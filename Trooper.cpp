#include "Trooper.h"

Trooper::Trooper(int planeX, int planeY)
{

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
    x = planeX + planeWidth/2 - w/2;
    y = planeY + planeHeight;
}

void Trooper::displayBackground(int x1, int y1, int w, int h) const {
    Imagine::fillRect(x1, y1, w, h, Imagine::BLACK);
}

void Trooper::displayFreeFall() const{
    displayBackground(x, y - trooperSpeedWithoutParachute, w, h);
    Imagine::display(trooperWithoutParachutePicture, x, y);
}

void Trooper::displayTrooperWithParachute() const{
    displayBackground(x - trooperWithParachutePicture.width()/2 + w/2, y - trooperSpeedWithoutParachute
                      , trooperWithParachutePicture.width(), trooperWithParachutePicture.height());
    Imagine::display(trooperWithParachutePicture, x - trooperWithParachutePicture.width()/2 + w/2, y);

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
        Imagine::display(skull, x + trooperWidth/2 - skull.width()/2, y - 3*skull.height()/4);
    }
}

void Trooper::updatePosition(){

    displayBackground(x, y, w, h);

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

        y += (isParachuteDrawn ? trooperSpeedWithParachute : trooperSpeedWithoutParachute);

        if (y >= heightToDrawParachute){
            if (!parachuteOpening) {
                y -= trooperWithParachutePicture.height() - trooperWithoutParachutePicture.height();
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
        if (y > windowHeight - groundHeight - trooperWithParachutePicture.height() && isParachuteDrawn){
            displayBackground(x - trooperWithParachutePicture.width()/2 + w/2,
                              windowHeight - groundHeight - trooperWithParachutePicture.height(),
                              trooperWithParachutePicture.width(),trooperWithParachutePicture.height());
            y = windowHeight - groundHeight - h;

            isWalking = true;
        }

        // Parachute has been shot and fell into the ground, display the skull
        else if (y > windowHeight - groundHeight - h && !isParachuteDrawn){
            displayBackground(x,windowHeight - groundHeight - h,w,h);
            y = windowHeight - groundHeight - h;
            displaySkull();

            if (countDisplaySkull==0){ removeMe = true; }
            else { countDisplaySkull--; }
        }

    }
}

void Trooper::Touched(Bullet bullet){
    if (isParachuteDrawn) {
        bool touchParachute = ((x <= bullet.get_x())
                               && (bullet.get_x() <= x + trooperWithParachutePicture.width())
                               && (y <= bullet.get_y())
                               && (bullet.get_y() <= y+trooperWithParachutePicture.height()-h));
        if (touchParachute && y < windowHeight - groundHeight - trooperWithParachutePicture.height()) {
            isParachuteShot=true;
            displayBackground(x - trooperWithParachutePicture.width()/2 + w/2, y,
                              trooperWithParachutePicture.width(),trooperWithParachutePicture.height());
            y += trooperWithParachutePicture.height() - trooperWithoutParachutePicture.height();
            displayFreeFall();
            bullet.setRemoveMe(true);
            std::cout << "Parachute touched !" << std::endl;
        }
        else {
            bool touchBody = ((x <= bullet.get_x())
                              && (bullet.get_x() <= x + w)
                              && (y + trooperWithParachutePicture.height() - h <= bullet.get_y())
                              && (bullet.get_y() <= y + trooperWithParachutePicture.height()));
            if (touchBody){
                bodyTouched = true;
                displayBackground(x - trooperWithParachutePicture.width()/2 + w/2, y,
                                  trooperWithParachutePicture.width(),trooperWithParachutePicture.height());
                bullet.setRemoveMe(true);
                removeMe = true;
                std::cout << "Trooper touched !" << std::endl;
            }
        }
    }
    else {
        bool touchBody = ((x <= bullet.get_x())
                          && (bullet.get_x() <= x + w)
                          && (y <= bullet.get_y())
                          && (bullet.get_y() <= y + h));
        if (touchBody){
            displayBackground(x,y,w,h);
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

