/// "Copyright 2019 BOUVIER-GATELLIER-GIRAUDON-SANTET"

#pragma once
#include <string>
#include "./Constants.h"
#include "./Bullet.h"

class Trooper {
    // Position
    int x;
    int y;

    // Dimension
    int w;
    int h;

    // Speed
    int v;

    // Picture of the trooper without parachute
    Imagine::Image<Imagine::AlphaColor> trooperWithoutParachutePicture;

    // Picture of the trooper with parachute
    Imagine::Image<Imagine::AlphaColor> trooperWithParachutePicture;

    // Picture of the skull
    Imagine::Image<Imagine::AlphaColor> skull;

    // Check if he has deployed its parachute
    bool isParachuteDrawn;

    // Check if parachute has been shot
    bool isParachuteShot;

    // Time remaining of display of the skull, -1 if skull not displayed
    int countDisplaySkull;

    // Height when he will deploy its parachute
    int heightToDrawParachute;

    // Check if he has touched the ground
    bool isWalking;

    // Check if he has been killed (for memory management purpose)
    bool removeMe;

    // Check if the trooper managed to enter the base
    bool cameinBase;

    // Check if the body was touched
    bool bodyTouched;

    // Check if this is the instant where the parachute opened
    bool parachuteOpening;

 public:
    /**
     * @brief Creates a trooper
     * @param planeX X coordinate of the plane that spawned the trooper
     * @param planeY Y coordinate of the plane that spawned the trooper
     */
    Trooper(int planeX, int planeY);

    /**
     * @brief Display a rectangle of the color of the background
     * @param x1 X coordinate of the upper right angle of the rectangle
     * @param y1 Y coordinate of the upper right angle of the rectangle
     * @param w Width of the rectangle
     * @param h Height of the rectangle
     */
    void displayBackground(int x1, int y1, int w1, int h1) const;

    /**
     * @brief Display an AlphaColorImage
     * @param x1 X coordinate of the upper right angle of the picture
     * @param y1 Y coordinate of the upper right angle of the picture
     * @param filename name of the file
     */
    void displayPicture(int x1, int y1, std::string filename) const;

    /**
     * @brief Display the trooper with a parachute
     */
    void displayTrooperWithParachute() const;

    /**
     * @brief Display the trooper when free falling
     */
    void displayFreeFall() const;

    /**
     * @brief Display the trooper when walking
     * @param isGoingRight Indicates if the trooper is going right or left
     */
    void displayWalkingTrooper(bool isGoingRight) const;

    /**
     * @brief Display the skull
     */
    void displaySkull() const;

    /**
     * @brief Update the position of the trooper if he is walking
     */
    void updateIfTrooperWalking();

    /**
     * @brief Update the position of the trooper if he is in the air
     */
    void updateIfTrooperInTheAir();

    /**
     * @brief Update the position of the trooper if he has landed
     */
    void updateIfTrooperLanded();

    /**
     * @brief Update the position of the trooper if he has crashed on the ground
     */
    void updateIfTrooperCrashed();

    /**
     * @brief Update the position of the trooper at the next frame
     */
    void updatePosition();

    /**
     * @brief Getter of removeMe boolean
     */
    bool getRemoveMe() const {
        return removeMe;
    }

    /**
     * @brief Update if a bullet collides the parachute's hitbox
     * @param bullet Bullet
     */
    void updateIfParachuteTouched(Bullet bullet);

    /**
     * @brief Update if a bullet collides the trooper's body hitbox
     * @param bullet Bullet
     */
    void updateIfBodyTouched(Bullet bullet);

    /**
     * @brief Update if a bullet collides the trooper's body or parachute's hitbox
     * @param bullet Bullet
     */
    void updateIfTouched(Bullet bullet);

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

    /**
     * @brief Checks if there is a rupture of continuity in the Y movement of a trooper
     */
    bool testYContinuity();
};
