#pragma once
#include "ofMain.h"
#include "Bullet.h"
#include "Weapon.h"
#include "Player.h"
#include "Monster.h"
#include "Door.h"
class Room {

public:
	Room();
	~Room();
	void addPlayer(Player* player); //Add the player to the room
	Player* removePlayer(); //Remove the player from the room
	void drawRoom(); // draw player, monsters, bullets, and items in room
	void drawDoors(); //Draws all four doors
	void setImage(ofImage *image); //set image of room
	bool hasPlayer(); //Returns if the player is in the room or not
	void putWeapon(Weapon weapon); //Puts a weapon in the room
	void placeDoors(); //Places the four doors in the room
	Weapon takeWeapon(); //Takes a weapon from the room and returns it
	void resize(); //Places objects in correct position based on resizing of window.
	void update();
	void updatePlayer();
	void playerShoot(int cardinal); //Shoots in a given cardinal direction
	bool bulletIsInbounds(Bullet bullet); //Checks to see if bullet is still in screen
	bool playerIsInbounds(); //Checks to see if player is in the screen
	bool upIsValid();
	bool downIsValid();
	bool leftIsValid();
	bool rightIsValid();

	bool isLeavingUp();
	bool isLeavingRight();
	bool isLeavingDown();
	bool isLeavingLeft();

	ofVec2f map_coordinate_;

	void randomize(); //randomizes a room



private:
	std::vector<Bullet> active_bullets_;
	std::vector<Weapon> room_weapons_;
	std::vector<Door> doors_;
	Player *player_;
	ofImage *room_image_;
	ofVec2f origin_;
	int width_ = 1024;
	int height_ = 1024;

	static const int DOOR_SHIFT = 50; //Used to shift the doors outward so they aren't sitting inside the room.
	Door up_door;
	Door down_door;
	Door left_door;
	Door right_door;

	bool leave_up_;
	bool leave_down_;
	bool leave_left_;
	bool leave_right_;

};

