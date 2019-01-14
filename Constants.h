#ifndef MYLIB_CONSTANTS_H
#define MYLIB_CONSTANTS_H

#include <Imagine/Graphics.h>
#include <Imagine/Images.h>

/// For the canvas

const int windowWidth = 800, windowHeight = 600, groundHeight = (int)(windowHeight/30);
const Imagine::Color windowBackgroundColor = Imagine::BLACK;
const Imagine::Color groundColor = Imagine::BLUE;
const std::string windowTitle = "Paratroopers";




/// For the planes

const int planeWidth = (int)(windowWidth/16);//constantes car ce sont des tailles d images
const int planeHeight = 26;


const int dropMargin = (int)(windowWidth/10);
const int leftRightPlaneHeight = (int)(windowHeight/30);
const int rightLeftPlaneHeight = (int)(windowHeight*7/60);
const int planeVelocity = (int)(windowWidth*3/800);
const Imagine::Color planeColor = Imagine::RED;


/// For the cannon


const int boxWidth = (int)(windowWidth/16), boxHeight =(int)(windowHeight/20);
const Imagine::Color boxColor = Imagine::WHITE;

const int cannonLength = (int)(windowHeight/20), cannonWidth = (int)(windowHeight/100);
const float cannonAngularVelocity = 0.32, cannonAngleLimit = M_PI/2, defaultCannonAngle = -M_PI/2;//constantes independantes de la fenetre
const Imagine::Color cannonColor = Imagine::WHITE;



/// For the bullets


const int bulletSpeed = (int)(windowHeight/60);

const int bulletSize = (int)(windowWidth/200);

const int shootFrequency = 5;


/// For the troopers

const int trooperWidth = 21;//fixe car image
const int trooperHeight = 45;//fixe car image
const Imagine::Color trooperColor = Imagine::RED;

const int parachuteWidth = 100;//fixe car image
const int parachuteHeight = 100;//fixe car image
const Imagine::Color parachuteColor = Imagine::RED;

const int trooperSpeedWithParachute = 2;
const int trooperSpeedWithoutParachute = 4;
const int trooperSpeedWalking = 2;

/// Margins
const int minHeightParachute = 300, maxHeightParachute = 400;
const int shieldMargin = boxWidth + 130;


/// For the images

const int skullTimeOfDisplay = 50;


/// For the score

const int points_body_touched = 5;
const int points_parachute_touched = 3;
const int points_bullet_used = -1;
const int points_plane_touched = 10;

#endif
