#include "Cannon.h"

Cannon::Cannon(int newBoxWidth, int newBoxHeight, int newLength, int newWidth, float newAngle, float newAngularVelocity,
               Imagine::Color newBoxColor, Imagine::Color newCannonColor){
    boxWidth = newBoxWidth;
    boxHeight = newBoxHeight;
    length = newLength;
    width = newWidth;
    angle = newAngle;
    angularVelocity = newAngularVelocity;
    boxColor = newBoxColor;
    cannonColor = newCannonColor;
}

void Cannon::display(Imagine::Color BoxColor, Imagine::Color CannonColor){
    Imagine::fillRect(windowWidth/2 - boxWidth/2, windowHeight - groundHeight - boxHeight, boxWidth, boxHeight, BoxColor);
    Imagine::drawLine(windowWidth/2, windowHeight - groundHeight - boxHeight, windowWidth/2 + length * std::cos(angle),
                      windowHeight - groundHeight - boxHeight + length * std::sin(angle), CannonColor, width);
}

void Cannon::updatePosition(int direction){
    display(windowBackgroundColor, windowBackgroundColor);
    if (direction == -1){
        angle -= angularVelocity;
    }
    else if (direction == 1){
        angle += angularVelocity;
    }

    if (angle < defaultCannonAngle-cannonAngleLimit){
        angle = defaultCannonAngle-cannonAngleLimit;
    }
    else if (angle > defaultCannonAngle+cannonAngleLimit){
        angle = defaultCannonAngle+cannonAngleLimit;
    }

    display(boxColor, cannonColor);
}
