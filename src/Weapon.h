#pragma once
#include "ofMain.h"
#include "Bullet.h"

class Weapon {

public:
	Weapon();
	Weapon(Bullet bullet, int bullet_max); 
	void setImage(ofImage image); //Sets the image being used for the projectile of the weapon
	ofImage getImage(); //Return image of weapon
	void setPosition(ofVec2f pos); //Sets position of the weapon
	ofVec2f getPosition(); //returns the position of the weapon
	void draw(); //Draws the weapon at the current position
	Bullet getBullet(); //returns the bullet of the weapon
	int getBulletMax(); //returns the weapons max bullets (number of bullets that can be in the room at once)
	bool isRealWeapon(); //Verifys that weapon has a bullet assocaited with it. (For starting conditions of player)
	static const int WEAPON_HEIGHT = 100;
	static const int WEAPON_WIDTH = 100;

	

private:
	Bullet bullet_type;
	int bullet_max_;
	ofImage weapon_image_;
	ofVec2f position_;
};

