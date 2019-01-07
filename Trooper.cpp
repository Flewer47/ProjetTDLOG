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

void Trooper::displayFreeFall() const{
    displayBackground(x, y - trooperSpeedWithoutParachute, w, h);
    Imagine::AlphaColor *AC;
    int Aw, Ah;
    Imagine::loadAlphaColorImage(srcPath("Images/trooperWithoutParachute.png"), AC, Aw, Ah);
    Imagine::putAlphaColorImage(x,y,AC,Aw,Ah);
}

void Trooper::displayTrooperWithParachute() const{
    Imagine::AlphaColor *AC;
    Imagine::Color *C;
    int Aw, Ah;
    Imagine::loadColorImage(srcPath("Images/trooperWithParachuteBlack.png"), C, Aw, Ah);
    Imagine::putColorImage(x - Aw/2 + w/2,y - trooperSpeedWithParachute,C,Aw,Ah);
    Imagine::loadAlphaColorImage(srcPath("Images/trooperWithParachute.png"), AC, Aw, Ah);
    Imagine::putAlphaColorImage(x - Aw/2 + w/2,y,AC,Aw,Ah);
}

void Trooper::displayWalkingTrooper(bool isGoingRight) const {
    if (isGoingRight) displayBackground(x - trooperSpeedWalking, y, w, h);
    else displayBackground(x + trooperSpeedWalking, y, w, h);
    Imagine::display(trooperWithoutParachutePicture, x, y);
}

void Trooper::displaySkull() const{
    if (countDisplaySkull == 0) {
        Imagine::fillRect(x + trooperWidth/2 - skull.width()/2,
                          y - 3*skull.height()/4, skull.width(), skull.height(), Imagine::BLACK);
    }
    else {
        Imagine::AlphaColor *AC;
        int Aw, Ah;
        Imagine::loadAlphaColorImage(srcPath("Images/skull.png"), AC, Aw, Ah);
        Imagine::putAlphaColorImage(x + trooperWidth/2 - Aw/2,
                                    y - 3*Ah/4,AC,Aw,Ah);

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

