/// "Copyright 2019 BOUVIER-GATELLIER-GIRAUDON-SANTET"

#include "./Plane.h"
#include "./Bullet.h"

Plane::Plane() {
    // Going left to right
    if ((rand()/static_cast<float>(RAND_MAX) < 0.5)) {
        vx = planeVelocity;
        x = -planeWidth;//initial coordinates
        y = leftRightPlaneHeight;
        isGoingRight = true;
    } else {
        vx = -planeVelocity;
        x = windowWidth;
        y = rightLeftPlaneHeight;
        isGoingRight = false;
    }
    hasSpawnedYet = false;//for the trooper
    isSpawningTrooper = false;//please read the part about spawning issues in our report to have precisions
    removeMe = false;//for the destructor
    dropWidth = dropMargin + (rand()/static_cast<float>(RAND_MAX))*
(windowWidth - 2*(shieldMargin/2 + dropMargin));//uniform distribution : we consider an interval
    if (dropWidth >= (windowWidth - shieldMargin)/2) {
        dropWidth += shieldMargin;//if the point in the previous interval corresponds to a point after the shield margin
    }
    planeShot = false;//if shot by the cannon
}


void Plane::display(Imagine::Color newColor) const {
    Imagine::Image<Imagine::AlphaColor> rightHelicopter;
    load(rightHelicopter, srcPath("Images/rightHelicopter.png"));

    Imagine::Image<Imagine::AlphaColor> leftHelicopter;
    load(leftHelicopter, srcPath("Images/leftHelicopter.png"));
    Imagine::fillRect(x-vx, y, rightHelicopter.width(),
rightHelicopter.height(), Imagine::BLACK);//to erase the former position

    // Plane
    if (isGoingRight) {//we display the adequate picture depending on the direction
        Imagine::display(rightHelicopter, x, y);
    } else {
        Imagine::display(leftHelicopter, x, y);
    }

    if (planeShot) Imagine::fillRect(x, y, rightHelicopter.width(),
rightHelicopter.height(), Imagine::BLACK);//if the plane is shot we erase it
}

void Plane::updatePosition() {
    display(windowBackgroundColor);

    x += vx;

    // If we spawned a trooper the frame before, hasSpawnedYet would
    // still be true in the next frame, and so we would spawn him again.
    // Our solution : we get another boolean (spawnTrooper), that help to
    // spawn the trooper correctly. We spawn a trooper in main.cpp
    // only if isSpawningTrooper is true (only the case for one frame)

    if (hasSpawnedYet && isSpawningTrooper) {
        isSpawningTrooper = false;
    }

    if (!hasSpawnedYet && ((isGoingRight && x >= dropWidth) ||
(!isGoingRight && x <= dropWidth))) {
        hasSpawnedYet = true;
        isSpawningTrooper = true;
    } else if ((isGoingRight && x >= windowWidth) ||
(!isGoingRight && x <= - planeWidth)) {
        removeMe = true;//we will use the destructor if the plane goes out of the screen
    }

    display();
}

bool Plane::getIsSpawningTrooper() const {
    return isSpawningTrooper;
}

int Plane::getPlaneX() const {
    return x;
}

int Plane::getPlaneY() const {
    return y;
}

bool Plane::getRemoveMe() const {
    return removeMe;
}

void Plane::updateIfTouched(Bullet bullet) {// we manage collisions with bullets in order to use the destructor then
    bool touch = ball_in_rectangle(bullet.get_x(), bullet.get_y(), x,
x+ planeWidth, y, y + planeHeight);
    if (touch) {
        planeShot = true;
        display(windowBackgroundColor);
        bullet.setRemoveMe(true);
        removeMe = true;
    }
}

bool Plane::isTouched() {
    return (planeShot);
}

int Plane::get_dropwidth() {
    return(dropWidth);
}

bool test_drop_width(int n) {//we test wether the abscisse of the spawning point can be accepted regarding the margins
    for (int i = 0; i < n; i++) {
        Plane plane_test;
        if (!(((plane_test.get_dropwidth() >= dropMargin)
              && (plane_test.get_dropwidth() <= windowWidth/2 -
shieldMargin/2))
             || ((plane_test.get_dropwidth() >= windowWidth/2 +
shieldMargin/2)
                && (plane_test.get_dropwidth() <= windowWidth -
dropMargin)))) {
            return(false);
        }
    }
    return(true);
}

bool ball_in_rectangle(int ball_x, int ball_y, int x1, int x2,
int y1, int y2) {
    bool inretangle = ((x1 < ball_x)
                  && (ball_x< x2)
                  && (y1 < ball_y)
                  && (ball_y < y2));
    return inretangle;
}
