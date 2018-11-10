#pragma once
#include <iostream>
#include "Canvas.h"
#include "Cannon.h"

/// For the speed of the bullet
const int bulletSpeed = 10;

/// For the size of the bullet
const int bulletSize = 4;

class Bullet{
private:
  float angle;
  int x;
  int y;
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
};
