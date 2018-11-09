#include "Canvas.h"


Canvas::Canvas()
{
    Imagine::Window window = Imagine::openWindow(windowWidth, windowHeight, windowTitle);
    Imagine::setActiveWindow(window);
    Imagine::setBackGround(windowBackgroundColor);

    activeCanvas = true;
}

void Canvas::closeCanvas() const{
    if (activeCanvas){
        Imagine::endGraphics();
    }
}
