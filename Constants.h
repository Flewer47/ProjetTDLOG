/// "Copyright 2019 BOUVIER-GATELLIER-GIRAUDON-SANTET"

#pragma once
#include <Imagine/Graphics.h>
#include <Imagine/Images.h>

/// For the canvas

// Relative positions only work if windowWidth > 800 and windowHeight > 600 !

const int windowWidth = 800, windowHeight = 600,  // Window dimensions
groundHeight = static_cast<int>(windowHeight/30);  // Line of the ground in the canvas
const Imagine::Color windowBackgroundColor = Imagine::BLACK;
const Imagine::Color groundColor = Imagine::BLUE;
const char windowTitle[] = "Paratroopers";  // Title of the game
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


// Fixed because of the picture
const int planeWidth = static_cast<int>(windowWidth/16);
const int planeHeight = 26;


const int dropMargin = static_cast<int>(windowWidth/10); // To not spawn a trooper on the edge of the screen
const int leftRightPlaneHeight = static_cast<int>(windowHeight/30); // Same height for every plane (for one direction)
const int rightLeftPlaneHeight = static_cast<int>(windowHeight*7/60);
const int planeVelocity = static_cast<int>(windowWidth*3/800); // Same speed for every plane
const Imagine::Color planeColor = Imagine::RED;


/// For the cannon


const int boxWidth = static_cast<int>(windowWidth/16),
boxHeight = static_cast<int>(windowHeight/20); // Dimensions of the box undearneath the cannon
const Imagine::Color boxColor = Imagine::WHITE;

const int cannonLength = static_cast<int>(windowHeight/20),
cannonWidth = static_cast<int>(windowHeight/100); // Dimensions of the cannon itself
// Do not depend on the dimensions of the window
const float cannonAngularVelocity = 0.32,
cannonAngleLimit = 0.9*M_PI/2, defaultCannonAngle = -M_PI/2;
const Imagine::Color cannonColor = Imagine::WHITE;



/// For the bullets

// Same characteristics for every bullet
const int bulletSpeed = static_cast<int>(windowHeight/60);
const int bulletSize = static_cast<int>(windowWidth/200);
const int shootFrequency = 5; // Can shoot a bullet every 5 frame at least


/// For the troopers

// Fixed because of the picture
const int trooperWidth = 21;
const int trooperHeight = 45; // Trooper dimensions
const Imagine::Color trooperColor = Imagine::RED;

// Fixed because of the picture
const int parachuteWidth = 100;
const int parachuteHeight = 100; // Parachute dimensions
const Imagine::Color parachuteColor = Imagine::RED;

// Different speeds for the paratrooper
const int trooperSpeedWithParachute = static_cast<int>(windowHeight/300);
const int trooperSpeedWithoutParachute = static_cast<int>(windowHeight/150);
const int trooperSpeedWalking = static_cast<int>(windowWidth/400);

/// Margins
const int minHeightParachute = static_cast<int>(windowHeight/2),
maxHeightParachute = static_cast<int>(2*windowHeight/3); // Define an interval where to deploy the parachute
const int shieldMargin = boxWidth + static_cast<int>(13*windowWidth/80); // Cannot spawn a trooper onto the cannon


/// For the images

// Fixed, does not depend on the screen dimensions
const int skullTimeOfDisplay = 50; // Letting the skull stay a bit (after a trooper being dead on the ground)


/// For the score
// Do not depend on the dimensions
const int points_body_touched = 5;
const int points_parachute_touched = 3;
const int points_bullet_used = -1;
const int points_plane_touched = 10;
