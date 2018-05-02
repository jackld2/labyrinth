#include "Player.h"



Player::Player() {
	position_.x = ofGetWidth() / 2;
	position_.y = ofGetHeight() / 2;
	health_ = 150;
	max_health_ = 150;
	width_ = 80;
	height_ = 80;
	speed_ = 10;

	up_ = false;
	down_ = false;
	right_ = false;
	left_ = false;
	has_weapon_ = false;

	current_cardinal_ = 1;
	previous_cardinal_ = 1;
}

void Player::setImage(ofImage *image) {
	player_image = image;
}

void Player::draw() {
	rotatePlayer();
	player_image->draw(position_.x - width_ / 2, position_.y - height_ / 2, width_, height_);
}

void Player::updateUp() {
	if (up_) {
		position_.y -= speed_;
		current_cardinal_ = 1;
	}
}

void Player::updateDown() {
	if (down_) {
		position_.y += speed_;
		current_cardinal_ = 3;
	}

}

void Player::updateLeft() {
	if (left_) {
		position_.x -= speed_;
		current_cardinal_ = 4;
	}
}

void Player::updateRight() {
	if (right_) {
		position_.x += speed_;
		current_cardinal_ = 2;
	}
}

void Player::updateCardinal() {
	previous_cardinal_ = current_cardinal_;
}

bool Player::hasWeapon() {
	return has_weapon_;
}

Weapon Player::getWeapon() {
	return weapon_;
}

double Player::getHealthFraction() {
	return (double)health_ / max_health_;
}

void Player::removeHealth(int health) {
	health_ = health_ - health;
}

Weapon Player::exchangeWeapon(Weapon weapon) {
	if (has_weapon_) {
		Weapon discarded = weapon_;
		weapon_ = weapon;
		return discarded;
	}
	return Weapon();
}

void Player::rotatePlayer() {
	int rotations = 0;
	int cardinal_difference = current_cardinal_ - previous_cardinal_;
	if (cardinal_difference > 0) {
		player_image->rotate90(cardinal_difference);
	}
	if (cardinal_difference < 0) {
		player_image->rotate90(cardinal_difference + 4);
	}
}

ofVec2f Player::getPlayerPos()
{
	return position_;
}

void Player::setPlayerPos(ofVec2f position) {
	position_ = position;
}

int Player::getCardinal()
{
	return current_cardinal_;
}

int Player::getSpeed() {
	return speed_;
}

int Player::getHeight()
{
	return height_;
}

int Player::getWidth() {
	return width_;
}

Weapon Player::dropWeapon()
{
	has_weapon_ = false;
	return weapon_;
}

void Player::setWeapon(Weapon weapon) {
	weapon_ = weapon;
	has_weapon_ = true;
}

void Player::setDirUp(bool value) {
	up_ = value;
}

void Player::setDirDown(bool value) {
	down_ = value;
}

void Player::setDirLeft(bool value) {
	left_ = value;
}

void Player::setDirRight(bool value) {
	right_ = value;
}

ofVec2f Player::getMomentumVector() {
	ofVec2f direction_vector = ofVec2f(0, 0);
	if (up_) {
		direction_vector += ofVec2f(0, -1*speed_);
	}
	if (down_) {
		direction_vector += ofVec2f(0, speed_);
	}
	if (left_) {
		direction_vector += ofVec2f(-1* speed_, 0);
	}
	if (right_) {
		direction_vector += ofVec2f(speed_, 0);
	}
	return direction_vector.getNormalized()*speed_;
}


