#include <iostream>
#include <Imagine/Graphics.h>


int main(){
    std::cout << "Hello World !" << std::endl;

    Imagine::IntPoint2 point(400, 400);
    Imagine::Color c("red");

    Imagine::openWindow(600, 600);
    Imagine::noRefreshBegin();
    Imagine::drawCircle(point, 50, c, 1, false);
    Imagine::noRefreshEnd();
    Imagine::endGraphics();



    return 0;
}
