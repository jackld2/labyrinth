#pragma once
#include "ofMain.h"
class Bullet
{
public:
	Bullet();
	Bullet(int damage, int speed, int width, int height); //Creates a bullet of a given damage, speed, and dimensions
	~Bullet();
	void setImage(ofImage image); //Sets image of the bullet
	ofImage getImage(); //returns the image of the bullet
	ofVec2f getBulletPos(); //Returns the position of the bullet
	void setBulletPos(ofVec2f position); //Set the position of the bullet
	int getBulletDamage(); //Returns the damage of the bullet
	int getBulletSpeed(); //Returns the speed of the bullet
	void setVectorDirection(ofVec2f direction); //testing
	void setMomentumVector(ofVec2f momentum_vector); //sets the momentum vector to be added to the bullet's trajectory
	void draw(); //Draws the bullet
	void bulletUpdate(); //Updates the bullets position based on momentum and initial fire direction
	int getSize(); //returns the size of the bullet (bullets must be square images)

private:
	int size_;
	int damage_;
	int speed_;
	int cardinal_direction_;

	ofImage bullet_image_;
	ofVec2f bullet_position_;
	ofVec2f bullet_direction_;
	ofVec2f momentum_vector_;
};

