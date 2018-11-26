#pragma once
#include <iostream>
#include "Constants.h"

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
   * @brief Returns the x coordinate of the Bullet
   */
  int get_x();

  /**
   * @brief Returns the y coordinate of the Bullet
   */
  int get_y();

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

  /**
   * @brief Sets wether or not bullet will be remove
   * @param rm bool (y/n)
   */
  void setRemoveMe(bool rm);
};
