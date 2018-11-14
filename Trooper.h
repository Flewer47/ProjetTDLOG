#ifndef TROOPER_H
#define TROOPER_H

#include "Cannon.h"

/// For the trooper
const int trooperWidth = 20;
const int trooperHeight = 20;
const Imagine::Color trooperColor = Imagine::RED;

/// For the parachute
const int parachuteWidth = 5;
const int parachuteHeight = 5;
const Imagine::Color parachuteColor = Imagine::RED;

/// Speeds
const int trooperSpeedWithParachute = 3;
const int trooperSpeedWithoutParachute = 5;
const int trooperSpeedWalking = 2;

/// Margins
const int minHeightParachute = 300, maxHeightParachute = 400;

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

    /**
     * @brief Display the trooper and its parachute if any
     * @param newColor1 Color of the trooper (trooperColor by default)
     * @param newColor2 Color of the parachute (parachuteColor by default)
     */
    void display(Imagine::Color newColor1 = trooperColor, Imagine::Color newColor2 = parachuteColor) const;

    /**
     * @brief Update the position of the trooper at the next frame
     */
    void updatePosition();

    /**
     * @brief Getter of removeMe boolean
     */
    bool getRemoveMe() const{
        return removeMe;
    }

};

#endif // TROOPER_H
