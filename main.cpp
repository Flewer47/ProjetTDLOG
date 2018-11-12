#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Cannon.h"
#include "Bullet.h"
#include <Imagine/Graphics.h>

/// Vector of bullets
std::vector<Bullet> bullets;


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

void setCue(std::vector<int> &cue){
    cue.clear();
    for(int i = 0; i < shootFrequency - 1; i++){
        cue.push_back(0);
    }
    cue.push_back(1);
}

void moveCannon(Cannon &cannon, std::vector<int> &cue, int direction){
    cannon.updatePosition(direction);
    setCue(cue);
}

void shoot(std::vector<int> &cue, std::vector<Bullet> &bullets, Cannon cannon)
{
    if (cue.back() == 1 || cue.empty()){
        bullets.push_back(Bullet(cannon.getAngle()));
        if(cue.empty()){
            setCue(cue);
        }
    }
    cue.pop_back();
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
    std::vector<int> bulletsCue;
    setCue(bulletsCue);

    while (countdown != 300){
        countdown++;
        keyboard(direction);
        if (direction!=2){
            moveCannon(cannon, bulletsCue, direction);
        }
        else{
            shoot(bulletsCue, bullets, cannon);
        }
        handleBullets();
        std::cout << bullets.size() << std::endl;
        Imagine::milliSleep(50);
    }

    canvas.closeCanvas();

    return 0;
}
