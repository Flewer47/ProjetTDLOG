#include "game.h"

int main(){
        std::cout << test_drop_width(100)<< std::endl;
        int planeX = dropMargin + (rand()/(float)RAND_MAX)*(windowWidth - 2*(shieldMargin/2 + dropMargin));
        int planeY = planeHeight;
        Trooper trooperTest(planeX, planeY);
        std::cout << trooperTest.testYContinuity() << std::endl;
}
