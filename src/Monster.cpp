#include "Monster.h"
#include "Bullet.h"



Monster::Monster() {}

Monster::Monster(int max_health, int speed, int shot_speed, Bullet bullet, int height, int width ) {
	max_health_ = max_health;
	current_health_ = max_health;
	width_ = width;
	height_ = height;
	bullet_ = bullet;
	shot_speed_ = shot_speed;
	speed_ = speed;
	last_move_distance = 1;
	shot_charge_ = 0;
	up_ = false;
	down_ = false;
	right_ = false;
	left_ = false;
	current_cardinal_ = 1;
	previous_cardinal_ = 1;
}

ofVec2f Monster::getPosition()
{
	return position_;
}

void Monster::setPosition(ofVec2f position) {
	position_ = position;
}

int Monster::getHealth() {
	return current_health_;
}

int Monster::getMaxHealth() {
	return max_health_;
}

void Monster::removeHealth(int health) {
	current_health_ = current_health_ - health;
}

void Monster::setImage(ofImage image) {
	monster_image_ = image;
}

void Monster::draw() {
	rotateMonster();
	monster_image_.draw(position_.x - width_ / 2, position_.y - height_ / 2, width_, height_);
}

void Monster::rotateMonster() {
	int rotations = 0;
	int cardinal_difference = current_cardinal_ - previous_cardinal_;
	if (cardinal_difference > 0) {
		monster_image_.rotate90(cardinal_difference);
	}
	if (cardinal_difference < 0) {
		monster_image_.rotate90(cardinal_difference + 4);
	}
}

int Monster::getSpeed() {
	return speed_;
}

int Monster::getHeight() {
	return height_;
}

int Monster::getWidth() {
	return width_;
}

Bullet Monster::getBullet() {
	return bullet_;
}

bool Monster::shotIsReady() {
	if (shot_charge_ >= shot_speed_) {
		shot_charge_ = 0;
		return true;
	}
	return false;
}

bool Monster::isFrozen() {
	return !(up_ || down_ || left_ || right_) || (last_move_distance == 0);
}

void Monster::resetLastMoveDistance() {
	last_move_distance = 0;
}

int Monster::getLastMoveDistance() {
	return 0;
}

void Monster::updateUp() {
	if (up_) {
		position_.y -= speed_;
		shot_charge_ += speed_;
		current_cardinal_ = 1;
		last_move_distance += speed_;
	}
}

void Monster::updateDown() {
	if (down_) {
		position_.y += speed_;
		shot_charge_ += speed_;
		current_cardinal_ = 3;
		last_move_distance += speed_;
	}
}

void Monster::updateLeft() {
	if (left_) {
		position_.x -= speed_;
		shot_charge_ += speed_;
		current_cardinal_ = 4;
		last_move_distance += speed_;
	}
}

void Monster::updateRight() {
	if (right_) {
		position_.x += speed_;
		shot_charge_ += speed_;
		current_cardinal_ = 2;
		last_move_distance += speed_;
	}
}

void Monster::updateCardinal() {
	previous_cardinal_ = current_cardinal_;
}

Monster::~Monster() {}

void Monster::setDirUp(bool value) {
	up_ = value;
}

void Monster::setDirDown(bool value) {
	down_ = value;
}

void Monster::setDirLeft(bool value) {
	left_ = value;
}

void Monster::setDirRight(bool value) {
	right_ = value;
}

void Monster::setDirection(bool up, bool down, bool left, bool right) {
	up_ = up;
	down_ = down;
	left_ = left;
	right_ = right;
}

ofVec2f Monster::getMomentumVector() {
	ofVec2f direction_vector = ofVec2f(0, 0);
	if (up_) {
		direction_vector += ofVec2f(0, -1 * speed_);
	}
	if (down_) {
		direction_vector += ofVec2f(0, speed_);
	}
	if (left_) {
		direction_vector += ofVec2f(-1 * speed_, 0);
	}
	if (right_) {
		direction_vector += ofVec2f(speed_, 0);
	}
	return direction_vector.getNormalized()*speed_;
}
