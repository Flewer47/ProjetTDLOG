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
   * @brief Setter of removeMe boolean
   * @param newRemoveMe Bool that goes to false if the bullet leave the screen
   */
  void setRemoveMe(bool newRemoveMe){
      removeMe = newRemoveMe;
  }

  /**
   * @brief Getter of removeMe boolean
   */
  bool getRemoveMe() const{
      return removeMe;
  }

  /**
   * @brief Getter of X coordinate
   */
  int getPositionX() const{
      return x;
  }

  /**
   * @brief Getter of Y coordinate
   */
  int getPositionY() const{
      return y;
  }
};
