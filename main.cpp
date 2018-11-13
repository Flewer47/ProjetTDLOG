#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Cannon.h"
#include "Bullet.h"
#include "Plane.h"
#include "Trooper.h"
#include <Imagine/Graphics.h>

/// Vector of bullets
std::vector<Bullet> bullets;

/// Vector of planes
std::vector<Plane> planes;

/// Vector of troopers
std::vector<Trooper> troopers;

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
            case Imagine::KEY_UP :
                up = push;
                break;
            }
        }
    } while (e.type!=Imagine::EVT_NONE);
    direction = (up ? 2 : (left ? -1 : (right ? 1 : 0)));
}


void handleBullets(){
    for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it){
        (*it).updatePosition();
    }

    for (std::vector<Bullet>::iterator it = bullets.end()-1; it != bullets.begin()-1; --it){
        if ((*it).getRemoveMe()){
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
    while (countdown != 300){
        countdown++;
        handleCannon(direction, count, cannon, bullets);
        handleBullets();
        Imagine::drawString(20,50, std::to_string(bullets.size()), Imagine::RED);
        Imagine::milliSleep(50);
        Imagine::drawString(20,50, std::to_string(bullets.size()), Imagine::BLACK);
    }

    canvas.closeCanvas();

    return 0;
}
