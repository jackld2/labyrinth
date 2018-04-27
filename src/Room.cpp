#include "Room.h"

Room::Room() {
	origin_ = ofVec2f(0, 0);
	active_bullets_ = std::vector<Bullet>();
	room_weapons_ = std::vector<Weapon>();
	player_ = nullptr;
	leave_up_ = false;
	leave_down_ = false;
	leave_left_ = false;
	leave_right_ = false;
	placeDoors();
}

Room::~Room() {
}

void Room::addPlayer(Player *player) {
	player_ = player;
}

Player* Room::removePlayer() {
	Player *temp = player_;
	player_ = nullptr;
	return temp;
}

void Room::drawRoom() {
	room_image_->draw(origin_.x - 88, origin_.y - 88);
	for (auto weapon : room_weapons_) {
		weapon.draw();
	}
	for (auto bullet : active_bullets_) {
		bullet.draw();
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

void Room::setImage(ofImage * image) {
	room_image_ = image;
}

bool Room::hasPlayer() {
	return player_;
}

void Room::putWeapon(Weapon weapon) {
	room_weapons_.push_back(weapon);
}

void Room::placeDoors() {

	ofImage door_image;
	door_image.load("door.png");

	up_door = Door(0);
	up_door.setImage(door_image);
	up_door.setPosition(ofVec2f(origin_.x + width_ / 2, origin_.y - DOOR_SHIFT));

	right_door = Door(1);
	right_door.setImage(door_image);
	right_door.setPosition(ofVec2f(origin_.x + width_ + DOOR_SHIFT, origin_.y + height_ / 2));

	down_door = Door(2);
	down_door.setImage(door_image);
	down_door.setPosition(ofVec2f(origin_.x + width_ / 2, origin_.y + height_ + DOOR_SHIFT));

	left_door = Door(3);
	left_door.setImage(door_image);
	left_door.setPosition(ofVec2f(origin_.x - DOOR_SHIFT, origin_.y + height_ / 2));
}


Weapon Room::takeWeapon() {
	return Weapon();
}

void Room::resize() {
	
	origin_ = ofVec2f((ofGetWindowWidth() / 2) - (width_ / 2), (ofGetWindowHeight() / 2) - (height_ / 2));
	up_door.setPosition(up_door.getPosition() + origin_);
	down_door.setPosition(down_door.getPosition() + origin_);
	left_door.setPosition(left_door.getPosition() + origin_);
	right_door.setPosition(right_door.getPosition() + origin_);
	player_->setPlayerPos(player_->getPlayerPos() + origin_);
	for (int i = 0; i < active_bullets_.size(); i++) {
		active_bullets_[i].setBulletPos(active_bullets_[i].getBulletPos() + origin_);
	}
	
}

void Room::update() {
	if (!active_bullets_.empty()) {
		for (int i = 0; i<active_bullets_.size(); i++) {
			active_bullets_[i].update();
			if (!bulletIsInbounds(active_bullets_[i])) {
				active_bullets_.erase(active_bullets_.begin() + i);

			}
		}
	}
	updatePlayer();
}

void Room::updatePlayer() {
	player_->updateCardinal();
	if (upIsValid()) {
		player_->updateUp();
	}
	if (downIsValid()) {
		player_->updateDown();
	}
	if (leftIsValid()) {
		player_->updateLeft();
	}
	if (rightIsValid()) {
		player_->updateRight();
	}

}

void Room::playerShoot(int cardinal) {
	Bullet bullet = Bullet(player_->weapon_.getBullet());
	bullet.setDirection(cardinal);
	bullet.setBulletPos(player_->getPlayerPos());
	active_bullets_.push_back(bullet);
}

bool Room::bulletIsInbounds(Bullet bullet) {
	if (bullet.getBulletPos().x >= origin_.x + width_ || bullet.getBulletPos().x <= origin_.x) {
		return false;
	}
	if (bullet.getBulletPos().y >= origin_.y + height_ || bullet.getBulletPos().y <= origin_.y) {
		return false;
	}
	return true;
}

bool Room::playerIsInbounds()
{
	if (player_->getPlayerPos().x >= origin_.x + width_ || player_->getPlayerPos().x <= origin_.x) {
		return false;
	}
	if (player_->getPlayerPos().y >= origin_.y + height_ || player_->getPlayerPos().y <= origin_.y) {
		return false;
	}
	return true;
}

bool Room::upIsValid() {
	return player_->getPlayerPos().y - player_->getHeight()/2 > origin_.y;
}

bool Room::downIsValid() {
	return player_->getPlayerPos().y + player_->getHeight()/2 < origin_.y + height_;
}


bool Room::leftIsValid() {
	return player_->getPlayerPos().x - player_->getWidth()/2 > origin_.x;	
}

bool Room::rightIsValid() {
	return player_->getPlayerPos().x + player_->getWidth()/2 < origin_.x + width_;
}

bool Room::isLeavingUp() {
	return player_->getPlayerPos().distance(up_door.getPosition()) < 100;
}

bool Room::isLeavingRight()
{
	return false;
}

bool Room::isLeavingDown()
{
	return false;
}

bool Room::isLeavingLeft()
{
	return false;
}

void Room::randomize() {

}








