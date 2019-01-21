/// "Copyright 2019 BOUVIER-GATELLIER-GIRAUDON-SANTET"

#include "./Cannon.h"

Cannon::Cannon() {
    angle = defaultCannonAngle;
}

void Cannon::display(Imagine::Color newColor1,
Imagine::Color newColor2) const {
    // Box
    Imagine::fillRect(windowWidth/2 - boxWidth/2,
windowHeight - groundHeight - boxHeight, boxWidth,
boxHeight, newColor1);

    // Cannon
    Imagine::drawLine(windowWidth/2, windowHeight -
groundHeight - boxHeight, windowWidth/2 +
cannonLength * std::cos(angle),
windowHeight - groundHeight - boxHeight +
cannonLength * std::sin(angle), newColor2, cannonWidth);
}

void Cannon::updatePosition(int direction) {
    // Erases the current cannon
    display(windowBackgroundColor, windowBackgroundColor);

    // If moving to the left (-1) or to the right (+1)
    if (direction == -1) {
        angle -= cannonAngularVelocity;
    } else if (direction == 1) {
        angle += cannonAngularVelocity;
    }

    // If you go too far left (<) or if you go too far right (>)
    if (angle < defaultCannonAngle-cannonAngleLimit) {
        angle = defaultCannonAngle-cannonAngleLimit;
    } else if (angle > defaultCannonAngle+cannonAngleLimit) {
        angle = defaultCannonAngle+cannonAngleLimit;
    }

    // Redraw the cannon
    display();
}

float Cannon::getAngle() const {
  return angle;
}
