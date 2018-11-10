#include "Cannon.h"

Cannon::Cannon() {
    angle = defaultCannonAngle;
}

void Cannon::display(Imagine::Color newColor1, Imagine::Color newColor2) const{
    // To draw faster
    Imagine::noRefreshBegin();

    // Box
    Imagine::fillRect(windowWidth/2 - boxWidth/2, windowHeight - groundHeight - boxHeight, boxWidth, boxHeight, newColor1);

    // Cannon
    Imagine::drawLine(windowWidth/2, windowHeight - groundHeight - boxHeight, windowWidth/2 + cannonLength * std::cos(angle),
                      windowHeight - groundHeight - boxHeight + cannonLength * std::sin(angle), newColor2, cannonWidth);

    Imagine::noRefreshEnd();
}

void Cannon::updatePosition(int direction){

    // Erases the current cannon
    display(windowBackgroundColor, windowBackgroundColor);

    // If moving to the left
    if (direction == -1){
        angle -= cannonAngularVelocity;
    }

    // If moving to the right
    else if (direction == 1){
        angle += cannonAngularVelocity;
    }

    // If you go too far left
    if (angle < defaultCannonAngle-cannonAngleLimit){
        angle = defaultCannonAngle-cannonAngleLimit;
    }

    // If you go too far right
    else if (angle > defaultCannonAngle+cannonAngleLimit){
        angle = defaultCannonAngle+cannonAngleLimit;
    }

    // Redraw the cannon
    display();
}

float Cannon::getAngle() const{
  return angle;
}
