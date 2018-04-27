#include "Player.h"



Player::Player() {
	position_.x = ofGetWidth() / 2;
	position_.y = ofGetHeight() / 2;
	health_ = 100;
	width_ = 80;
	height_ = 80;
	speed_ = 6;

	up_ = false;
	down_ = false;
	right_ = false;
	left_ = false;
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
		current_cardinal = 1;
	}
}

void Player::updateDown() {
	if (down_) {
		position_.y += speed_;
		current_cardinal = 3;
	}

}

void Player::updateLeft() {
	if (left_) {
		position_.x -= speed_;
		current_cardinal = 4;
	}
}

void Player::updateRight() {
	if (right_) {
		position_.x += speed_;
		current_cardinal = 2;
	}
}

void Player::updateCardinal() {
	previous_cardinal = current_cardinal;
}

bool Player::hasWeapon() {
	return (weapon_.isRealWeapon());
}

Weapon Player::exchangeWeapon(Weapon weapon) {
	Weapon discarded = weapon_;
	weapon_ = weapon;
	return discarded;
}

void Player::rotatePlayer() {
	int rotations = 0;
	int cardinal_difference = current_cardinal - previous_cardinal;
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
	return current_cardinal;
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


