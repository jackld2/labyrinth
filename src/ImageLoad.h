#pragma once
#include "ofMain.h"
#include "Randomize.h"
class ImageLoad
{
public:
	ImageLoad();
	~ImageLoad();

	static ofImage getBGImage();
	ofImage getPlayerImage();
	static ofImage getBulletImage();
	ofImage getDoorImage();
	ofImage getWeaponImage();

private:

	
	ofImage player_image_;
	ofImage bullet_image_;
	ofImage door_image_;
	ofImage weapon_image_;
	
};

