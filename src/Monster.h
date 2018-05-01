#pragma once
#include "ofMain.h"
#include "Weapon.h"
class Monster
{
public:
	Monster();
	Monster(int max_health, int speed, int shot_speed, Bullet bullet, int height, int width); 
	~Monster();
	
	ofVec2f getPosition(); //gets position of the monster
	void setPosition(ofVec2f position); //sets the position of the monster
	int getHealth(); //returns health of the monster
	int getMaxHealth();
	void removeHealth(int health); //sets the health of the monster
	void setImage(ofImage image); //Sets image of the monster
	void draw(); //draws the monster
	void rotateMonster(); //Rotates the monster based on a system of numbered cardinal directions and the difference between the new and previous directions.

	int getSpeed(); //returns the speed of the monster
	int getHeight(); //Returns the height of the monster
	int getWidth(); //Returns the width of the monster
	Bullet getBullet(); //returns the bullet of the monster
	bool shotIsReady(); //returns if the monster is ready to shoot
	bool isFrozen(); //Tells if the random boolean generator has set all of the monsters bool directions to false.
	void resetLastMoveDistance();
	int getLastMoveDistance();
	 
	void updateUp(); //updates the monsters direction up
	void updateDown(); //updates the monsters direction down
	void updateLeft(); //updates the monsters direction left
	void updateRight(); //updates the monsters direction right
	void updateCardinal();

	void setDirUp(bool value);
	void setDirDown(bool value);
	void setDirLeft(bool value);
	void setDirRight(bool value);
	void setDirection(bool up, bool down, bool left, bool right);
	ofVec2f getMomentumVector();




private:
	

	ofVec2f position_;
	ofImage monster_image_;
	Bullet bullet_;
	
	int current_health_;
	int max_health_;
	int height_;
	int width_;
	int speed_;
	int shot_speed_;
	int shot_charge_;
	int last_move_distance;
	
	bool up_, down_, left_, right_;
	int current_cardinal_;
	int previous_cardinal_;
	

};

