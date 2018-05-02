#include "ImageLoad.h"

static const std::vector<std::string> background_images_ = std::vector<std::string>({ "background.png" });
static const std::vector<std::string> monster_images_ = std::vector<std::string>({ "monster.png" });
static const std::vector<std::string> weapon_images_ = std::vector<std::string>({ "gun_1.png", "gun_2.png", "gun_3.png","gun_4.png","gun_5.png" });
static const std::vector<std::string> bullet_images_ = std::vector<std::string>({ "bullet.png"});
static const std::vector<std::string> monster_bullet_images_ = std::vector<std::string>({ "monster_bullet.png" });

ImageLoad::ImageLoad() {
}

ImageLoad::~ImageLoad() {
}

ofImage ImageLoad::getBGImage() {
	ofImage background;
	background.load(background_images_[0]);
	return background;
}

ofImage ImageLoad::getPlayerImage() {
	ofImage player;
	player.load("player.png");
	return player;
}

ofImage ImageLoad::getBulletImage() {
	ofImage bullet;
	bullet.load(bullet_images_[randomBulletImageIndex()]);
	return bullet;
}

ofImage ImageLoad::getMonsterBulletImage() {
	ofImage bullet;
	bullet.load(monster_bullet_images_[randomBulletImageIndex()]);
	return bullet;
}

ofImage ImageLoad::getDoorImage() {
	ofImage door;
	door.load("door.png");
	return door;
}

ofImage ImageLoad::getWeaponImage() {
	ofImage weapon;
	weapon.load(weapon_images_[randomWeaponImageIndex()]);
	return weapon;
}

ofImage ImageLoad::getMonsterImage(){
	ofImage monster;
	monster.load(monster_images_[randomMonsterImageIndex()]);
	return monster;
}

ofImage ImageLoad::getTitleScreenImage() {
	ofImage title;
	title.load("title.png");
	return title;
}


