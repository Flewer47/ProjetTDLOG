/// "Copyright 2019 BOUVIER-GATELLIER-GIRAUDON-SANTET"

/**
 * @brief keyboard management function for the cannon and the shooting
 * @param direction -1 if it goes to the left, 1 if it goes to the right, 2 if the user shoots, 0 otherwise.
 */
void keyboard(int& direction) {
    static bool left = false, right = false, up = false;  // Directions, up for shooting
    Imagine::Event e;
    do {
        Imagine::getEvent(0, e);
        if (e.type == Imagine::EVT_KEY_ON || e.type == Imagine::EVT_KEY_OFF) {
            bool push = (e.type == Imagine::EVT_KEY_ON);  // Check if there is something going on
            switch (e.key) {
            case Imagine::KEY_LEFT :
                left = push;
                break;
            case Imagine::KEY_RIGHT :
                right = push;
                break;
            case 'z' :  // We use the 'z' key to shoot
                up = push;
                break;
            }
        }
    } while (e.type != Imagine::EVT_NONE);  // When there is a keyboard press
    direction = (up ? 2 : (left ? -1 : (right ? 1 : 0)));  // Direction updated
}

/**
 * @brief resetVariables : When reaching a game over and wanting to play another game,
 * reset any variable used for the game.
 * @param score
 * @param player_lives
 * @param bullets
 * @param troopers
 * @param planes
 */
void resetVariables(int &score, int &player_lives,
                    std::vector<Bullet> &bullets, std::vector<Trooper> &troopers,
                    std::vector<Plane> &planes) {
    score = 0;
    player_lives = 7;
    bullets.clear();
    troopers.clear();
    planes.clear();
}


/// Vector of bullets
std::vector<Bullet> bullets;

/// Vector of planes
std::vector<Plane> planes;

/// Vector of troopers
std::vector<Trooper> troopers;

/**
 * @brief handleBullets at every frame
 * @param player_score : get modified if a bullet is removed without touching an object
 */
void handleBullets(int & player_score) {
    // Update position of every bullet
    for (std::vector<Bullet>::iterator it = bullets.begin();
         it != bullets.end(); ++it) {
        (*it).updatePosition();
    }

    // Check to see if any bullet has to be removed
    for (std::vector<Bullet>::iterator it = bullets.end()-1;
         it != bullets.begin()-1; --it) {  // Need to go backward as we are removing
        if ((*it).getRemoveMe()) {
            player_score = player_score + points_bullet_used;
            bullets.erase(it);
        }
    }
}

/**
 * @brief moveCannon at every frame
 * @param direction : where the cannon is moving, info got from keyboard function
 * @param count : constraint on the shoot frequency (shooting every 5 frames at least)
 * @param cannon : player
 */
void moveCannon(const int& direction, int &count, Cannon &cannon) {
    cannon.updatePosition(direction);
    count = shootFrequency;
}

/**
 * @brief shoot a bullet
 * @param count : constraint on the shoot frequency (shooting every 5 frames at least)
 * @param cannon : player
 * @param bullets : bullets existing at the frame
 */
void shoot(int &count, const Cannon& cannon, std::vector<Bullet> &bullets) {
    if (count == shootFrequency || count == 0) {  // We can actually shoot
        bullets.push_back(Bullet(cannon.getAngle()));
        if (count == 0) {
            count = shootFrequency;
        }
    }
    count--;  // One frame has passed
}

/**
 * @brief handleCannon at every frame
 * @param direction : where the cannon is moving, info got from keyboard function
 * @param count : constraint on the shoot frequency (shooting every 5 frames at least)
 * @param cannon : player
 * @param bullets : bullets existing at the frame
 */
void handleCannon(int& direction, int& count, Cannon &cannon,
                  std::vector<Bullet> &bullets) {
    keyboard(direction);
    if (direction != 2) {  // Moving the cannon
        moveCannon(direction, count, cannon);
    } else {  // Shooting
        shoot(count, cannon, bullets);
    }
}

/**
 * @brief handlePlanes at every frame
 * @param player_score
 */
void handlePlanes(int & player_score) {
    // Check if we need to remove a plane
    for (std::vector<Plane>::iterator it = planes.end()-1;
         it != planes.begin()-1; it--) {
        if ((*it).getRemoveMe()) {
            if ((*it).isTouched()) {  // If a plane has been shot
                player_score = player_score + points_plane_touched;
            }
            planes.erase(it);
        }
    }

    // Update position of every plane
    for (std::vector<Plane>::iterator it = planes.begin();
         it != planes.end(); it++) {
        (*it).updatePosition();
        if ((*it).getIsSpawningTrooper()) {
            troopers.push_back(Trooper((*it).getPlaneX(), (*it).getPlaneY()));
        }
    }
}

/**
 * @brief handleTroopers at every frame
 * @param player_lives
 * @param player_score
 */
void handleTroopers(int & player_lives, int & player_score) {
    for (std::vector<Trooper>::iterator it = troopers.end()-1;
         it != troopers.begin()-1; --it) {
        if ((*it).getRemoveMe()) {
            if ((*it).hascameinBase()) {  // A trooper has reached the base
                player_lives -= 1;
            } else if ((*it).isbodyTouched()) {  // A trooper has been bodyshot
                player_score = player_score + points_body_touched;
            } else if ((*it).isparachuteTouched()) {  // A parachute has been shot
                player_score = player_score + points_parachute_touched;
            }
            troopers.erase(it);
        }
    }

    // Update position of every trooper
    for (std::vector<Trooper>::iterator it = troopers.begin();
         it != troopers.end(); ++it) {
        (*it).updatePosition();
    }
}

/**
 * @brief handleHitboxes at every frame.
 * For every bullet, check if it has hit a trooper or a plane
 */
void handleHitboxes() {
    for (std::vector<Bullet>::iterator it_bull = bullets.begin();
         it_bull !=bullets.end(); it_bull++) {
        for (std::vector<Trooper>::iterator it_troop = troopers.begin();
             it_troop !=troopers.end(); it_troop++) {
            (*it_troop).updateIfTouched((*it_bull));
        }
        for (std::vector<Plane>::iterator it_plane = planes.begin();
             it_plane !=planes.end(); it_plane++) {
            (*it_plane).updateIfTouched((*it_bull));
        }
    }
}
