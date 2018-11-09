#pragma once
#include "Canvas.h"

/// For the box
const int boxWidth = 50, boxHeight = 30;
const Imagine::Color boxColor = Imagine::WHITE;

/// For the cannon
const int cannonLength = 30, cannonWidth = 6;
const float cannonAngularVelocity = 0.32, cannonAngleLimit = M_PI*0.42, defaultCannonAngle = -M_PI/2;
const Imagine::Color cannonColor = Imagine::WHITE;

/// For shooting
const int shootFrequency = 0;

class Cannon{
private:
    float angle;
public:

    /**
     * @brief Creates a cannon object
     */
    Cannon();

    /**
     * @brief Display the cannon
     * @param newColor1 Color of the box (boxColor by default)
     * @param newColor2 Color of the cannon (cannonColor by default)
     */
    void display(Imagine::Color newColor1 = boxColor, Imagine::Color newColor2 = cannonColor) const;

    /**
     * @brief Update the position of the cannon
     * @param direction Belongs in {-1,0,1} and indicates which key is pressed if any to change the position of the cannon
     */
    void updatePosition(int direction);
};
