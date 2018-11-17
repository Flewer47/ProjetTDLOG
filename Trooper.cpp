#include "Trooper.h"

Trooper::Trooper(int planeX, int planeY)
{
    x = planeX + planeWidth/2;
    y = planeY + planeHeight;
    v = trooperSpeedWithoutParachute;
    isParachuteDrawn = false;
    isParachuteShot = false;
    heightToDrawParachute = minHeightParachute + (rand()/(float)RAND_MAX)*(maxHeightParachute-minHeightParachute);
    isWalking = false;
    removeMe = false;
}

void Trooper::display(Imagine::Color newColor1, Imagine::Color newColor2) const{
    // To draw faster
    Imagine::noRefreshBegin();

    // Trooper
    Imagine::fillRect(x, y, trooperWidth, trooperHeight, newColor1);

    // Parachute
    Imagine::fillRect(x + trooperWidth/2 - parachuteWidth/2, y - parachuteHeight, parachuteWidth, parachuteHeight, newColor2);

    Imagine::noRefreshEnd();
}

void Trooper::updatePosition(){

    display(windowBackgroundColor, windowBackgroundColor);

    if (isWalking){
        if (x < windowWidth/2 - boxWidth/2 - trooperWidth){
            x += trooperSpeedWalking;
            display(trooperColor, windowBackgroundColor);
        }
        else if (x > windowWidth/2 + boxWidth/2){
            x -= trooperSpeedWalking;
            display(trooperColor, windowBackgroundColor);
        }
        else{ // Trooper comes inside the base.
            removeMe = true;
        }
    }

    // In the air
    else{

        y += (isParachuteDrawn ? trooperSpeedWithParachute : trooperSpeedWithoutParachute);

        if (y >= heightToDrawParachute){
            if (!isParachuteShot){
                isParachuteDrawn = true;
            }
            else {
                isParachuteDrawn = false;
            }
        }

        if(isParachuteDrawn){
            display();
        }
        else{
            display(trooperColor, windowBackgroundColor);
        }

        // Landed
        if (y >= windowHeight - groundHeight - trooperHeight){
            if (isParachuteDrawn){
                y = windowHeight - groundHeight - trooperHeight;
                isWalking = true;
            }
            // Parachute has been shot and fell into the ground
            else{
                removeMe = true;
            }
        }
    }
}

void Trooper::Touched(Bullet bullet){
    if (isParachuteDrawn) {
        bool touchParachute = ((x + trooperWidth/2 - parachuteWidth/2 < bullet.get_x())
                                && (bullet.get_x()< x + trooperWidth/2 + parachuteWidth/2)
                                && (y - parachuteHeight < bullet.get_y())
                                && (bullet.get_y() < y));
        if (touchParachute) {
            isParachuteShot=true;
            display(trooperColor, windowBackgroundColor);
            bullet.setRemoveMe(true);
            std::cout << "Parachute touched !" << std::endl;
        }
        else {
            bool touchBody = ((x < bullet.get_x())
                               && (bullet.get_x()< x + trooperWidth)
                               && (y < bullet.get_y())
                               && (bullet.get_y() < y + trooperHeight));
            if (touchBody){
                display(windowBackgroundColor, windowBackgroundColor);
                bullet.setRemoveMe(true);
                removeMe = true;
                std::cout << "Trooper touched !" << std::endl;
            }
        }
    }
    else {
        bool touchBody = ((x < bullet.get_x())
                          && (bullet.get_x()< x + trooperWidth)
                          && (y < bullet.get_y())
                          && (bullet.get_y() < y + trooperHeight));
        if (touchBody){
           display(windowBackgroundColor, windowBackgroundColor);
           bullet.setRemoveMe(true);
           removeMe = true;
           std::cout << "Trooper touched !" << std::endl;
       }
    }
}

bool Trooper::hasParachute(){
    return(isParachuteDrawn);
}
