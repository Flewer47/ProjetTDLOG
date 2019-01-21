/// "Copyright 2019 BOUVIER-GATELLIER-GIRAUDON-SANTET"

#pragma once
#include <Imagine/Graphics.h>
#include <Imagine/Images.h>

/// For the canvas

const int windowWidth = 800, windowHeight = 600,
groundHeight = static_cast<int>(windowHeight/30);
const Imagine::Color windowBackgroundColor = Imagine::BLACK;
const Imagine::Color groundColor = Imagine::BLUE;
const char windowTitle[] = "Paratroopers";


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


// Fixed because of the picture
const int planeWidth = static_cast<int>(windowWidth/16);
const int planeHeight = 26;


const int dropMargin = static_cast<int>(windowWidth/10);
const int leftRightPlaneHeight = static_cast<int>(windowHeight/30);
const int rightLeftPlaneHeight = static_cast<int>(windowHeight*7/60);
const int planeVelocity = static_cast<int>(windowWidth*3/800);
const Imagine::Color planeColor = Imagine::RED;


/// For the cannon


const int boxWidth = static_cast<int>(windowWidth/16),
boxHeight = static_cast<int>(windowHeight/20);
const Imagine::Color boxColor = Imagine::WHITE;

const int cannonLength = static_cast<int>(windowHeight/20),
cannonWidth = static_cast<int>(windowHeight/100);
// Do not depend on the dimensions of the window
const float cannonAngularVelocity = 0.32,
cannonAngleLimit = M_PI/2, defaultCannonAngle = -M_PI/2;
const Imagine::Color cannonColor = Imagine::WHITE;



/// For the bullets


const int bulletSpeed = static_cast<int>(windowHeight/60);

const int bulletSize = static_cast<int>(windowWidth/200);

const int shootFrequency = 5;


/// For the troopers

// Fixed because of the picture
const int trooperWidth = 21;
const int trooperHeight = 45;
const Imagine::Color trooperColor = Imagine::RED;

// Fixed because of the picture
const int parachuteWidth = 100;
const int parachuteHeight = 100;
const Imagine::Color parachuteColor = Imagine::RED;

const int trooperSpeedWithParachute = static_cast<int>(windowHeight/300);
const int trooperSpeedWithoutParachute = static_cast<int>(windowHeight/150);
const int trooperSpeedWalking = static_cast<int>(windowWidth/400);

/// Margins
const int minHeightParachute = static_cast<int>(windowHeight/2),
maxHeightParachute = static_cast<int>(2*windowHeight/3);
const int shieldMargin = boxWidth + static_cast<int>(13*windowWidth/80);


/// For the images

// Fixed, does not depend on the screen dimensions
const int skullTimeOfDisplay = 50;


/// For the score
// Do not depend on the dimensions
const int points_body_touched = 5;
const int points_parachute_touched = 3;
const int points_bullet_used = -1;
const int points_plane_touched = 10;
