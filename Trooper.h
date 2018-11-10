#ifndef TROOPER_H
#define TROOPER_H

#include "Canvas.h"

/// For the trooper
const int trooperWidth = 20;
const int trooperHeight = 20;
const Imagine::Color trooperColor = Imagine::BLUE;

/// For the parachute
const int parachuteWidth = 5;
const int parachuteHeight = 5;
const Imagine::Color parachuteColor = Imagine::GREEN;

/// Speeds
const int trooperSpeedWithParachute = 3;
const int trooperSpeedWithoutParachute = 5;

class Trooper
{
    // Position
    int x;
    int y;

    // Speed
    int v;

    // Check if he has deployed its parachute
    bool isParachuteDrawn;

    // Height when he will deploy its parachute
    int heightToDrawParachute;

    // Check if he has touched the ground
    bool isWalking;

    // Check if he has been killed (for memory management purpose)
    bool removeMe;

public:
    /**
     * @brief Creates a trooper
     * @param planeX X coordinate of the plane that spawned the trooper
     * @param planeY Y coordinate of the plane that spawned the trooper
     */
    Trooper(int planeX, int planeY);

};

#endif // TROOPER_H
