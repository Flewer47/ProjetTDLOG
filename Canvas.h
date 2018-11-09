#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>
#include <Imagine/Graphics.h>

class Canvas
{
    /// Window
    int width;
    int height;
    std::string title;
    Imagine::Color backgroundColor;
    bool activeCanvas;

    /// Drop Troopers
    int dropMargin;
    int leftRightPlaneHeight;
    int rightLeftPlaneHeight;
    int shieldMargin;

    /// Deploy Parachute
    int maxHeigthParachute;
    int minHeightParachute;

    /// Score
    int groundHeight;

public:
    Canvas(int newWidth, int newHeight, std::string newTitle, Imagine::Color newBackgroundColor, int newDropMargin, int newLeftRightPlaneHeight,
           int newRightLeftPlaneHeight, int newShieldMargin, int newMaxHeightParachute, int newMinHeightParachute, int newGroundHeight);

    void closeCanvas();
};

#endif // CANVAS_H
