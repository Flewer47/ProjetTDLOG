#include "Trooper.h"
#include "Plane.h"

Trooper::Trooper(int planeX, int planeY)
{
    x = planeX + planeWidth/2;
    y = planeY + planeHeight;
    v = trooperSpeedWithoutParachute;
    isParachuteDrawn = false;
    isParachuteShot = false;
    isWalking = false;
    removeMe = false;
    cameinBase = false;
    bodyTouched = false;
    parachuteOpening = false;
    heightToDrawParachute = minHeightParachute + (rand()/(float)RAND_MAX)*(maxHeightParachute-minHeightParachute);
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
        Imagine::fillRect(x + trooperWidth/2 - skull.width()/2,
                          y - 3*skull.height()/4, skull.width(), skull.height(), Imagine::BLACK);
    }
    else {
        displayPicture(x + trooperWidth/2 - skull.width()/2,
                       y - 3*skull.height()/4, srcPath("Images/skull.png"));
    }
}

void Trooper::updateWalkingTrooper(){
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

void Trooper::updateTrooperInTheAir(){
    if(y<windowHeight - groundHeight - trooperHeight){
        y += (isParachuteDrawn ? trooperSpeedWithParachute : trooperSpeedWithoutParachute);
    }
    if (y >= heightToDrawParachute){
        if (!parachuteOpening && !isParachuteShot) {
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
}

void Trooper::updateLandedTrooper(){
    if (y > windowHeight - groundHeight - parachuteHeight && isParachuteDrawn){
        displayBackground(x - parachuteWidth/2 + trooperWidth/2,
                          windowHeight - groundHeight - parachuteHeight,
                          parachuteWidth,parachuteHeight);
        y = windowHeight - groundHeight - trooperHeight;

        isWalking = true;
    }
}

void Trooper::updateTrooperCrashed(){
    if (y >= windowHeight - groundHeight - trooperHeight && isParachuteShot){
        displayBackground(x,windowHeight - groundHeight - trooperHeight,trooperWidth,trooperHeight);
        y = windowHeight - groundHeight - trooperHeight;
        displaySkull();

        if (countDisplaySkull==0){ removeMe = true; }
        else { countDisplaySkull--; }
    }
}

void Trooper::updatePosition(){

    displayBackground(x, y, trooperWidth, trooperHeight);

    // On the ground
    if (isWalking){ updateWalkingTrooper(); }

    // In the air
    else{
        updateTrooperInTheAir();

        // If landed with parachute
        updateLandedTrooper();

        // If parachute has been shot and trooper fell into the ground, display the skull
        updateTrooperCrashed();

    }
}

void Trooper::Touched(Bullet bullet){
    if (isParachuteDrawn) {
        bool touchParachute = ball_in_rectangle(bullet.get_x(), bullet.get_y(),x, x+ parachuteWidth, y, y + parachuteHeight-trooperHeight);
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
            bool touchBody = ball_in_rectangle(bullet.get_x(), bullet.get_y(),x, x+ w, y + parachuteHeight - trooperHeight,y + parachuteHeight);
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
        bool touchBody = ball_in_rectangle(bullet.get_x(), bullet.get_y(),x, x + trooperWidth, y ,y + trooperHeight);
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

bool Trooper::testYContinuity(){
    srand(time(0));
    y = planeHeight;
    x = dropMargin + (rand()/(float)RAND_MAX)*(windowWidth - 2*(shieldMargin/2 + dropMargin));
    isParachuteDrawn = true;
    int y1;
    while(!isWalking){
        y1 = y;
        updatePosition();
        if(y-y1 > trooperSpeedWithParachute && !isWalking){return false;}
    }
    return true;


}

