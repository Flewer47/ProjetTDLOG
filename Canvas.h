#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>
#include "Constants.h"

class Canvas
{
    Imagine::Window window;

public:

    /**
     * @brief Creates a canvas
     */
    Canvas();

    /**
     * @brief Is the canvas is active, puts a "endGraphics" so the player can exit the game
     */
    void closeCanvas() const;

    /**
      * @brief Opens the start menu
      * @param mode Defines the action from start menu
      */
    void startMenu(int& mode);

    /**
      * @brief Opens the Game Over pop-up
      * @param mode Defines the action from start menu
      * @param player_lives Number of lives
      * @param score Score
      */
    void gameOverScreen(int& mode, int&player_lives, int score);
};

bool isInRect(Imagine::IntPoint2 pos, Imagine::IntPoint2 size, Imagine::IntPoint2 pt);

#endif // CANVAS_H
