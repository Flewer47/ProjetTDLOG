#include "Canvas.h"

Canvas::Canvas(int newWidth, int newHeight, std::string newTitle, Imagine::Color newBackgroundColor, int newDropMargin,
               int newLeftRightPlaneHeight, int newRightLeftPlaneHeight, int newShieldMargin, int newMaxHeightParachute,
               int newMinHeightParachute, int newGroundHeight)
{
    width = newWidth;
    height = newHeight;
    title = newTitle;
    backgroundColor = newBackgroundColor;
    dropMargin = newDropMargin;
    leftRightPlaneHeight = newLeftRightPlaneHeight;
    rightLeftPlaneHeight = newRightLeftPlaneHeight;
    shieldMargin = newShieldMargin;
    maxHeigthParachute = newMaxHeightParachute;
    minHeightParachute = newMinHeightParachute;
    groundHeight = newGroundHeight;

    Imagine::Window window = Imagine::openWindow(width, height, title);
    Imagine::setActiveWindow(window);
    Imagine::setBackGround(backgroundColor);

    activeCanvas = true;
}

void Canvas::closeCanvas(){
    if (activeCanvas){
        Imagine::endGraphics();
    }
}
