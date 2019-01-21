#include "ProjetTDLOG/Bullet.h"

/// "Copyright 2019 BOUVIER-GATELLIER-GIRAUDON-SANTET"

Bullet::Bullet(float angle0) {
  angle = angle0;
  x = (windowWidth/2) + std::cos(angle0)*
    (cannonLength + 1.5*bulletSize);
  y = windowHeight - groundHeight - boxHeight +
std::sin(angle0)*(cannonLength + 1.5*bulletSize);
  removeMe = false;
}

int Bullet::get_x() {
    return x;
}

int Bullet::get_y() {
    return y;
}

void Bullet::display(Imagine::Color newColor) const {
  // Bullet
  Imagine::fillRect(x, y, bulletSize, bulletSize, newColor);
}

void Bullet::updatePosition() {
  // Erases the current bullet
  display(windowBackgroundColor);

  x += std::cos(angle)*bulletSpeed;
  y += std::sin(angle)*bulletSpeed;

  if (x < 0 || x > windowWidth || y < 0) {
      removeMe = true;
  } else {
    display();
  }
}

void Bullet::setRemoveMe(bool rm) {
    removeMe = rm;
}
