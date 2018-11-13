#include "Plane.h"

Plane::Plane()
{
    // Going left to right
    if (rand() < 0.5){
        vx = planeVelocity;
        x = -planeWidth;
        y = leftRightPlaneHeight;
        isGoingRight = true;
    }
    else {
        vx = -planeVelocity;
        x = windowWidth;
        y = rightLeftPlaneHeight;
        isGoingRight = false;
    }

    hasSpawnedYet = false;
    isSpawningTrooper = false;
    removeMe = false;
    dropWidth = dropMargin + rand()*(windowWidth - 2*(shieldMargin/2 + dropMargin));
    if (dropWidth >= (windowWidth - shieldMargin)/2){
        dropWidth += shieldMargin;
    }
}

void Plane::display(Imagine::Color newColor) const{
    // To draw faster
    Imagine::noRefreshBegin();

    // Plane
    Imagine::fillRect(x, y, planeWidth, planeHeight, newColor);

    Imagine::noRefreshEnd();
}

void Plane::updatePosition(){

    display(windowBackgroundColor);

    x += vx;

    // If we spawned a trooper the frame before, hasSpawnedYet would still be true in the next frame, and so we would spawn him again.
    // My solution : we get another boolean (spawnTrooper), that help to spawn the trooper correctly. We spawn a trooper in main.cpp
    // only if isSpawningTrooper is true (only the case for one frame)

    if (hasSpawnedYet && isSpawningTrooper){
        isSpawningTrooper = false;
    }

    if (!hasSpawnedYet && ((isGoingRight && x >= dropWidth) || (!isGoingRight && x <= dropWidth))){
        hasSpawnedYet = true;
        isSpawningTrooper = true;
    }
    else if ((isGoingRight && x >= windowWidth) || (!isGoingRight && x <= - planeWidth)){
        removeMe = true;
    }

    display();
}

bool Plane::getIsSpawningTrooper() const{
    return isSpawningTrooper;
}
