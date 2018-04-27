#include "Weapon.h"



Weapon::Weapon() {
	bullet_type = Bullet();
}

Weapon::Weapon(Bullet bullet) {
	bullet_type = bullet;
}

void Weapon::setImage(ofImage *image) {
	weapon_image_ = image;
}

void Weapon::setPosition(ofVec2f pos) {
	position_ = pos;
}

void Weapon::draw() {
	weapon_image_->draw(position_.x - WEAPON_WIDTH / 2, position_.y - WEAPON_HEIGHT / 2, WEAPON_WIDTH, WEAPON_HEIGHT);

}

Bullet Weapon::getBullet(){
	return bullet_type;
}

bool Weapon::isRealWeapon()
{
	return false;
}

void Weapon::randomize() {

}
