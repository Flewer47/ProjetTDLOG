#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>
#include <Imagine/Graphics.h>

/// For the canvas
const int windowWidth = 600, windowHeight = 600, groundHeight = 20;
const Imagine::Color windowBackgroundColor = Imagine::BLACK;
const std::string windowTitle = "Paratroopers";

/// Drop Troopers
const int dropMargin = 0, leftRightPlaneHeight = 0, rightLeftPlaneHeight = 0, shieldMargin = 0;

class Canvas
{
    // Check if the canvas is active or not.
    bool activeCanvas;

public:

    // Creates a canvas
    Canvas();

    // endGraphics for the canvas
    void closeCanvas() const;
};

#endif // CANVAS_H
