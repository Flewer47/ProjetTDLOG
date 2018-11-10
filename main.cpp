#include <iostream>
#include "Cannon.h"
#include "Bullet.h"
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

void spacebar(int& shoot){
  static bool space = false;
  Imagine::Event e;
  do {
      Imagine::getEvent(0, e);
      if (e.type == Imagine::EVT_KEY_ON || e.type == Imagine::EVT_KEY_OFF) {
          bool push = (e.type == Imagine::EVT_KEY_ON);
          std::cout << "ah" << std::endl;
          if(e.key == Imagine::KEY_UP){
            space = push;
            break;
          }
      }
  } while (e.type!=Imagine::EVT_NONE);
  shoot = (space ? 1 : 0);
}


int main(){
    std::cout << "Hello World !" << std::endl;

    Canvas canvas;

    Cannon cannon;

    std::vector<Bullet> bullets;

    int countdown = 0;
    int direction = 0;
    int shoot = 0;
    while (countdown != 100){
        countdown++;
        keyboard(direction);
        cannon.updatePosition(direction);
        spacebar(shoot);
        std::cout << direction << std::endl;
        if (shoot){
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
