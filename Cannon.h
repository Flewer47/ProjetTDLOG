#pragma once
#include <Imagine/Graphics.h>

const int windowWidth = 600, windowHeight = 600;
const Imagine::Color windowBackgroundColor = Imagine::WHITE;
const int groundHeight = 20;
const float cannonAngleLimit = M_PI*0.42, defaultCannonAngle = -M_PI/2;

class Cannon {
private:
    int boxHeight;
    int boxWidth;
    int length;
    int width;
    float angle;
    float angularVelocity;
    Imagine::Color boxColor;
    Imagine::Color cannonColor;

public:

    Cannon(int newBoxWidth, int newBoxHeight, int newLength, int newWidth, float newAngle = defaultCannonAngle,
           float newAngularVelocity = 0.32, Imagine::Color newBoxColor = Imagine::BLACK, Imagine::Color newCannonColor = Imagine::BLACK);

    void display(Imagine::Color BoxColor, Imagine::Color CannonColor);
    void updatePosition(int direction);
};
