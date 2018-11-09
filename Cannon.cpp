#include "Cannon.h"

Cannon::Cannon() {
    angle = defaultCannonAngle;
}

void Cannon::display(Imagine::Color newColor1, Imagine::Color newColor2) const{
    Imagine::fillRect(windowWidth/2 - boxWidth/2, windowHeight - groundHeight - boxHeight, boxWidth, boxHeight, newColor1);
    Imagine::drawLine(windowWidth/2, windowHeight - groundHeight - boxHeight, windowWidth/2 + cannonLength * std::cos(angle),
                      windowHeight - groundHeight - boxHeight + cannonLength * std::sin(angle), newColor2, cannonWidth);
}

void Cannon::updatePosition(int direction){
    display(windowBackgroundColor, windowBackgroundColor);
    if (direction == -1){
        angle -= cannonAngularVelocity;
    }
    else if (direction == 1){
        angle += cannonAngularVelocity;
    }

    if (angle < defaultCannonAngle-cannonAngleLimit){
        angle = defaultCannonAngle-cannonAngleLimit;
    }
    else if (angle > defaultCannonAngle+cannonAngleLimit){
        angle = defaultCannonAngle+cannonAngleLimit;
    }
    display();
}
