#include <iostream>
#include <Imagine/Graphics.h>

/// For the cancas
int const width = 600, height = 600;
std::string const windowTitle = "Paratroopers";

/// For the player
int const playerWidth = 50, playerHeight = 30;
Imagine::Color playerColor = Imagine::BLACK;

/// For the canon
float const canonLength = 30, canonAngularVelocity = 0.1;
const int canonWidth = 6;
Imagine::Color canonColor = Imagine::BLACK;


int main(){
    std::cout << "Hello World !" << std::endl;

    Imagine::openWindow(width, height, windowTitle);

    Imagine::IntPoint2 player(width/2 - playerWidth/2, height - playerHeight);
    Imagine::IntPoint2 canon(width/2, height - playerHeight);

    Imagine::fillRect(player, playerWidth, playerHeight, playerColor);

    float canonAngle = -M_PI/2;
    int compteur = 0;
    while (compteur != 100){
        compteur++;
        Imagine::drawLine(canon, canon + Imagine::IntPoint2(canonLength*std::cos(canonAngle), canonLength*std::sin(canonAngle)), canonColor, canonWidth);
        Imagine::milliSleep(100);
        Imagine::drawLine(canon, canon + Imagine::IntPoint2(canonLength*std::cos(canonAngle), canonLength*std::sin(canonAngle)), Imagine::WHITE, canonWidth);
        Imagine::fillRect(player, playerWidth, playerHeight, playerColor);
        canonAngle += canonAngularVelocity;
    }



    Imagine::endGraphics();



    return 0;
}
