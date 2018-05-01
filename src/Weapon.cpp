#include "Weapon.h"

Weapon::Weapon() {
	bullet_type = Bullet();
}

Weapon::Weapon(Bullet bullet, int bullet_max) {
	bullet_type = bullet;
	bullet_max_ = bullet_max;
}

void Weapon::setImage(ofImage image) {
	weapon_image_ = image;
}

ofImage Weapon::getImage() {
	return weapon_image_;
}

void Weapon::setPosition(ofVec2f pos) {
	position_ = pos;
}

ofVec2f Weapon::getPosition() {
	return position_;
}

void Weapon::draw() {
	weapon_image_.draw(position_.x - WEAPON_WIDTH / 2, position_.y - WEAPON_HEIGHT / 2, WEAPON_WIDTH, WEAPON_HEIGHT);
}

Bullet Weapon::getBullet(){
	return bullet_type;
}

int Weapon::getBulletMax() {
	return bullet_max_;
}

bool Weapon::isRealWeapon() {
	return false;
}
