#include <iostream>
#include "Cannon.h"
#include <Imagine/Graphics.h>


/**
 * @brief keyboard management function for the cannon
 * @param direction -1 if it goes to the left, 1 if it goes to the right, 0 otherwise.
 */
void keyboard(int& direction){
    static bool left = false, right = false;
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
            }
        }
    } while (e.type!=Imagine::EVT_NONE);
    direction = (left ? -1 : (right ? 1 : 0));
}


int main(){
    std::cout << "Hello World !" << std::endl;

    Canvas canvas;

    Cannon cannon;

    int countdown = 0;
    int direction = 0;
    while (countdown != 100){
        countdown++;
        keyboard(direction);
        cannon.updatePosition(direction);
        Imagine::milliSleep(50);
    }

    canvas.closeCanvas();

    return 0;
}
