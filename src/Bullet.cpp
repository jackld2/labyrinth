#include "Bullet.h"

Bullet::Bullet() {
	damage_ = 0;
	speed_ = 0;
	width_ = 0;
	height_ = 0;
}

Bullet::Bullet(int damage, int speed, int width, int height) {
	damage_ = damage;
	speed_ = speed;
	width_ = width;
	height_ = height;
	cardinal_direction_ = -1;

}


Bullet::~Bullet() {
}

void Bullet::setImage(ofImage image) {
	bullet_image_ = image;
	
}

ofVec2f Bullet::getBulletPos() {
	return bullet_position_;
}

void Bullet::setBulletPos(ofVec2f position) {
	bullet_position_ = position;
}

int Bullet::getBulletDamage() {
	return damage_;
}

int Bullet::getBulletSpeed() {
	return speed_;
}

void Bullet::setDirection(int cardinal) {
	
	cardinal_direction_ = cardinal;
	bullet_image_.rotate90(cardinal_direction_); //0 deg rotation for north, 90 deg rotation for east, 180 deg rotation for south and 270 deg rotation for west
}

void Bullet::draw() {
	
	bullet_image_.draw(bullet_position_.x - width_ / 2, bullet_position_.y - height_ / 2, width_, height_);
}


void Bullet::update() {
	if (cardinal_direction_ == 1) {
		bullet_position_.x += speed_;
	}
	if (cardinal_direction_ == 3) {
		bullet_position_.x -= speed_;
	}
	if (cardinal_direction_ == 0) {
		bullet_position_.y -= speed_;
	}
	if (cardinal_direction_ == 2) {
		bullet_position_.y += speed_;
	}
}

void Bullet::randomize()
{
}
