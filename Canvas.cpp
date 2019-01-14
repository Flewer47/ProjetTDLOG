#include "Canvas.h"


Canvas::Canvas()
{
    window = Imagine::openWindow(windowWidth, windowHeight, windowTitle);
    Imagine::setBackGround(windowBackgroundColor);
}

void Canvas::closeCanvas() const{
    Imagine::closeWindow(window);
}

void Canvas::startMenu(int& mode){
    int x=0, y=0;

    Imagine::Image<Imagine::AlphaColor> title;
    load(title, srcPath("Images/Title.png"));
    Imagine::display(title, 100, 50);           // Title

    Imagine::Image<Imagine::AlphaColor> start;
    load(start, srcPath("Images/start.png"));
    Imagine::display(start, 300, 250);           // Start

    Imagine::drawString(335, 380, "TUTORIAL", Imagine::WHITE, 20);
    Imagine::drawString(235, 420, "Use the arrows to move the cannon.", Imagine::CYAN, 16);
    Imagine::drawString(335, 443, "Use Z to fire.", Imagine::CYAN, 16);
                                                 // Tutorial

    Imagine::Image<Imagine::AlphaColor> quit;
    load(quit, srcPath("Images/quit.png"));
    Imagine::display(quit, 300, 500);             // Quit

    load(start, srcPath("Images/start_clicked.png"));
    load(quit, srcPath("Images/quit_clicked.png"));

    while(mode==0){
        Imagine::getMouse(x,y);
        Imagine::milliSleep(10);
        if ((300<=x) && (x<=500) && (250<=y) && (y<=300)){
            mode=1;
            Imagine::fillRect(300, 250, 200, 50, windowBackgroundColor);
            Imagine::display(start, 300, 250);
            Imagine::milliSleep(80);
        }
        else if ((300<=x) && (x<=500) && (500<=y) && (y<=550)){
            mode=3;
            Imagine::fillRect(300, 500, 200, 50, windowBackgroundColor);
            Imagine::display(quit, 300, 500);
            Imagine::milliSleep(80);
        }
    }
    Imagine::fillRect(0,0,windowWidth,windowHeight,windowBackgroundColor);
}

void Canvas::gameOverScreen(int &mode, int &player_lives, int score){


    bool gameOver = true;

    Imagine::fillRect(200, 200, 400, 350, Imagine::WHITE);
    Imagine::fillRect(210, 210, 380, 330, Imagine::BLACK);

    Imagine::drawString(300, 250, "The Cannon is down !", Imagine::CYAN, 16);
    Imagine::drawString(320, 450, "YOU LOSE", Imagine::WHITE, 30);

    Imagine::Image<Imagine::AlphaColor> start;
    load(start, srcPath("Images/start.png"));
    Imagine::display(start, 300, 275);           // Start

    Imagine::Image<Imagine::AlphaColor> quit;
    load(quit, srcPath("Images/quit.png"));
    Imagine::display(quit, 300, 475);             // Quit


    Imagine::drawString(350, 400, "Score :", Imagine::WHITE, 12);
    Imagine::drawString(400, 400, std::to_string(score), Imagine::WHITE, 20);

    load(start, srcPath("Images/start_clicked.png"));
    load(quit, srcPath("Images/quit_clicked.png"));

    while(gameOver){
        int x,y;
        Imagine::getMouse(x,y);
        Imagine::milliSleep(10);
        if ((300<=x) && (x<=500) && (275<=y) && (y<=325)){
            mode=1;
            Imagine::fillRect(300, 275, 200, 50, windowBackgroundColor);
            Imagine::display(start, 300, 275);
            Imagine::milliSleep(80);
            gameOver = false;
        }
        else if ((300<=x) && (x<=500) && (475<=y) && (y<=525)){
            mode=3;
            Imagine::fillRect(300, 475, 200, 50, windowBackgroundColor);
            Imagine::display(quit, 300, 475);
            Imagine::milliSleep(80);
            gameOver = false;
        }
    }
}
