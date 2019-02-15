/// "Copyright 2019 BOUVIER-GATELLIER-GIRAUDON-SANTET"

#pragma once
#include "./Constants.h"
#include "./Bullet.h"


class Plane {

    // Position
    int x;
    int y;

    // Velocity
    int vx;

    // Check the direction (true if right, false if left)
    bool isGoingRight;

    // Check to see if it has left the screen (for memory management purpose)
    bool removeMe;

    // Determine if it has spawned an enemy yet
    bool hasSpawnedYet;

    // Determine if is has to spawn an enemy
    bool isSpawningTrooper;

    // Determine where to drop the enemy
    int dropWidth;

    // Determine if the plane was shot by a bullet
    bool planeShot;


 public:

    /**
     * @brief Plane constructor. Setting up a direction and a drop zone randomly
     */
    Plane();

    /**
     * @brief display the plane
     * @param newColor : color that is used to display the plane (original plane color by default)
     */
    void display(Imagine::Color newColor = planeColor) const;

    /**
     * @brief updatePosition of the plane
     */
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
     * @brief Update if a bullet collides the plane's hitbox
     * @param bullet : any bullet that is needed for the check
     */
    void updateIfTouched(Bullet bullet);

    /**
      * @brief Checks if the plane was shot
      */
    bool isTouched();

    /**
     * @brief get_dropwidth (for tests)
     * @return the drop width related ton the plane
     */
    int get_dropwidth();
};

/**
 * @brief test_drop_width (for tests)
 * @param n : number of plane tested
 * @return true if every plane tested has a dropmargin compatible with constraints, else false
 */
bool test_drop_width(int n);

/**
 * @brief ball_in_rectangle (for tests)
 * @param ball_x
 * @param ball_y
 * @param x1
 * @param x2
 * @param y1
 * @param y2
 * @return true if the ball is in the rectangle defined by the four points
 */
bool ball_in_rectangle(int ball_x, int ball_y, int x1, int x2, int y1, int y2);
