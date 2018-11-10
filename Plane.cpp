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

    if (!hasSpawnedYet && ((isGoingRight && x >= dropWidth) || (!isGoingRight && x <= dropWidth))){ // need to drop a Trooper
        hasSpawnedYet = true;
    }
    else if ((isGoingRight && x >= windowWidth) || (!isGoingRight && x <= - planeWidth)){
        removeMe = true;
    }

    display();
}
