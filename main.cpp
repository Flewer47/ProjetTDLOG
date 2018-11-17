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

void handlePlanes(){
    for (std::vector<Plane>::iterator it = planes.begin(); it != planes.end(); it++){
        (*it).updatePosition();
        if ((*it).getIsSpawningTrooper()){
            troopers.push_back(Trooper((*it).getPlaneX(), (*it).getPlaneY()));
        }
    }

    for (std::vector<Plane>::iterator it = planes.end()-1; it != planes.begin()-1; it--){
        if ((*it).getRemoveMe()){
            planes.erase(it);
        }
    }
}

void handleTroopers(){
    for (std::vector<Trooper>::iterator it = troopers.begin(); it != troopers.end(); ++it){
        (*it).updatePosition();
    }

    for (std::vector<Trooper>::iterator it = troopers.end()-1; it != troopers.begin()-1; --it){
        if ((*it).getRemoveMe()){
            troopers.erase(it);
        }
    }
}

void handleHitboxes(){
    for (std::vector<Bullet>::iterator it_bull = bullets.begin(); it_bull !=bullets.end(); it_bull++){
        for (std::vector<Trooper>::iterator it_troop = troopers.begin(); it_troop !=troopers.end(); it_troop++){
            if ((*it_troop).isTouched((*it_bull))){
                (*it_bull).display(Imagine::BLACK);
                bullets.erase(it_bull);
                (*it_troop).display(Imagine::BLACK, Imagine::BLACK);
                troopers.erase(it_troop);
                std::cout << "Trooper touched !" << std::endl;
            }
        }
        for (std::vector<Plane>::iterator it_plane = planes.begin(); it_plane !=planes.end(); it_plane++){
            if ((*it_plane).isTouched((*it_bull))){
                (*it_bull).display(Imagine::BLACK);
                bullets.erase(it_bull);
                (*it_plane).display(Imagine::BLACK);
                planes.erase(it_plane);
                std::cout << "Plane touched !" << std::endl;
            }
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
    while (countdown != 300){

        if (countdown % 10 == 0){
            planes.push_back(Plane());
        }

        countdown++;
        handleCannon(direction, count, cannon, bullets);
        handlePlanes();
        handleBullets();
        handleTroopers();
        handleHitboxes();

        Imagine::drawString(20,50, patch::to_string(bullets.size()), Imagine::RED);
        Imagine::drawString(20,100, patch::to_string(planes.size()), Imagine::RED);
        Imagine::drawString(20,150, patch::to_string(troopers.size()), Imagine::RED);

        Imagine::milliSleep(50);

        Imagine::drawString(20,50, patch::to_string(bullets.size()), Imagine::BLACK);
        Imagine::drawString(20,100, patch::to_string(planes.size()), Imagine::BLACK);
        Imagine::drawString(20,150, patch::to_string(troopers.size()), Imagine::BLACK);
    }

    canvas.closeCanvas();

    return 0;
}
