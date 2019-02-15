/// "Copyright 2019 BOUVIER-GATELLIER-GIRAUDON-SANTET"

#include "./Canvas.h"
#include "./Constants.h"

Canvas::Canvas() {
    //Defines the properties of the canvas

    window = Imagine::openWindow(windowWidth, windowHeight, windowTitle);
    Imagine::setBackGround(windowBackgroundColor);
}

void Canvas::closeCanvas() const {
    //Closes the canvas
    //Called at the end of game

    Imagine::closeWindow(window);
}

void Canvas::startMenu(int& mode) {
    //Creates the start menu (buttons, tutorial, title...)
    Imagine::IntPoint2 p;

    Imagine::Image<Imagine::AlphaColor> title;
    load(title, srcPath("Images/Title.png"));
    Imagine::display(title, pos_Title.x(), pos_Title.y());           // Title

    Imagine::Image<Imagine::AlphaColor> start;
    load(start, srcPath("Images/start.png"));
    Imagine::display(start, pos_Start.x(), pos_Start.y());           // Start

    Imagine::drawString(pos_TUTORIAL, "TUTORIAL", Imagine::WHITE, 20);
    Imagine::drawString(pos_Tuto1, "Use the arrows to move the cannon.",
Imagine::CYAN, 16);
    Imagine::drawString(pos_Tuto2, "Use Z to fire.", Imagine::CYAN, 16);
                                                 // Tutorial

    Imagine::Image<Imagine::AlphaColor> quit;
    load(quit, srcPath("Images/quit.png"));
    Imagine::display(quit, pos_Quit.x(), pos_Quit.y());             // Quit

    load(start, srcPath("Images/start_clicked.png"));
    load(quit, srcPath("Images/quit_clicked.png"));     // Changes color of the buttons when clicked

    while (mode == 0) {
        Imagine::getMouse(p);
        Imagine::milliSleep(10);
        if (isInRect(pos_Start, size_Button, p)) {
            //Starting the game
            mode = 1;
            Imagine::fillRect(pos_Start, size_Button.x(),
size_Button.y(), windowBackgroundColor);
            Imagine::display(start, pos_Start.x(), pos_Start.y());
            Imagine::milliSleep(click_Inertia);
        } else if (isInRect(pos_Quit, size_Button, p)) {
            //Exiting the application
            mode = 3;
            Imagine::fillRect(pos_Quit, size_Button.x(), size_Button.y(),
windowBackgroundColor);
            Imagine::display(quit, pos_Quit.x(), pos_Quit.y());
            Imagine::milliSleep(click_Inertia);
        }
    }
    Imagine::fillRect(0, 0, windowWidth, windowHeight,
windowBackgroundColor);
}

void Canvas::gameOverScreen(int &mode, int &player_lives, int score) {
    //Builds the Game Over Screen (Replay or Quit, print the score)
    bool gameOver = true;

    Imagine::fillRect(pos_WhiteRectGO, size_WhiteRectGO.x(),
size_WhiteRectGO.y(), Imagine::WHITE);
    Imagine::fillRect(pos_WhiteRectGO.x() + width_WhiteRectGo,
                      pos_WhiteRectGO.y() + width_WhiteRectGo,
                      size_WhiteRectGO.x() - 2 * width_WhiteRectGo,
                      size_WhiteRectGO.y() - 2 * width_WhiteRectGo,
Imagine::BLACK);

    //Print some text
    Imagine::drawString(pos_txtGO, "The Cannon is down !", Imagine::CYAN,
16);
    Imagine::drawString(pos_YOULOSE, "YOU LOSE", Imagine::WHITE, 30);

    Imagine::Image<Imagine::AlphaColor> start;
    load(start, srcPath("Images/start.png"));
    // Start Button
    Imagine::display(start, pos_Start_GO.x(),
pos_Start_GO.y());

    Imagine::Image<Imagine::AlphaColor> quit;
    load(quit, srcPath("Images/quit.png"));
    // Quit Button
    Imagine::display(quit, pos_Quit_GO.x(), pos_Quit_GO.y());


    //Print the score
    Imagine::drawString(pos_ScoreTXT_GO, "Score :", Imagine::WHITE, 12);
    Imagine::drawString(pos_ScoreVAR_GO, std::to_string(score),
Imagine::WHITE, 20);

    load(start, srcPath("Images/start_clicked.png"));
    load(quit, srcPath("Images/quit_clicked.png")); // Clicking mecanism

    while (gameOver) {
        Imagine::IntPoint2 p;
        Imagine::getMouse(p);
        Imagine::milliSleep(10);
        if (isInRect(pos_Start_GO, size_Button, p)) {
            mode = 1;
            Imagine::fillRect(pos_Start_GO, size_Button.x(),
size_Button.y(), windowBackgroundColor);
            Imagine::display(start, pos_Start_GO.x(), pos_Start_GO.y());
            Imagine::milliSleep(click_Inertia);
            gameOver = false;
        } else if (isInRect(pos_Quit_GO, size_Button, p)) {
            mode = 3;
            Imagine::fillRect(pos_Quit_GO, size_Button.x(),
size_Button.y(), windowBackgroundColor);
            Imagine::display(quit, pos_Quit_GO.x(), pos_Quit_GO.y());
            Imagine::milliSleep(click_Inertia);
            gameOver = false;
        }
    }
}

bool isInRect(Imagine::IntPoint2 pos, Imagine::IntPoint2 size,
Imagine::IntPoint2 pt) {
    // Checks if a point is contain in a rectangle
    // Useful when it comes to checking whether or not a button has been clicked
    return((pos.x() <= pt.x()) && (pt.x() <= pos.x()+size.x()) &&
           (pos.y() <= pt.y()) && (pt.y() <= pos.y()+size.y()));
}
