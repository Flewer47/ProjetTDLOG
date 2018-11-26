#include "Canvas.h"


Canvas::Canvas()
{
    Imagine::openWindow(windowWidth, windowHeight, windowTitle);
    Imagine::setBackGround(windowBackgroundColor);
    Imagine::fillRect(0, windowHeight-groundHeight, windowWidth, groundHeight, groundColor);
    isCanvasActive = true;
}

void Canvas::closeCanvas() const{
    if (isCanvasActive){
        Imagine::endGraphics();
    }
}
