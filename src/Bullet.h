#pragma once
#include "ofMain.h"
class Bullet
{
public:
	Bullet();
	Bullet(int damage, int speed, int width, int height); //Creates a bullet of a given damage, speed, and dimensions
	~Bullet();
	void setImage(ofImage image); //Sets image of the bullet
	ofVec2f getBulletPos(); //Returns the position of the bullet
	void setBulletPos(ofVec2f position); //Set the position of the bullet
	int getBulletDamage(); //Returns the damage of the bullet
	int getBulletSpeed(); //Returns the speed of the bullet
	void setDirection(int cardinal);
	void draw(); //Draws the bullet
	void update();
	void randomize();

private:

	int width_;
	int height_;
	int damage_;
	int speed_;
	int cardinal_direction_;

	ofImage bullet_image_;
	ofVec2f bullet_position_;
};

