#include "Bullet.h"

Bullet::Bullet() {
	damage_ = 0;
	speed_ = 0;
	size_ = 0;
}

Bullet::Bullet(int damage, int speed, int size, int height) {
	damage_ = damage;
	speed_ = speed;
	size_ = size;
	cardinal_direction_ = -1;
}

Bullet::~Bullet() {
}

void Bullet::setImage(ofImage image) {
	bullet_image_ = image;
}

ofImage Bullet::getImage() {
	return bullet_image_;
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

void Bullet::setVectorDirection(ofVec2f direction) {
	if (direction.x > 0 && abs(direction.x) > abs(direction.y)) {
		bullet_image_.rotate90(1);
	}
	if (direction.x < 0 && abs(direction.x) > abs(direction.y)) {
		bullet_image_.rotate90(3);
	}
	if (direction.y > 0 && abs(direction.x) < abs(direction.y)) {
		bullet_image_.rotate90(2);
	}
	if (direction.y < 0 && abs(direction.x) < abs(direction.y)) {
		bullet_image_.rotate90(0);
	}
	bullet_direction_ = direction;
}

void Bullet::setMomentumVector(ofVec2f momentum_vector) {
	momentum_vector_ = momentum_vector;
}

void Bullet::draw() {
	bullet_image_.draw(bullet_position_.x - size_ / 2, bullet_position_.y - size_ / 2, size_, size_);
}

void Bullet::bulletUpdate() {
	if (bullet_position_.distance(bullet_position_ + bullet_direction_ * speed_ + momentum_vector_) >= speed_) {
		bullet_position_ = bullet_position_ + bullet_direction_ * speed_ + momentum_vector_;
	}
	else {
		bullet_position_ = bullet_position_ + (bullet_direction_ * speed_);
	}
}

int Bullet::getSize() {
	return size_;
}


 