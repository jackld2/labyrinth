#pragma once
#include "ofMain.h"
#include "Bullet.h"

class Weapon {

public:
	Weapon();
	Weapon(Bullet bullet); 
	void setImage(ofImage *image); //Sets the image being used for the projectile of the weapon
	void setPosition(ofVec2f pos); //Sets position of the weapon
	void draw(); //Draws the weapon at the current position
	Bullet getBullet();
	bool isRealWeapon(); //Verifys that weapon has a bullet assocaited with it. (For starting conditions of player)
	void randomize(); 
	static const int WEAPON_HEIGHT = 100;
	static const int WEAPON_WIDTH = 100;

	

private:
	Bullet bullet_type;
	ofImage *weapon_image_;
	ofVec2f position_;
	ofImage *bullet_image_;
};

