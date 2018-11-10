#include "Bullet.h"

Bullet::Bullet(float angle0){
  angle = angle0;
  x = (windowWidth/2) + std::cos(angle0)*(cannonLength + 1.5*bulletSize);
  y = windowHeight - groundHeight - boxHeight + std::sin(angle0)*(cannonLength + 1.5*bulletSize);
  removeMe = false;
}

void Bullet::display(Imagine::Color newColor) const{
  // To draw faster
  Imagine::noRefreshBegin();

  // Bullet
  Imagine::fillRect(x, y, bulletSize, bulletSize, newColor);

  Imagine::noRefreshEnd();
}

void Bullet::updatePosition(){
  // Erases the current bullet
  display(windowBackgroundColor);

  x += std::cos(angle)*bulletSpeed;
  y += std::sin(angle)*bulletSpeed;

  // Redraw the bullet
  display();
}
