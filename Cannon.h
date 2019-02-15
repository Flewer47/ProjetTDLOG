/// "Copyright 2019 BOUVIER-GATELLIER-GIRAUDON-SANTET"

#pragma once
#include "./Constants.h"




class Cannon{
 private:
    // Angle of the cannon
    float angle;

 public:
    /**
     * @brief Creates a cannon object
     */
    Cannon();

    /**
     * @brief Display the cannon
     * @param newColor1 Color of the box (boxColor by default)
     * @param newColor2 Color of the cannon (cannonColor by default)
     */
    void display(Imagine::Color newColor1 = boxColor,
Imagine::Color newColor2 = cannonColor) const;

    /**
     * @brief Update the position of the cannon
     * @param direction Belongs in {-1,0,1} and indicates which key is pressed if any to change the position of the cannon
     */
    void updatePosition(int direction);
    /**
     * @brief Return the angle of the cannon
     */
    float getAngle() const;
};
