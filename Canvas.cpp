#include "Canvas.h"


Canvas::Canvas()
{
    window = Imagine::openWindow(windowWidth, windowHeight, windowTitle);
    Imagine::setBackGround(windowBackgroundColor);
    isGameActive = false;
}

void Canvas::closeCanvas() const{
    if (isCanvasActive){
        Imagine::closeWindow(window);
    }
}

void Canvas::startMenu(int& mode){
    int x=0, y=0;
    Imagine::fillRect(200, 50, 400, 150, Imagine::RED);
    Imagine::fillRect(300, 275, 200, 50, Imagine::YELLOW); // Start Button
    Imagine::drawString(390, 310, "START", Imagine::GREEN);
    Imagine::fillRect(300, 375, 200, 50, Imagine::YELLOW); // Option Button
    Imagine::drawString(390, 410, "OPTIONS (Ne pas cliquer)", Imagine::GREEN);
    Imagine::fillRect(300, 475, 200, 50, Imagine::YELLOW); // Quit Button
    Imagine::drawString(390, 510, "QUIT", Imagine::GREEN);
    while(mode==0){
        Imagine::getMouse(x,y);
        Imagine::milliSleep(10);
        if ((300<=x) && (x<=500) && (275<=y) && (y<=325)){
            mode=1;
            Imagine::fillRect(300, 275, 200, 50, Imagine::BLUE);
            Imagine::milliSleep(80);
        }
        else if ((300<=x) && (x<=500) && (375<=y) && (y<=425)){
            // NE PAS CLIQUER SUR OPTION !!!
            mode=2;
            Imagine::fillRect(300, 375, 200, 50, Imagine::BLUE);
            Imagine::milliSleep(80);
        }
        else if ((300<=x) && (x<=500) && (475<=y) && (y<=525)){
            mode=3;
            Imagine::fillRect(300, 475, 200, 50, Imagine::BLUE);
            Imagine::milliSleep(80);
        }
    }
    Imagine::fillRect(0,0,windowWidth,windowHeight,windowBackgroundColor);
    isGameActive = true;
}
