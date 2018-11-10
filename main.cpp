#include <iostream>
#include "Cannon.h"
#include "Bullet.h"
#include <Imagine/Graphics.h>


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

int main(){
    std::cout << "Hello World !" << std::endl;

    Canvas canvas;

    Cannon cannon;

    std::vector<Bullet> bullets;

    int countdown = 0;
    int direction = 0;
    while (countdown != 100){
        countdown++;
        keyboard(direction);
        if (direction!=2){
            cannon.updatePosition(direction);
        }
        else{
            bullets.push_back(Bullet(cannon.getAngle()));
        }
        for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it){
            (*it).updatePosition();
        }
        Imagine::milliSleep(50);
    }

    canvas.closeCanvas();

    return 0;
}
