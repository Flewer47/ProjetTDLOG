#include "Plane.h"

Plane::Plane(){
    // Going left to right
    if ((rand()/(float)RAND_MAX) < 0.5){
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
    dropWidth = dropMargin + (rand()/(float)RAND_MAX)*(windowWidth - 2*(shieldMargin/2 + dropMargin));
    if (dropWidth >= (windowWidth - shieldMargin)/2){
        dropWidth += shieldMargin;
    }
    planeShot = false;
}


void Plane::display(Imagine::Color newColor) const{
    // To draw faster


    Imagine::Image<Imagine::AlphaColor> rightHelicopter;
    load(rightHelicopter, srcPath("rightHelicopter.png"));

    Imagine::Image<Imagine::AlphaColor> leftHelicopter;
    load(leftHelicopter, srcPath("leftHelicopter.png"));

    Imagine::fillRect(x-vx,y,rightHelicopter.width(), rightHelicopter.height(), Imagine::BLACK);

    // Plane
    if (isGoingRight){
        Imagine::display(rightHelicopter, x, y);
    }
    else {
        Imagine::display(leftHelicopter, x, y);
    }

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

int Plane::getPlaneX() const{
    return x;
}

int Plane::getPlaneY() const{
    return y;
}

bool Plane::getRemoveMe() const{
    return removeMe;
}

void Plane::Touched(Bullet bullet){
    bool touch = ((x < bullet.get_x())
                  && (bullet.get_x()< x + planeWidth)
                  && (y < bullet.get_y())
                  && (bullet.get_y() < y + planeHeight));
    if (touch){
        planeShot = true;
        display(windowBackgroundColor);
        bullet.setRemoveMe(true);
        removeMe=true;
    }
}

bool Plane::isTouched(){
    return (planeShot);
}
