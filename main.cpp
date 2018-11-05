#include <iostream>
#include <Imagine/Graphics.h>

// Ceci est un test git : cf Louis

/// For the canvas
int const width = 600, height = 600;
std::string const windowTitle = "Paratroopers";

/// For the player
int const playerWidth = 50, playerHeight = 30;
Imagine::Color playerColor = Imagine::BLACK;

/// For the cannon
float const cannonLength = 30, defaultCannonAngle = -M_PI/2, cannonAngleLimit = M_PI/4, cannonAngularVelocity = 0.1;
const int cannonWidth = 6;
Imagine::Color cannonColor = Imagine::BLACK;


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

    Imagine::openWindow(width, height, windowTitle);

    Imagine::IntPoint2 player(width/2 - playerWidth/2, height - playerHeight);
    Imagine::IntPoint2 cannon(width/2, height - playerHeight);

    Imagine::fillRect(player, playerWidth, playerHeight, playerColor);

    float cannonAngle = defaultCannonAngle;
    int countdown = 0;
    int direction = 0;
    while (countdown != 100){
        countdown++;
        Imagine::drawLine(cannon, cannon + Imagine::IntPoint2(cannonLength*std::cos(cannonAngle), cannonLength*std::sin(cannonAngle)), cannonColor, cannonWidth);
        Imagine::milliSleep(50);
        Imagine::drawLine(cannon, cannon + Imagine::IntPoint2(cannonLength*std::cos(cannonAngle), cannonLength*std::sin(cannonAngle)), Imagine::WHITE, cannonWidth);
        Imagine::fillRect(player, playerWidth, playerHeight, playerColor);
        keyboard(direction);
        if (direction == 1){
            cannonAngle += cannonAngularVelocity;
        }
        else if (direction == -1){
            cannonAngle -= cannonAngularVelocity;
        }

        if (cannonAngle < defaultCannonAngle-cannonAngleLimit){
            cannonAngle = defaultCannonAngle-cannonAngleLimit;
        }
        else if (cannonAngle > defaultCannonAngle+cannonAngleLimit){
            cannonAngle = defaultCannonAngle+cannonAngleLimit;
        }
    }



    Imagine::endGraphics();



    return 0;
}
