#include "Canvas.h"


Canvas::Canvas()
{
    Imagine::openWindow(windowWidth, windowHeight, windowTitle);
    Imagine::setBackGround(windowBackgroundColor);
    isGameActive = false;
}

void Canvas::closeCanvas() const{
    Imagine::endGraphics();
}

void Canvas::startMenu(){
    int x,y;
    Imagine::fillRect(200, 50, 400, 150, Imagine::RED);
    Imagine::fillRect(300, 275, 200, 50, Imagine::YELLOW);
    Imagine::drawString(390, 310, "START", Imagine::GREEN);
    Imagine::fillRect(300, 375, 200, 50, Imagine::YELLOW);
    Imagine::fillRect(300, 475, 200, 50, Imagine::YELLOW);
    while(!((300<=x) && (x<=500) && (275<=y) && (y<=325))){
        Imagine::getMouse(x,y);
        Imagine::milliSleep(5);
    }
    Imagine::fillRect(0,0,windowWidth,windowHeight,windowBackgroundColor);
    isGameActive = true;
}
