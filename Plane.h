#ifndef PLANE_H
#define PLANE_H
#include "Cannon.h"

const int dropMargin = 20;
const int leftRightPlaneHeight = 20;
const int rightLeftPlaneHeight = 70;
const int shieldMargin = boxWidth + 40;
const int planeVelocity = 3;
const Imagine::Color planeColor = Imagine::RED;

const int planeWidth = 10;
const int planeHeight = 10;

class Plane
{
    int x;
    int y;
    int vx;
    bool isGoingRight;

    // Check to see if it has left the screen (for memory management purpose)
    bool removeMe;

    // Determine if he has spawned an enemy yet
    bool hasSpawnedYet;

    // Determine where to drop the enemy
    int dropWidth;


public:
    Plane();

    void display(Imagine::Color newColor = planeColor) const;

    void updatePosition();
};

#endif // PLANE_H
