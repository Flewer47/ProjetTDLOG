#include "Trooper.h"

Trooper::Trooper(int planeX, int planeY)
{
    x = planeX;
    y = planeY;
    v = trooperSpeedWithoutParachute;
    isParachuteDrawn = false;
    heightToDrawParachute = minHeightParachute + rand()*(maxHeightParachute-minHeightParachute);
    isWalking = false;
    removeMe = false;
}
