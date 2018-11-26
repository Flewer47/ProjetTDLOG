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
    countDisplaySkull = skullTimeOfDisplay;
}

void Trooper::display(Imagine::Color newColor1, Imagine::Color newColor2) const{
    // To draw faster
    Imagine::noRefreshBegin();

    // Trooper
    Imagine::fillRect(x, y, trooperWidth, trooperHeight, newColor1);

    // Parachute
    Imagine::IntPoint2 p[]={Imagine::IntPoint2(x+trooperWidth/2, y),
                            Imagine::IntPoint2(x+trooperWidth/2-parachuteWidth/2, y-parachuteHeight),
                            Imagine::IntPoint2(x+trooperWidth/2+parachuteWidth/2, y-parachuteHeight)};   // triangle
    if(isParachuteDrawn) Imagine::fillPoly(p,3,newColor2);

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
            cameinBase = true;
            removeMe = true;
        }
    }

    // In the air
    else{

        y += (isParachuteDrawn ? trooperSpeedWithParachute : trooperSpeedWithoutParachute);

        if (y >= heightToDrawParachute){
            isParachuteDrawn = !isParachuteShot;
        }

        if(isParachuteDrawn){
            display();
        }
        else{
            display(trooperColor, windowBackgroundColor);
        }

        // Landed
        if (y > windowHeight - groundHeight - trooperHeight){
            if (isParachuteDrawn){
                y = windowHeight - groundHeight - trooperHeight;
                isWalking = true;
            }
            // Parachute has been shot and fell into the ground, display the skull
            else{
                display(windowBackgroundColor, windowBackgroundColor);

                y -= trooperSpeedWithoutParachute;

                Imagine::Image<Imagine::AlphaColor> skull;
                Imagine::load(skull, srcPath("Images/skull.png"));

                if (countDisplaySkull==0){
                    Imagine::fillRect(x + trooperWidth/2 - skull.width()/2,
                                      y - 3*skull.height()/4, skull.width(), skull.height(), Imagine::BLACK);
                    removeMe = true;
                }
                else{
                    Imagine::display(skull, x + trooperWidth/2 - skull.width()/2, y - 3*skull.height()/4);
                    countDisplaySkull--;
                }
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
                bodyTouched = true;
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

