#pragma once
#include <iostream>
#include "Canvas.h"
#include "Cannon.h"

/// For the speed of the bullet
const int bulletSpeed = 10;

/// For the size of the bullet
const int bulletSize = 4;

/// For shooting
const int shootFrequency = 4;

class Bullet{
private:
  float angle;
  int x;
  int y;

  // Check to see if it has left the screen (for memory management purpose)
  bool removeMe;

public:

  /**
   * @brief Create at bullet object
   * @param angle0 Angle of the cannon
   */
  Bullet(float angle0);

  /**
   * @brief Update the position of the bullet at the next frame
   */
  void updatePosition();

  /**
   * @brief Display the bullet
   * @param newColor Color of the bullet (cannonColor by default)
   */
  void display(Imagine::Color newColor = cannonColor) const;

  /**
   * @brief Getter of removeMe boolean
   */
  bool getRemoveMe() const{
      return removeMe;
  }
};
