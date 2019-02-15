#ifndef MYLIB_CONSTANTS_H
#define MYLIB_CONSTANTS_H

#include <Imagine/Graphics.h>
#include <Imagine/Images.h>

/// For the canvas

// Relative positions only work if windowWidth > 800 and windowHeight > 600 !

const int windowWidth = 800, windowHeight = 600, groundHeight = (int)(windowHeight/30);
const Imagine::Color windowBackgroundColor = Imagine::BLACK;
const Imagine::Color groundColor = Imagine::BLUE;
const std::string windowTitle = "Paratroopers";
const int click_Inertia = 80;


const Imagine::IntPoint2 size_Title = Imagine::IntPoint2(600, 150); // fixed
const Imagine::IntPoint2 pos_Title = Imagine::IntPoint2((windowWidth-size_Title.x())/2, windowHeight/12);

const Imagine::IntPoint2 size_Button = Imagine::IntPoint2(200, 50); // fixed
const Imagine::IntPoint2 pos_Start = Imagine::IntPoint2((int)((windowWidth-size_Button.x())/2), (int)(windowHeight/2.4));
const Imagine::IntPoint2 pos_TUTORIAL = Imagine::IntPoint2((int)(windowWidth/2.4), (int)(windowHeight/1.6));
const Imagine::IntPoint2 pos_Tuto1 = Imagine::IntPoint2((int)(windowWidth/3.5), (int)(windowHeight/1.4));
const Imagine::IntPoint2 pos_Tuto2 = Imagine::IntPoint2((int)(windowWidth/2.4), (int)(windowHeight/1.3));
const Imagine::IntPoint2 pos_Quit = Imagine::IntPoint2((int)((windowWidth-size_Button.x())/2), (int)(windowHeight/1.2));

const Imagine::IntPoint2 size_WhiteRectGO = Imagine::IntPoint2(400, 350); // fixed
const Imagine::IntPoint2 pos_WhiteRectGO = Imagine::IntPoint2((int)((windowWidth-size_WhiteRectGO.x())/2),
                                                              (int)((windowWidth-size_WhiteRectGO.y())/2));
const int width_WhiteRectGo = 10; // Do not exceed 40 * size_WhiteRectGO.x()

const Imagine::IntPoint2 pos_txtGO = Imagine::IntPoint2((int)(windowWidth/2-100), (int)(windowHeight/2.35));
const Imagine::IntPoint2 pos_YOULOSE = Imagine::IntPoint2((int)(windowWidth/2-90), (int)(windowHeight/1.4));
const Imagine::IntPoint2 pos_Start_GO = Imagine::IntPoint2((int)(windowWidth/2-size_Button.x()/2), (int)(windowHeight/2.2));
const Imagine::IntPoint2 pos_Quit_GO = Imagine::IntPoint2((int)(windowWidth/2-size_Button.x()/2), (int)(windowHeight/1.3));
const Imagine::IntPoint2 pos_ScoreTXT_GO = Imagine::IntPoint2((int)(windowWidth/2-40), (int)(windowHeight/1.6));
const Imagine::IntPoint2 pos_ScoreVAR_GO = Imagine::IntPoint2((int)(windowWidth/2+10), (int)(windowHeight/1.6));


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
