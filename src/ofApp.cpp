#include "ofApp.h"


//--------------------------------------------------------------
void labyrinthGame::setup(){
	title_img = ImageLoad::getTitleScreenImage();
	player_img = ImageLoad::getPlayerImage();
	gamefont_.load("8-BIT WONDER.ttf", 15);
	rooms_ = std::vector<Room>();
	player_ = Player();
	player_.setImage(&player_img);
	win_coordinate_ = randomMapPos();
	rooms_.push_back(generateStartRoom());
	current_room_ = &rooms_[0];
	current_room_->addPlayer(&player_);
	ofSetFrameRate(60);
	ofSetBackgroundColor(0, 0, 0);
}

//--------------------------------------------------------------
void labyrinthGame::update(){
	if (current_state_ == IN_PROGRESS) {
		current_room_->update();
	}
	if (player_.getHealthFraction() <= 0 && player_mode_ == NORMAL_MODE) {
		current_state_ = DEATH;
	}
}

//--------------------------------------------------------------
void labyrinthGame::draw(){
	if (current_state_ == START) {
		title_img.draw(0, 0);
	}
	if (current_state_ == IN_PROGRESS) {
		current_room_->drawRoom();
		drawHUD();
	}
	if (current_state_ == MAP) {
		drawMap();
	}
	if (current_state_ == DEATH) {
		//Prints three death messages vertically stacked, at the given coordinates
		gamefont_.drawString(DEATH_MESSAGE, 900, 540);
		gamefont_.drawString(RESTART_MESSAGE, 775, 600);
		gamefont_.drawString(ESCAPE_MESSAGE, 840, 630);
	}
	if (current_state_ == WIN) {
		//Prints three win messages vertically stacked, at the given coordinates
		gamefont_.drawString(WIN_MESSAGE, 840, 540);
		gamefont_.drawString(RESTART_MESSAGE, 775, 600);
		gamefont_.drawString(ESCAPE_MESSAGE, 840, 630);
	}
}

//--------------------------------------------------------------
void labyrinthGame::keyPressed(int key){
	int upper_key = toupper(key);
	if (upper_key == ' ') {
		if (current_state_ == START) {
			current_state_ = IN_PROGRESS;
		}
		if ((current_state_ == DEATH) || (current_state_ == WIN)) {
			reset();
		}
	}
	if (upper_key == 'W') {
		player_.setDirUp(true);
	}
	if (upper_key == 'A') {
		player_.setDirLeft(true);
	}
	if (upper_key == 'S') {
		player_.setDirDown(true);
	}
	if (upper_key == 'D') {
		player_.setDirRight(true);
	}
	if (upper_key == OF_KEY_UP) {
		current_room_->playerShoot(ofVec2f(0,-1));
	}
	if (upper_key == OF_KEY_DOWN) {
		current_room_->playerShoot(ofVec2f(0, 1));
	}
	if (upper_key == OF_KEY_LEFT) {
		current_room_->playerShoot(ofVec2f(-1, 0));
	}
	if (upper_key == OF_KEY_RIGHT) {
		current_room_->playerShoot(ofVec2f(1, 0));;
	}
	if (upper_key == OF_KEY_F11) {
		ofToggleFullscreen();
		return;
	}
	if (upper_key == 'M') {
		current_state_ = MAP;
	}
	if (upper_key == 'E') {
		if (current_room_->interactDoor() != -1 && (current_room_->getMonsters().size() <= 0 || player_mode_ == PRESENTATION_MODE)) {
			changeRooms(current_room_->interactDoor());
		}
		else {
			current_room_->pickUp();
		}
	}
	if (upper_key == 'K') {
		ofToggleFullscreen();
	}
	if (upper_key == 'P') {
		player_mode_ = PRESENTATION_MODE;
	}
	if (upper_key == 'O') {
		player_mode_ = NORMAL_MODE;
	}
}

//--------------------------------------------------------------
void labyrinthGame::keyReleased(int key){
	int upper_key = toupper(key);

	if (upper_key == 'W') {
		player_.setDirUp(false);
	}
	if (upper_key == 'A') {
		player_.setDirLeft(false);
	}
	if (upper_key == 'S') {
		player_.setDirDown(false);
	}
	if (upper_key == 'D') {
		player_.setDirRight(false);
	}
	if (upper_key == 'M') {
		current_state_ = IN_PROGRESS;
	}
}

void labyrinthGame::reset() {
	rooms_.clear();
	player_img = ImageLoad::getPlayerImage();
	player_ = Player();
	player_.setImage(&player_img);
	rooms_.push_back(generateStartRoom());
	win_coordinate_ = randomMapPos();
	current_room_ = &rooms_[0];
	current_room_->addPlayer(&player_);
	current_state_ = IN_PROGRESS;
	player_mode_ = NORMAL_MODE;
}

void labyrinthGame::changeRooms(int i) {
	ofVec2f next_coordinates;
	if (i == 0) {
		next_coordinates = current_room_->getMapCoordinate() + ofVec2f(0, 1);
	}
	if (i == 1) {
		next_coordinates = current_room_->getMapCoordinate() + ofVec2f(1,0);
	}
	if (i == 2) {
		next_coordinates = current_room_->getMapCoordinate() + ofVec2f(0,-1);
	}
	if (i == 3) {
		next_coordinates = current_room_->getMapCoordinate() + ofVec2f(-1,0);
	}
	current_room_->removePlayer();
	int room_index = roomExists(next_coordinates);
	if ( room_index != -1) {
		current_room_ = &rooms_[room_index];
	}
	else {
		if (willBeBossRoom()) {
			rooms_.push_back(generateBossRoom(next_coordinates));
		}
		else {
			rooms_.push_back(generateRoom(next_coordinates));
		}
		current_room_ = &rooms_[rooms_.size() - 1];
	}
	current_room_->addPlayer(&player_);
	player_.setPlayerPos(current_room_->getNewPlayerPos(i));
	if (current_room_->getMapCoordinate() == win_coordinate_) {
		current_state_ = WIN;
	}
}

void labyrinthGame::drawMap() {
	for (int i = 0; i < rooms_.size(); i++) {
		int x_coord = ofGetWindowWidth() / 2 + rooms_[i].getMapCoordinate().x * 50;
		int y_coord = ofGetWindowHeight() / 2 - rooms_[i].getMapCoordinate().y * 50;
		rooms_[i].getImage().draw(x_coord, y_coord, 45, 45);
		if (rooms_[i].getWeapons().size() != 0) {
			rooms_[i].getWeapons()[0].getImage().draw(x_coord, y_coord, 45, 45); //draws the first weapon in the room array over the room on the map
		}
		if (rooms_[i].hasPlayer()) {
			player_img.draw(x_coord, y_coord, 45, 45); // draws the player image in the current room
		}
	}
}

void labyrinthGame::drawHUD() {
	gamefont_.drawString(MAP_MESSAGE, 30, 120);
	gamefont_.drawString(ESCAPE_MESSAGE, 30, 150);
	ofSetColor(255, 255, 255);
	std::string current_coordinate = "(" + to_string(current_room_->getMapCoordinate().x) + ", " + to_string(current_room_->getMapCoordinate().y) + ")";
	std::string win_coordinate = "(" + to_string(win_coordinate_.x) + ", " + to_string(win_coordinate_.y) + ")";
	ofDrawBitmapString(current_coordinate, 10, 10);
	ofDrawBitmapString(win_coordinate, 10, 30);
	if (player_.hasWeapon()) {
		drawBulletHUD();
		drawWeaponHUD();
	}
	drawPlayerHealthHUD();
	drawMonsterHealthHUD();
}

void labyrinthGame::drawBulletHUD() {
	int bullets_left = player_.getWeapon().getBulletMax() - current_room_->playerBulletsInRoom();
	Bullet player_bullet = player_.getWeapon().getBullet();
	gamefont_.drawString("*" + to_string(bullets_left), 1830, 40); //Placing number of bullets left at (1840, 40)
	int shift = 50; //Initial Y coordinate first bullet is drawn at
	for (int i = 0; i < bullets_left; i++) {
		if (shift < 1000) {
			player_bullet.getImage().draw(1800, shift, player_bullet.getSize(), player_bullet.getSize()); //Drawing the bullet images, starting at (1800, 50) and dynamically spacing with bullet size + 5 to Y.
			shift += player_bullet.getSize() + 5;
		}
		else {
			player_bullet.getImage().draw(1850, shift - 950, player_bullet.getSize(), player_bullet.getSize());
			shift += player_bullet.getSize() + 5;
		}
	}
}

void labyrinthGame::drawWeaponHUD() {
	gamefont_.drawString(WEAPON_MESSAGE, 1600, 120); //Placing message at (1600,120)
	player_.getWeapon().getImage().draw(1615, 140); //Placing weapon image at (1615, 140)
	gamefont_.drawString(DAMAGE_MESSAGE, 1600, 300); //Placing message at (1600,300)
	gamefont_.drawString(to_string(player_.getWeapon().getBullet().getBulletDamage()), 1650, 330); //Placing damage of current weapon at (1650, 330)
	gamefont_.drawString(SPEED_MESSAGE, 1615, 400); //Placing message at (1615,400)
	gamefont_.drawString(to_string(player_.getWeapon().getBullet().getBulletSpeed()), 1650, 430); //Placing speed of current weapon at(1650, 430)
}

void labyrinthGame::drawPlayerHealthHUD() {
	int bar_length = player_.getHealthFraction() * HEALTH_BAR_LENGTH;
	gamefont_.drawString(PLAYER_MESSAGE, 40, 300); //Placing message at (40,300)
	if (bar_length > 0) {
		ofSetColor(255, 0, 0);
		ofDrawRectangle(40, 320, bar_length, 20); //draw dynamically scaling health bar at (40,320)
		ofSetColor(255, 255, 255);
	}
	if (bar_length == HEALTH_BAR_LENGTH) {
		gamefont_.drawString(FULL_BAR_MESSAGE, 100, 338); //Placing message at (100,338)
	}
}

void labyrinthGame::drawMonsterHealthHUD() {
	int bar_length = current_room_->getMonstersHealthFraction()* HEALTH_BAR_LENGTH;
	gamefont_.drawString(MONSTER_MESSAGE, 40, 400); //Placing message at (40,400)
	if (bar_length > 0) {
		ofSetColor(255,0,255);
		ofDrawRectangle(40, 420, bar_length, 20); //draw dynamically scaling health bar at (40,420)
		ofSetColor(255, 255, 255);
	}
}

int labyrinthGame::roomExists(ofVec2f coordinate) {
	for (int i = 0; i < rooms_.size(); i++) {
		if (rooms_[i].getMapCoordinate() == coordinate) {
			return i;
		}
	}
	return -1;
}
