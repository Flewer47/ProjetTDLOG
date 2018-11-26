#ifndef PLANE_H
#define PLANE_H
#include "../Cannon/Cannon.h"
#include "../Bullet/Bullet.h"

const int dropMargin = 20;
const int leftRightPlaneHeight = 20;
const int rightLeftPlaneHeight = 70;
const int shieldMargin = boxWidth + 40;
const int planeVelocity = 3;
const Imagine::Color planeColor = Imagine::RED;


class Plane
{
    int x;
    int y;
    int vx;
    bool isGoingRight;

    // Check to see if it has left the screen (for memory management purpose)
    bool removeMe;

    // Determine if it has spawned an enemy yet
    bool hasSpawnedYet;

    // Determine if is has to spawn an enemy
    bool isSpawningTrooper;

    // Determine where to drop the enemy
    int dropWidth;

    //Determine if the plane was shot by a bullet
    bool planeShot;


public:
    Plane();

    void display(Imagine::Color newColor = planeColor) const;

    void updatePosition();

    /**
     * @brief Getter of the HasSpawnedYet boolean
     */
    bool getIsSpawningTrooper() const;

    /**
     * @brief Getter of the x coordinate
     */
    int getPlaneX() const;

    /**
     * @brief Getter of the y coordinate
     */
    int getPlaneY() const;

    /**
     * @brief Getter of the removeMe boolean
     */
    bool getRemoveMe() const;

    /**
     * @brief Checks if a bullet collides the plane's hitbox
     * @param bullet Bullet
     */
    void Touched(Bullet bullet);

    /**
      * @brief Checks if the plane was shot
      */
    bool isTouched();

};

#endif // PLANE_H
