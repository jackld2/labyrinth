#include "Room.h"

Room::Room() {
	active_bullets_ = std::vector<Bullet>();
	monster_bullets_ = std::vector<Bullet>();
	room_weapons_ = std::vector<Weapon>();
	monsters_ = std::vector<Monster>();
	max_monsters_health = 0;
	player_ = nullptr;
	origin_ = ofVec2f((ofGetWindowWidth() / 2) - (WIDTH / 2), (ofGetWindowHeight() / 2) - (HEIGHT / 2));
	placeDoors();
	map_coordinate_ = ofVec2f(0, 0);
}

Room::~Room() {
}

void Room::addPlayer(Player *player) {
	player_ = player;
}

void Room::removePlayer() {
	player_ = nullptr;
}

void Room::pickUp() {
	int weapon_index = interactWeapon();
	if (player_->hasWeapon()) {
		Weapon dropped = player_->dropWeapon();
		dropped.setPosition(player_->getPlayerPos());
		room_weapons_.push_back(dropped);
	}
	if (weapon_index != -1) {
		player_->setWeapon(room_weapons_[weapon_index]);
		room_weapons_.erase(room_weapons_.begin() + weapon_index);
	}
				
}

int Room::interactDoor() {
	if (isLeavingUp()) { return 0; }
	if (isLeavingRight()) { return 1; }
	if (isLeavingDown()) { return 2; }
	if (isLeavingLeft()) { return 3; }
	return -1;
}

int Room::interactWeapon() {
	for (int i = 0; i < room_weapons_.size(); i++) {
		if (player_->getPlayerPos().distance(room_weapons_[i].getPosition()) < 100) {
			return i;
		}
	}
	return -1;
}

void Room::drawRoom() {
	room_image_.draw(origin_.x - 88, origin_.y - 88);
	for (auto weapon : room_weapons_) {
		weapon.draw();
	}
	for (auto bullet : active_bullets_) {
		bullet.draw();
	}
	drawMonsterBullets();
	for (auto monster : monsters_) {
		monster.draw();
	}
	player_->draw();
	drawDoors();
	
}

void Room::drawDoors() {
	up_door.draw();
	down_door.draw();
	left_door.draw();
	right_door.draw();

}

void Room::setImage(ofImage image) {
	room_image_ = image;
}

ofImage Room::getImage() {
	return room_image_;
}

void Room::setMapCoordinate(ofVec2f coordinate) {
	map_coordinate_ = coordinate;
}

ofVec2f Room::getMapCoordinate() {
	return map_coordinate_;
}

bool Room::hasPlayer() {
	return player_;
}

void Room::putWeapon(Weapon weapon) {
	room_weapons_.push_back(weapon);
}

std::vector<Weapon> Room::getWeapons() {
	return room_weapons_;
}

void Room::placeDoors() {

	ofImage door_image;
	door_image.load("door.png");

	up_door = Door(0);
	up_door.setImage(door_image);
	up_door.setPosition(ofVec2f(origin_.x + WIDTH / 2, origin_.y - DOOR_SHIFT));

	right_door = Door(1);
	right_door.setImage(door_image);
	right_door.setPosition(ofVec2f(origin_.x + WIDTH + DOOR_SHIFT, origin_.y + HEIGHT / 2));

	down_door = Door(2);
	down_door.setImage(door_image);
	down_door.setPosition(ofVec2f(origin_.x + WIDTH / 2, origin_.y + HEIGHT + DOOR_SHIFT));

	left_door = Door(3);
	left_door.setImage(door_image);
	left_door.setPosition(ofVec2f(origin_.x - DOOR_SHIFT, origin_.y + HEIGHT / 2));
}


Weapon Room::takeWeapon() {
	return Weapon();
}

void Room::update() {
	updatePlayer();
	updateMonsters();
	updatePlayerBullets();
	updateMonsterBullets();
	updatePlayerHits();
	updateMonsterHits();
}

void Room::updatePlayer() {
	player_->updateCardinal();
	if (upIsValid(player_->getPlayerPos(), player_->getHeight())) {
		player_->updateUp();
	}
	if (downIsValid(player_->getPlayerPos(), player_->getHeight())) {
		player_->updateDown();
	}
	if (leftIsValid(player_->getPlayerPos(), player_->getHeight())) {
		player_->updateLeft();
	}
	if (rightIsValid(player_->getPlayerPos(), player_->getHeight())) {
		player_->updateRight();
	}
}

void Room::updatePlayerBullets() {
	if (!active_bullets_.empty()) {
		for (int i = 0; i < active_bullets_.size(); i++) {
			active_bullets_[i].bulletUpdate();
			if (!bulletIsInbounds(active_bullets_[i])) {
				active_bullets_.erase(active_bullets_.begin() + i);
			}
		}
	}
}

void Room::updatePlayerHits() {
	int bullet_index = -1;
	for (int i = 0; i < monster_bullets_.size(); i++) {
		if (player_->getPlayerPos().distance(monster_bullets_[i].getBulletPos()) < (player_->getHeight() / 3) + (monster_bullets_[i].getSize() / 2)) {
			player_->removeHealth(monster_bullets_[i].getBulletDamage());
			bullet_index = i;
		}
	}
	if (bullet_index != -1) {
		monster_bullets_.erase(monster_bullets_.begin() + bullet_index);
	}
}

void Room::playerShoot(ofVec2f direction) {
	if (player_->hasWeapon() && (player_->getWeapon().getBulletMax() > active_bullets_.size())) {
		Bullet bullet = Bullet(player_->getWeapon().getBullet());
		bullet.setVectorDirection(direction);
		bullet.setMomentumVector(player_->getMomentumVector());
		bullet.setBulletPos(player_->getPlayerPos());
		active_bullets_.push_back(bullet);
	}
}

int Room::playerBulletsInRoom() {
	return active_bullets_.size();
}

ofVec2f Room::getNewPlayerPos(int cardinal) {
	if (cardinal == 0) {
		return ofVec2f(origin_.x + WIDTH / 2, origin_.y + HEIGHT + PLAYER_SHIFT);
	}
	if (cardinal == 1) {
		return ofVec2f(origin_.x - PLAYER_SHIFT, origin_.y + HEIGHT / 2);
	}
	if (cardinal == 2) {
		return ofVec2f(origin_.x + WIDTH / 2, origin_.y - PLAYER_SHIFT);
	}
	if (cardinal == 3) {
		return ofVec2f(origin_.x + WIDTH + PLAYER_SHIFT, origin_.y + HEIGHT / 2);
	}
	return ofVec2f();
}

bool Room::bulletIsInbounds(Bullet bullet) {
	if (bullet.getBulletPos().x >= origin_.x + WIDTH || bullet.getBulletPos().x <= origin_.x) {
		return false;
	}
	if (bullet.getBulletPos().y >= origin_.y + HEIGHT || bullet.getBulletPos().y <= origin_.y) {
		return false;
	}
	return true;
}

bool Room::upIsValid(ofVec2f position, int size) {
	return position.y - size / 2 > origin_.y;
}

bool Room::downIsValid(ofVec2f position, int size) {
	return position.y + size / 2 < origin_.y + HEIGHT;
}


bool Room::leftIsValid(ofVec2f position, int size) {
	return position.x - size / 2 > origin_.x;	
}

bool Room::rightIsValid(ofVec2f position, int size) {
	return position.x + size / 2 < origin_.x + WIDTH;
}

bool Room::isLeavingUp() {
	return player_->getPlayerPos().distance(up_door.getPosition()) < Door::DOOR_HEIGHT;
}

bool Room::isLeavingRight() {
	return player_->getPlayerPos().distance(right_door.getPosition()) < Door::DOOR_HEIGHT;
}

bool Room::isLeavingDown() {
	return player_->getPlayerPos().distance(down_door.getPosition()) < Door::DOOR_HEIGHT;
}

bool Room::isLeavingLeft() {
	return player_->getPlayerPos().distance(left_door.getPosition()) < Door::DOOR_HEIGHT;
}

void Room::putMonster(Monster monster) {
	monsters_.push_back(monster);
	max_monsters_health += monster.getMaxHealth();
}

int Room::isMonsterHit(Bullet bullet) {
	for (int i = 0; i < monsters_.size(); i++) {
		if (monsters_[i].getPosition().distance(bullet.getBulletPos()) < (monsters_[i].getWidth() / 2) + (bullet.getSize() / 2) ) {
			return i;
		}
	}
	return -1;
}

void Room::updateMonsterHits() {
	int bullet_index = -1;
	for (int i = 0; i < active_bullets_.size(); i++) {
		int monster_index = isMonsterHit(active_bullets_[i]);
		if ( monster_index != -1) {
			bullet_index = i;
			monsters_[monster_index].removeHealth(active_bullets_[i].getBulletDamage());
			if (monsters_[monster_index].getHealth() <= 0) {
				monsters_.erase(monsters_.begin() + monster_index);
			}
		}
	}
	if (bullet_index != -1) {
		active_bullets_.erase(active_bullets_.begin() + bullet_index);
	}
}

void Room::setMonsters(std::vector<Monster> monsters) {
	monsters_ = monsters;
	for (Monster monster : monsters) {
		max_monsters_health += monster.getMaxHealth();
	}
}

void Room::monsterShoot(Monster monster) {
	ofVec2f shoot_direction = (player_->getPlayerPos() - monster.getPosition()).getNormalized();
	Bullet bullet = Bullet(monster.getBullet());
	bullet.setVectorDirection(shoot_direction);
	bullet.setMomentumVector(monster.getMomentumVector());
	bullet.setBulletPos(monster.getPosition());
	monster_bullets_.push_back(bullet);
}

void Room::updateMonsters() {
	for (int i = 0; i < monsters_.size(); i++) {
		monsters_[i].updateCardinal();
		bool can_move_up = upIsValid(monsters_[i].getPosition(), monsters_[i].getHeight());
		bool can_move_down = downIsValid(monsters_[i].getPosition(), monsters_[i].getHeight());
		bool can_move_left = leftIsValid(monsters_[i].getPosition(), monsters_[i].getHeight());
		bool can_move_right = rightIsValid(monsters_[i].getPosition(), monsters_[i].getHeight());

		monsters_[i].resetLastMoveDistance();
		if (can_move_up) {
			monsters_[i].updateUp();
		}
		if (can_move_down) {
			monsters_[i].updateDown();
		}
		if (can_move_left) {
			monsters_[i].updateLeft();
		}
		if (can_move_right) {
			monsters_[i].updateRight();
		}
		if (monsters_[i].isFrozen()) {
			monsters_[i].setDirection(randomBool(), randomBool(), randomBool(), randomBool());
		}
		if (monsters_[i].shotIsReady()) {
			monsterShoot(monsters_[i]);
			monsters_[i].setDirection(randomBool(), randomBool(), randomBool(), randomBool());
		}
	}
}

void Room::updateMonster(Monster monster) {
	monster.updateCardinal();
	if (upIsValid(monster.getPosition(), monster.getHeight())) {
		monster.updateUp();
	}
	if (downIsValid(monster.getPosition(), monster.getHeight())) {
		monster.updateDown();
	}
	if (leftIsValid(monster.getPosition(), monster.getHeight())) {
		monster.updateLeft();
	}
	if (rightIsValid(monster.getPosition(), monster.getHeight())) {
		monster.updateRight();
	}
}

void Room::drawMonsterBullets() {
	for (auto bullet : monster_bullets_) {
		bullet.draw();
	}
}

void Room::updateMonsterBullets() {
	if (!monster_bullets_.empty()) {
		for (int i = 0; i < monster_bullets_.size(); i++) {
			monster_bullets_[i].bulletUpdate();
			if (!bulletIsInbounds(monster_bullets_[i])) {
				monster_bullets_.erase(monster_bullets_.begin() + i);
			}
		}
	}
}

double Room::getMonstersHealthFraction() {
	int current_health_total = 0;
	for (Monster monster : monsters_) {
		current_health_total += monster.getHealth();
	}
	return (double)current_health_total / max_monsters_health;
}

std::vector<Monster> Room::getMonsters() {
	return monsters_;
}








