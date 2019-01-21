/// "Copyright 2019 BOUVIER-GATELLIER-GIRAUDON-SANTET"

#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>
#include "Canvas.h"
#include "Cannon.h"
#include "Bullet.h"
#include "Plane.h"
#include "Trooper.h"


namespace patch {
template < typename T > std::string to_string(const T& n ) {
    std::ostringstream stm;
    stm << n;
    return stm.str();
}
}


/// Vector of bullets
std::vector<Bullet> bullets;

/// Vector of planes
std::vector<Plane> planes;

/// Vector of troopers
std::vector<Trooper> troopers;

void resetVariables(int &score, int &player_lives,
std::vector<Bullet> &bullets, std::vector<Trooper> &troopers,
std::vector<Plane> &planes) {
    score = 0;
    player_lives = 7;
    bullets.clear();
    troopers.clear();
    planes.clear();
}

/**
 * @brief keyboard management function for the cannon and the shooting
 * @param direction -1 if it goes to the left, 1 if it goes to the right, 2 if the user shoots, 0 otherwise.
 */
void keyboard(int& direction) {
    static bool left = false, right = false, up = false;
    Imagine::Event e;
    do {
        Imagine::getEvent(0, e);
        if (e.type == Imagine::EVT_KEY_ON || e.type == Imagine::EVT_KEY_OFF) {
            bool push = (e.type == Imagine::EVT_KEY_ON);
            switch (e.key) {
            case Imagine::KEY_LEFT :
                left = push;
                break;
            case Imagine::KEY_RIGHT :
                right = push;
                break;
            case 'z' :
                up = push;
                break;
            }
        }
    } while (e.type != Imagine::EVT_NONE);
    direction = (up ? 2 : (left ? -1 : (right ? 1 : 0)));
}


void handleBullets(int & player_score) {
    for (std::vector<Bullet>::iterator it = bullets.begin();
it != bullets.end(); ++it) {
        (*it).updatePosition();
    }

    for (std::vector<Bullet>::iterator it = bullets.end()-1;
it != bullets.begin()-1; --it) {
        if ((*it).getRemoveMe()) {
            player_score = player_score + points_bullet_used;
            bullets.erase(it);
        }
    }
}

void moveCannon(const int& direction, int &count, Cannon &cannon) {
    cannon.updatePosition(direction);
    count = shootFrequency;
}

void shoot(int &count, const Cannon& cannon, std::vector<Bullet> &bullets) {
    if (count == shootFrequency || count == 0) {
        bullets.push_back(Bullet(cannon.getAngle()));
        if (count == 0) {
            count = shootFrequency;
        }
    }
    count--;
}


void handleCannon(int& direction, int& count, Cannon &cannon,
std::vector<Bullet> &bullets) {
    keyboard(direction);
    if (direction != 2) {
        moveCannon(direction, count, cannon);
    } else {
        shoot(count, cannon, bullets);
    }
}

void handlePlanes(int & player_score) {
    for (std::vector<Plane>::iterator it = planes.end()-1;
it != planes.begin()-1; it--) {
        if ((*it).getRemoveMe()) {
            if ((*it).isTouched()) {
                player_score = player_score + points_plane_touched;
            }
            planes.erase(it);
        }
    }

    for (std::vector<Plane>::iterator it = planes.begin();
it != planes.end(); it++) {
        (*it).updatePosition();
        if ((*it).getIsSpawningTrooper()) {
            troopers.push_back(Trooper((*it).getPlaneX(), (*it).getPlaneY()));
        }
    }
}

void handleTroopers(int & player_lives, int & player_score) {
    for (std::vector<Trooper>::iterator it = troopers.end()-1;
it != troopers.begin()-1; --it) {
        if ((*it).getRemoveMe()) {
            if ((*it).hascameinBase()) {
                player_lives -= 1;
            } else if ((*it).isbodyTouched()) {
                player_score = player_score + points_body_touched;
            } else if ((*it).isparachuteTouched()) {
                player_score = player_score + points_parachute_touched;
            }
            troopers.erase(it);
        }
    }

    for (std::vector<Trooper>::iterator it = troopers.begin();
it != troopers.end(); ++it) {
        (*it).updatePosition();
    }
}

void handleHitboxes() {
    for (std::vector<Bullet>::iterator it_bull = bullets.begin();
it_bull !=bullets.end(); it_bull++) {
        for (std::vector<Trooper>::iterator it_troop = troopers.begin();
it_troop !=troopers.end(); it_troop++) {
            (*it_troop).Touched((*it_bull));
        }
        for (std::vector<Plane>::iterator it_plane = planes.begin();
it_plane !=planes.end(); it_plane++) {
            (*it_plane).Touched((*it_bull));
        }
    }
}

void generateRandom() {
    srand(time(0));
}


void game() {
    generateRandom();

    Canvas canvas;
    Cannon cannon;

    // 0 : Start Menu / 1 : Game / 2 : Option / 3 : Quit
    int mode = 0;
    bool developper_mode = true;
    int countdown = 0;
    int direction = 0;
    int count = shootFrequency;
    int player_lives = 7;
    int player_score = 0;

    canvas.startMenu(mode);

    while ((0 <= mode) && (mode <= 3)) {
        if (mode == 0) {
            canvas.startMenu(mode);
        }

        if (mode == 1) {
            Imagine::fillRect(0, windowHeight-groundHeight,
windowWidth, groundHeight, groundColor);
            Imagine::drawString(150, 595, "Score :",
Imagine::WHITE, 12, 0, true);
            Imagine::drawString(650, 595, "Lives :",
Imagine::WHITE, 12, 0, true);



            while (player_lives != 0) {
                Imagine::noRefreshBegin();

                int letterSize = 12;

                if (countdown % 30 == 0) {
                    planes.push_back(Plane());
                }

                countdown++;
                handleCannon(direction, count, cannon, bullets);
                handlePlanes(player_score);
                handleBullets(player_score);
                handleTroopers(player_lives, player_score);
                handleHitboxes();


                if (developper_mode) {
                    Imagine::fillRect(700, 595-letterSize, 30,
15, Imagine::BLUE);
                    Imagine::drawString(700, 595,
patch::to_string(player_lives), Imagine::WHITE);
                }
                Imagine::fillRect(200, 595-letterSize, 30, 15, Imagine::BLUE);
                Imagine::drawString(200, 595,
patch::to_string(player_score), Imagine::WHITE);

                Imagine::noRefreshEnd();


                Imagine::milliSleep(20);
            }

            if (player_lives == 0) {
                canvas.gameOverScreen(mode, player_lives, player_score);
            }

            Imagine::fillRect(0, 0, windowWidth,
windowHeight, windowBackgroundColor);
        }

        if (mode == 3) {
            canvas.closeCanvas();
            break;
        }
    }
}
