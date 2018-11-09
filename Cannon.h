#pragma once
#include "Canvas.h"

/// For the box
const int boxWidth = 50, boxHeight = 30;
const Imagine::Color boxColor = Imagine::WHITE;

/// For the cannon
const float cannonLength = 30, cannonAngularVelocity = 0.32;
const int cannonWidth = 6;
const Imagine::Color cannonColor = Imagine::WHITE;
const float cannonAngleLimit = M_PI*0.42, defaultCannonAngle = -M_PI/2;

/// For shooting
const int shootFrequency = 0;

class Cannon{
private:
    float angle;
public:

    Cannon();

    void display(Imagine::Color newColor1 = boxColor, Imagine::Color newColor2 = cannonColor) const;
    void updatePosition(int direction);
};
