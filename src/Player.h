#pragma once
#include "ofMain.h"
#include "Weapon.h"

class Player
{
public:
	Player();
	void setImage(ofImage *image);
	void draw(); //Draws the player at the current position
	void updateUp();
	void updateDown();
	void updateLeft();
	void updateRight();
	void updateCardinal();
	bool hasWeapon(); //Tells if the player currently has a real weapon
	Weapon exchangeWeapon(Weapon weapon); //sets the players weapon to given weapon, returns the old weapon.
	void rotatePlayer(); //Rotates the player based on a system of numbered cardinal directions and the difference between the new and previous directions.
	ofVec2f getPlayerPos(); //Returns the players position
	void setPlayerPos(ofVec2f position); //Sets the position of the player.
	int getCardinal(); //returns cardinal direction of the player
	int getSpeed(); //returns the speed of the player
	int getHeight(); //Returns the width of the player
	int getWidth(); //Returns the height of the player

public:
	Weapon weapon_;
	ofImage *player_image;
	int current_cardinal = 1;
	int previous_cardinal = 1;
	int health_;
	ofVec2f position_;
	int height_;
	int width_;
	int speed_;
	ofVec2f body_size_;
	ofVec2f screen_dims_;
	bool up_, down_, left_, right_;

};

