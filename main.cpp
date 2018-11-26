#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Cannon.h"
#include "Bullet.h"
#include "Plane.h"
#include "Trooper.h"
#include <Imagine/Graphics.h>
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}


/// Vector of bullets
std::vector<Bullet> bullets;

/// Vector of planes
std::vector<Plane> planes;

/// Vector of troopers
std::vector<Trooper> troopers;


//values of the score points for each shot

const int points_body_touched = 5;
const int points_parachute_touched = 3;
const int points_bullet_used = -1;
const int points_plane_touched = 10;

/**
 * @brief keyboard management function for the cannon and the shooting
 * @param direction -1 if it goes to the left, 1 if it goes to the right, 2 if the user shoots, 0 otherwise.
 */
void keyboard(int& direction){
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
    } while (e.type!=Imagine::EVT_NONE);
    direction = (up ? 2 : (left ? -1 : (right ? 1 : 0)));
}


void handleBullets(int & player_score){
    for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it){
        (*it).updatePosition();
    }

    for (std::vector<Bullet>::iterator it = bullets.end()-1; it != bullets.begin()-1; --it){
        if ((*it).getRemoveMe()){
            player_score = player_score + points_bullet_used;
            bullets.erase(it);
        }
    }
}

void moveCannon(const int& direction, int &count, Cannon &cannon){
    cannon.updatePosition(direction);
    count = shootFrequency;
}

void shoot(int &count, const Cannon& cannon, std::vector<Bullet> &bullets)
{
    if (count == shootFrequency || count == 0){
        bullets.push_back(Bullet(cannon.getAngle()));
        if(count == 0){
            count = shootFrequency;
        }
    }
    count--;
}


void handleCannon(int& direction, int& count, Cannon &cannon, std::vector<Bullet> &bullets){
    keyboard(direction);
    if (direction != 2){
        moveCannon(direction, count, cannon);
    }
    else{
        shoot(count, cannon, bullets);
    }
}

void handlePlanes(int & player_score){
    for (std::vector<Plane>::iterator it = planes.end()-1; it != planes.begin()-1; it--){
            if ((*it).getRemoveMe()){
                if((*it).isTouched()){
                    player_score = player_score + points_plane_touched;
                }
                planes.erase(it);
            }
        }

    for (std::vector<Plane>::iterator it = planes.begin(); it != planes.end(); it++){
        (*it).updatePosition();
        if ((*it).getIsSpawningTrooper()){
            troopers.push_back(Trooper((*it).getPlaneX(), (*it).getPlaneY()));
        }
    }
}

void handleTroopers(int & player_lives, int & player_score){
    for (std::vector<Trooper>::iterator it = troopers.end()-1; it != troopers.begin()-1; --it){
        if ((*it).getRemoveMe()){
            if((*it).hascameinBase()){
                player_lives -= 1;
            }
            else if((*it).isbodyTouched()){
                player_score = player_score + points_body_touched;
            }
            else if((*it).isparachuteTouched()){
                player_score = player_score + points_parachute_touched;
            }
            troopers.erase(it);
        }
    }

    for (std::vector<Trooper>::iterator it = troopers.begin(); it != troopers.end(); ++it){
        (*it).updatePosition();
    }
}

void handleHitboxes(){
    for (std::vector<Bullet>::iterator it_bull = bullets.begin(); it_bull !=bullets.end(); it_bull++){
        for (std::vector<Trooper>::iterator it_troop = troopers.begin(); it_troop !=troopers.end(); it_troop++){
            (*it_troop).Touched((*it_bull));
        }
        for (std::vector<Plane>::iterator it_plane = planes.begin(); it_plane !=planes.end(); it_plane++){
            (*it_plane).Touched((*it_bull));
        }
    }
}

void generateRandom(){
    srand(time(0));
}

int main(){

    generateRandom();
    std::cout << "Hello World !" << std::endl;

    Canvas canvas;
    Cannon cannon;

    int countdown = 0;
    int direction = 0;
    int count = shootFrequency;
    int player_lives = 10;
    int player_score = 0;
    while (player_lives != 0){
        Imagine::noRefreshBegin();

        if (countdown % 30 == 0){
            planes.push_back(Plane());
        }

        countdown++;
        handleCannon(direction, count, cannon, bullets);
        handlePlanes(player_score);
        handleBullets(player_score);
        handleTroopers(player_lives, player_score);
        handleHitboxes();

        Imagine::drawString(20,50, patch::to_string(bullets.size()), Imagine::RED);
        Imagine::drawString(20,100, patch::to_string(planes.size()), Imagine::RED);
        Imagine::drawString(20,150, patch::to_string(troopers.size()), Imagine::RED);
        Imagine::drawString(20,20, patch::to_string(player_lives), Imagine::GREEN);
        Imagine::drawString(550,20, patch::to_string(player_score), Imagine::BLUE);



        Imagine::milliSleep(50);

        Imagine::drawString(20,50, patch::to_string(bullets.size()), Imagine::BLACK);
        Imagine::drawString(20,100, patch::to_string(planes.size()), Imagine::BLACK);
        Imagine::drawString(20,150, patch::to_string(troopers.size()), Imagine::BLACK);
        Imagine::drawString(20,20, patch::to_string(player_lives), Imagine::BLACK);
        Imagine::drawString(550,20, patch::to_string(player_score), Imagine::BLACK);
        Imagine::noRefreshEnd();
    }

    canvas.closeCanvas();

    return 0;
}
