#include "game.h"

int main(){
<<<<<<< HEAD
    Imagine::Window window = Imagine::openWindow(windowWidth, windowHeight, windowTitle);
    Imagine::setActiveWindow(window);

    //
    std::cout << "Test on the troopers' drop zone : " << test_drop_width(100)<< std::endl;

    //
    int planeX = dropMargin + (rand()/(float)RAND_MAX)*(windowWidth - 2*(shieldMargin/2 + dropMargin));
    int planeY = planeHeight;
    Trooper trooperTest(planeX, planeY);
    std::cout << "Test on the continuity of the trooper's trajectory : " << trooperTest.testYContinuity() << std::endl;

    Imagine::closeWindow(window);
return EXIT_SUCCESS;

}
