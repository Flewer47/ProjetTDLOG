#ifndef MYLIB_CONSTANTS_H
#define MYLIB_CONSTANTS_H

#include <Imagine/Graphics.h>
#include <Imagine/Images.h>

/// For the canvas

const int windowWidth = 800, windowHeight = 600, groundHeight = (int)(windowHeight/30);
const Imagine::Color windowBackgroundColor = Imagine::BLACK;
const Imagine::Color groundColor = Imagine::BLUE;
const std::string windowTitle = "Paratroopers";


const Imagine::IntPoint2 pos_Title = Imagine::IntPoint2(100, 50);
const Imagine::IntPoint2 size_Button = Imagine::IntPoint2(200, 50);
const Imagine::IntPoint2 pos_Start = Imagine::IntPoint2(300, 250);
const Imagine::IntPoint2 pos_TUTORIAL = Imagine::IntPoint2(335, 380);
const Imagine::IntPoint2 pos_Tuto1 = Imagine::IntPoint2(235, 420);
const Imagine::IntPoint2 pos_Tuto2 = Imagine::IntPoint2(335, 443);
const Imagine::IntPoint2 pos_Quit = Imagine::IntPoint2(300, 500);
const int click_Inertia = 80;
const Imagine::IntPoint2 pos_WhiteRectGO = Imagine::IntPoint2(200, 200);
const Imagine::IntPoint2 size_WhiteRectGO = Imagine::IntPoint2(400, 350);
const int width_WhiteRectGo = 10;
const Imagine::IntPoint2 pos_txtGO = Imagine::IntPoint2(300, 250);
const Imagine::IntPoint2 pos_YOULOSE = Imagine::IntPoint2(320, 450);
const Imagine::IntPoint2 pos_Start_GO = Imagine::IntPoint2(300, 275);
const Imagine::IntPoint2 pos_Quit_GO = Imagine::IntPoint2(300, 475);
const Imagine::IntPoint2 pos_ScoreTXT_GO = Imagine::IntPoint2(350, 400);
const Imagine::IntPoint2 pos_ScoreVAR_GO = Imagine::IntPoint2(400, 400);


/// For the planes

const int planeWidth = (int)(windowWidth/16);//fixed because of the picture
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
const float cannonAngularVelocity = 0.32, cannonAngleLimit = M_PI/2, defaultCannonAngle = -M_PI/2;//do not depend on the dimensions of the window
const Imagine::Color cannonColor = Imagine::WHITE;



/// For the bullets


const int bulletSpeed = (int)(windowHeight/60);

const int bulletSize = (int)(windowWidth/200);

const int shootFrequency = 5;


/// For the troopers

const int trooperWidth = 21;//fixed because of the picture
const int trooperHeight = 45;//fixed because of the picture
const Imagine::Color trooperColor = Imagine::RED;

const int parachuteWidth = 100;//fixed because of the picture
const int parachuteHeight = 100;//fixed because of the picture
const Imagine::Color parachuteColor = Imagine::RED;

const int trooperSpeedWithParachute = (int)(windowHeight/300);
const int trooperSpeedWithoutParachute = (int) (windowHeight/150);
const int trooperSpeedWalking = (int)(windowWidth/400);

/// Margins
const int minHeightParachute = (int) (windowHeight/2), maxHeightParachute = (int) (2*windowHeight/3);
const int shieldMargin = boxWidth + (int)(13*windowWidth/80);


/// For the images

const int skullTimeOfDisplay = 50;//fixed, does not depend on the screen dimensions


/// For the score
//do not depend on the dimensions
const int points_body_touched = 5;
const int points_parachute_touched = 3;
const int points_bullet_used = -1;
const int points_plane_touched = 10;

#endif
