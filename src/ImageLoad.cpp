#include "ImageLoad.h"

static const std::vector<std::string> background_images_ = std::vector<std::string>({ "background.png" });
static const std::vector<std::string> monster_images_ = std::vector<std::string>({ "monster.png" });
static const std::vector<std::string> weapon_images_ = std::vector<std::string>({ "weapon.png" });
static const std::vector<std::string> bullet_images_ = std::vector<std::string>({ "bullet.png", "arrow.png"});



ImageLoad::ImageLoad() {
	

}


ImageLoad::~ImageLoad() {
}

ofImage ImageLoad::getBGImage()
{
	ofImage background;
	background.load(background_images_[0]);
	return background;
}

ofImage ImageLoad::getPlayerImage()
{
	return player_image_;
}

ofImage ImageLoad::getBulletImage() {
	ofImage bullet;
	bullet.load(bullet_images_[randomBulletImageIndex()]);
	return bullet;
}

ofImage ImageLoad::getDoorImage()
{
	return door_image_;
}

ofImage ImageLoad::getWeaponImage()
{
	return weapon_image_;
}


