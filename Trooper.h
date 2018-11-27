#ifndef TROOPER_H
#define TROOPER_H

#include "Cannon.h"
#include "Bullet.h"

/// For the trooper
const int trooperWidth = 20;
const int trooperHeight = 20;
const Imagine::Color trooperColor = Imagine::RED;

/// For the parachute
const int parachuteWidth = 30;
const int parachuteHeight = 50;
const Imagine::Color parachuteColor = Imagine::RED;

/// Speeds
const int trooperSpeedWithParachute = 3;
const int trooperSpeedWithoutParachute = 5;
const int trooperSpeedWalking = 2;

/// Margins
const int minHeightParachute = 300, maxHeightParachute = 400;

/// Images
const int skullTimeOfDisplay = 250;

class Trooper
{
    // Position
    int x;
    int y;

    // Speed
    int v;

    // Check if he has deployed its parachute
    bool isParachuteDrawn;

    //Check if parachute has been shot
    bool isParachuteShot;

    // Time remaining of display of the skull, -1 if skull not displayed
    int countDisplaySkull;

    // Height when he will deploy its parachute
    int heightToDrawParachute;

    // Check if he has touched the ground
    bool isWalking;

    // Check if he has been killed (for memory management purpose)
    bool removeMe;

    //Check if the trooper managed to enter the base
    bool cameinBase;

    //Check if the body was touched
    bool bodyTouched;

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

    /**
     * @brief Checks if a bullet collides the trooper's hitbox
     * @param bullet Bullet
     */
    void Touched(Bullet bullet);

    /**
     * @brief Checks if trooper has a parachute
     */
    bool hasParachute();

    /**
     * @brief Checks if trooper managed to come into the base
     */

    bool hascameinBase();

    /**
     * @brief Checks if the parachute was touched
     */

    bool isparachuteTouched();

    /**
     * @brief Checks if the body of the trooper was touched
     */

    bool isbodyTouched();
};

#endif // TROOPER_H
