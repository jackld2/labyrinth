#pragma once
#include "ofMain.h"
#include "Weapon.h"

class Player
{
public:
	Player();
	void setImage(ofImage *image); //sets the image pointer of the player
	void draw(); //Draws the player at the current position
	
	//Updates the player's movement in the up, down, left, right directions (using bools)
	void updateUp(); 
	void updateDown();
	void updateLeft();
	void updateRight();

	void updateCardinal(); //Updates the cardinal direction of the player (used for rotating image)
	bool hasWeapon(); //Tells if the player currently has a weapon
	Weapon getWeapon(); //returns the player's weapon
	double getHealthFraction(); // returns the current health of the player
	void removeHealth(int health); //removes a given amount of health from the player
	Weapon exchangeWeapon(Weapon weapon); //sets the players weapon to given weapon, returns the old weapon.
	void rotatePlayer(); //Rotates the player based on a system of numbered cardinal directions and the difference between the new and previous directions.
	ofVec2f getPlayerPos(); //Returns the players position
	void setPlayerPos(ofVec2f position); //Sets the position of the player.
	int getCardinal(); //returns cardinal direction of the player
	int getSpeed(); //returns the speed of the player
	int getHeight(); //Returns the height of the player
	int getWidth(); //Returns the width of the player
	Weapon dropWeapon(); //Returns the player's weapon
	void setWeapon(Weapon weapon); //Sets the player's weapon

	void setDirUp(bool value); //sets bool up_
	void setDirDown(bool value); //sets bool down_
	void setDirLeft(bool value); //sets bool left_
	void setDirRight(bool value); //sets bool right_
	ofVec2f getMomentumVector(); //returns the player's current momentum as a vector (used to modify bullet direction and speed based on momentum)

private:
	bool has_weapon_;
	Weapon weapon_;
	ofImage *player_image;
	int current_cardinal_ = 1;
	int previous_cardinal_ = 1;
	int health_;
	int max_health_;
	ofVec2f position_;
	int height_;
	int width_;
	int speed_;
	ofVec2f body_size_;
	ofVec2f screen_dims_;
	bool up_, down_, left_, right_;

};

