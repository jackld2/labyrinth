#pragma once
#include "ofMain.h"
#include "Randomize.h"
class ImageLoad
{
public:
	ImageLoad();
	~ImageLoad();

	static ofImage getBGImage(); //returns a background image from the background_images_ vector of files 
	static ofImage getPlayerImage(); //returns the player image
	static ofImage getBulletImage(); //returns a weapon bullet image from the bullet_images_ vector of files
	static ofImage getMonsterBulletImage(); //returns a monster bullet image from the monster_bullet_images_ vector of files 
	static ofImage getDoorImage(); //returns the door image
	static ofImage getWeaponImage(); //returns a weapon image from the weapon_images_ vector of files
	static ofImage getMonsterImage(); //returns a monster image from the monster_images_ vector of files
	static ofImage getTitleScreenImage(); //returns the title screen image

private:

	
};

