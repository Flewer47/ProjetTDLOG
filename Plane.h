#ifndef PLANE_H
#define PLANE_H
#include "Cannon.h"

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


public:
    Plane();

    void display(Imagine::Color newColor = planeColor) const;

    void updatePosition();

    /**
     * @brief Getter of the HasSpawnedYet boolean
     */
    bool getisSpawningTrooper() const;
};

#endif // PLANE_H
