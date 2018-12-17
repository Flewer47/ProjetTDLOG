#ifndef PLANE_H
#define PLANE_H
#include "Constants.h"
#include "Bullet.h"


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
    /**
     * @brief get_dropwidth
     * @return the drop width related ton the plane
     */
    int get_dropwidth();

};

/**
 * @brief test_drop_width
 * @param n : number of plane tested
 * @return true if every plane tested has a dropmargin compatible with constraints, else false
 */
bool test_drop_width(int n);

#endif // PLANE_H
