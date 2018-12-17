#ifndef MYLIB_CONSTANTS_H
#define MYLIB_CONSTANTS_H

#include <Imagine/Graphics.h>
#include <Imagine/Images.h>

/// For the canvas

const int windowWidth = 800, windowHeight = 600, groundHeight = 20;
const Imagine::Color windowBackgroundColor = Imagine::BLACK;
const Imagine::Color groundColor = Imagine::BLUE;
const std::string windowTitle = "Paratroopers";




/// For the planes

const int planeWidth = 50;
const int planeHeight = 26;


const int dropMargin = 30;
const int leftRightPlaneHeight = 20;
const int rightLeftPlaneHeight = 70;
const int planeVelocity = 3;
const Imagine::Color planeColor = Imagine::RED;


/// For the cannon


const int boxWidth = 50, boxHeight = 30;
const Imagine::Color boxColor = Imagine::WHITE;

const int cannonLength = 30, cannonWidth = 6;
const float cannonAngularVelocity = 0.32, cannonAngleLimit = M_PI*0.42, defaultCannonAngle = -M_PI/2;
const Imagine::Color cannonColor = Imagine::WHITE;



/// For the bullets


const int bulletSpeed = 10;

const int bulletSize = 4;

const int shootFrequency = 5;


/// For the troopers


const int trooperWidth = 20;
const int trooperHeight = 20;
const Imagine::Color trooperColor = Imagine::RED;

const int parachuteWidth = 30;
const int parachuteHeight = 50;
const Imagine::Color parachuteColor = Imagine::RED;

const int trooperSpeedWithParachute = 3;
const int trooperSpeedWithoutParachute = 5;
const int trooperSpeedWalking = 2;

/// Margins
const int minHeightParachute = 300, maxHeightParachute = 400;
const int shieldMargin = boxWidth + 50;


/// For the images

const int skullTimeOfDisplay = 50;


/// For the score

const int points_body_touched = 5;
const int points_parachute_touched = 3;
const int points_bullet_used = -1;
const int points_plane_touched = 10;

#endif
