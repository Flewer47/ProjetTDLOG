#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>
#include <Imagine/Graphics.h>

/// For the canvas
const int windowWidth = 600, windowHeight = 600, groundHeight = 20;
const Imagine::Color windowBackgroundColor = Imagine::BLACK;
const Imagine::Color groundColor = Imagine::BLUE;
const std::string windowTitle = "Paratroopers";

/// Drop Troopers
const int dropMargin = 0, leftRightPlaneHeight = 0, rightLeftPlaneHeight = 0, shieldMargin = 0, minHeightParachute = 0, maxHeightParachute = 0;

class Canvas
{
    // Check if the canvas is active or not.
    bool isCanvasActive;

public:

    /**
     * @brief Creates a canvas
     */
    Canvas();

    /**
     * @brief Is the canvas is active, puts a "endGraphics" so the player can exit the game
     */
    void closeCanvas() const;
};

#endif // CANVAS_H
