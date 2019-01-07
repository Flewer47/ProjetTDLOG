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
    cameinBase = false;
    bodyTouched = false;
    parachuteOpening = false;
    countDisplaySkull = skullTimeOfDisplay;

    Imagine::load(trooperWithParachutePicture, srcPath("Images/trooperWithParachute.png"));
    Imagine::load(trooperWithoutParachutePicture, srcPath("Images/trooperWithoutParachute.png"));
    Imagine::load(skull, srcPath("Images/skull.png"));
    w = trooperWithoutParachutePicture.width();
    h = trooperWithoutParachutePicture.height();
}

void Trooper::displayBackground(int x1, int y1, int w1, int h1) const {
    Imagine::fillRect(x1, y1, w1, h1, Imagine::BLACK);
}

void Trooper::displayPicture(int x1, int y1, std::string filename) const{
    Imagine::AlphaColor *AC;
    int Aw, Ah;
    Imagine::loadAlphaColorImage(filename, AC, Aw, Ah);
    Imagine::putAlphaColorImage(x1, y1,AC,Aw,Ah);
}

void Trooper::displayFreeFall() const{
    displayPicture(x, y - trooperSpeedWithoutParachute,
                   srcPath("Images/trooperWithoutParachuteBlack.png"));
    displayPicture(x, y,srcPath("Images/trooperWithoutParachute.png"));

}

void Trooper::displayTrooperWithParachute() const{    
    displayPicture(x - parachuteWidth/2 + trooperWidth/2,y - trooperSpeedWithParachute,
                   srcPath("Images/trooperWithParachuteBlack.png"));
    displayPicture(x - parachuteWidth/2 + trooperWidth/2,y,
                   srcPath("Images/trooperWithParachute.png"));
}

void Trooper::displayWalkingTrooper(bool isGoingRight) const {
    if (isGoingRight) displayPicture(x-trooperSpeedWalking,y,
                                     srcPath("Images/trooperWithoutParachuteBlack.png"));
    else displayPicture(x+trooperSpeedWalking,y,
                        srcPath("Images/trooperWithoutParachuteBlack.png"));
    displayPicture(x,y,srcPath("Images/trooperWithoutParachute.png"));
}

void Trooper::displaySkull() const{
    if (countDisplaySkull == 0) {
        displayPicture(x + trooperWidth/2 - skull.width()/2,
                       y - 3*skull.height()/4,srcPath("Images/skullBlack.png"));
    }
    else {
        displayPicture(x + trooperWidth/2 - skull.width()/2,
                       y - 3*skull.height()/4,srcPath("Images/skull.png"));
    }
}

void Trooper::updatePosition(){

    displayBackground(x, y, trooperWidth, trooperHeight);

    if (isWalking){
        if (x < windowWidth/2 - boxWidth/2 - trooperWidth){
            x += trooperSpeedWalking;
            displayWalkingTrooper(true);
        }
        else if (x > windowWidth/2 + boxWidth/2){
            x -= trooperSpeedWalking;
            displayWalkingTrooper(false);
        }
        else{ // Trooper comes inside the base.
            cameinBase = true;
            removeMe = true;
        }
    }

    // In the air
    else{
        if(y<windowHeight - groundHeight - h){
            y += (isParachuteDrawn ? trooperSpeedWithParachute : trooperSpeedWithoutParachute);
        }
        if (y >= heightToDrawParachute){
            if (!parachuteOpening) {
                y -= parachuteHeight - trooperHeight;
                parachuteOpening = true;
            }
            isParachuteDrawn = !isParachuteShot;
        }

        if(isParachuteDrawn){
            displayTrooperWithParachute();
        }
        else{
            displayFreeFall();
        }

        // Landed
        if (y > windowHeight - groundHeight - parachuteHeight && isParachuteDrawn){
            displayBackground(x - parachuteWidth/2 + trooperWidth/2,
                              windowHeight - groundHeight - parachuteHeight,
                              parachuteWidth,parachuteHeight);
            y = windowHeight - groundHeight - trooperHeight;

            isWalking = true;
        }

        // Parachute has been shot and fell into the ground, display the skull
        else if (y >= windowHeight - groundHeight - trooperHeight && !isParachuteDrawn){
            displayBackground(x,windowHeight - groundHeight - trooperHeight,trooperWidth,trooperHeight);
            y = windowHeight - groundHeight - trooperHeight;
            displaySkull();

            if (countDisplaySkull==0){ removeMe = true; }
            else { countDisplaySkull--; }
        }

    }
}

void Trooper::Touched(Bullet bullet){
    if (isParachuteDrawn) {
        bool touchParachute = ((x <= bullet.get_x())
                               && (bullet.get_x() <= x + parachuteWidth)
                               && (y <= bullet.get_y())
                               && (bullet.get_y() <= y + parachuteHeight-trooperHeight));
        if (touchParachute && y < windowHeight - groundHeight - parachuteHeight) {
            isParachuteShot=true;
            displayBackground(x - parachuteWidth/2 + w/2, y,
                              parachuteWidth, parachuteHeight);
            y += parachuteHeight - trooperHeight;
            displayFreeFall();
            bullet.setRemoveMe(true);
            std::cout << "Parachute touched !" << std::endl;
        }
        else {
            bool touchBody = ((x <= bullet.get_x())
                              && (bullet.get_x() <= x + w)
                              && (y + parachuteHeight - trooperHeight <= bullet.get_y())
                              && (bullet.get_y() <= y + parachuteHeight));
            if (touchBody){
                bodyTouched = true;
                displayBackground(x - parachuteWidth/2 + w/2, y,
                                  parachuteWidth,parachuteHeight);
                bullet.setRemoveMe(true);
                removeMe = true;
                std::cout << "Trooper touched !" << std::endl;
            }
        }
    }
    else {
        bool touchBody = ((x <= bullet.get_x())
                          && (bullet.get_x() <= x + trooperWidth)
                          && (y <= bullet.get_y())
                          && (bullet.get_y() <= y + trooperHeight));
        if (touchBody){
            displayBackground(x,y,trooperWidth,trooperHeight);
            bullet.setRemoveMe(true);
            bodyTouched = true;
            removeMe = true;
            std::cout << "Trooper touched !" << std::endl;
        }
    }
}

bool Trooper::hasParachute(){
    return(isParachuteDrawn);
}

bool Trooper::hascameinBase(){
    return(cameinBase);
}

bool Trooper::isparachuteTouched(){
    return(isParachuteShot);
}

bool Trooper::isbodyTouched(){
    return(bodyTouched);
}

