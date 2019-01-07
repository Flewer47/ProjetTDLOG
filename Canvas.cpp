#include "Canvas.h"


Canvas::Canvas()
{
    window = Imagine::openWindow(windowWidth, windowHeight, windowTitle);
    Imagine::setBackGround(windowBackgroundColor);
}

void Canvas::closeCanvas() const{
    Imagine::closeWindow(window);
}

void Canvas::startMenu(int& mode){
    int x=0, y=0;

    Imagine::Image<Imagine::AlphaColor> title;
    load(title, srcPath("Images/Title.png"));
    Imagine::display(title, 100, 50);           // Title

    Imagine::Image<Imagine::AlphaColor> start;
    load(start, srcPath("Images/start.png"));
    Imagine::display(start, 300, 275);           // Start

    Imagine::Image<Imagine::AlphaColor> quit;
    load(quit, srcPath("Images/quit.png"));
    Imagine::display(quit, 300, 475);             // Quit

    load(start, srcPath("Images/start_clicked.png"));
    load(quit, srcPath("Images/quit_clicked.png"));

    while(mode==0){
        Imagine::getMouse(x,y);
        Imagine::milliSleep(10);
        if ((300<=x) && (x<=500) && (275<=y) && (y<=325)){
            mode=1;
            Imagine::display(start, 300, 275);
            Imagine::milliSleep(80);
        }
        else if ((300<=x) && (x<=500) && (475<=y) && (y<=525)){
            mode=3;
            Imagine::display(quit, 300, 475);
            Imagine::milliSleep(80);
        }
    }
    Imagine::fillRect(0,0,windowWidth,windowHeight,windowBackgroundColor);
}
