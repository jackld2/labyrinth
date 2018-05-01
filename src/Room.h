#pragma once
#include "ofMain.h"
#include "Bullet.h"
#include "Weapon.h"
#include "Player.h"
#include "Monster.h"
#include "Door.h"
#include "Randomize.h"

class Room {

public:
	Room();
	~Room();
	void addPlayer(Player* player); //Add the player to the room
	void removePlayer(); //Remove the player from the room
	void pickUp(); //Checks to see if player is near an item and picks it up if true
	int interactDoor(); //returns cardinal number of door player is currently colliding with, -1 if no collision
	int interactWeapon(); //returns index of weapon player is currently colliding with, -1 if no collision
	void drawRoom(); // draw player, monsters, bullets, and items in room
	void drawDoors(); //Draws all four doors
	void setImage(ofImage image); //set image of room
	ofImage getImage(); //returns the image of the room
	void setMapCoordinate(ofVec2f coordinate); //Sets the map location of the room
	ofVec2f getMapCoordinate(); //Returns the rooms map location
	bool hasPlayer(); //Returns if the player is in the room or not
	void putWeapon(Weapon weapon); //Puts a weapon in the room
	void placeDoors(); //Places the four doors in the room
	Weapon takeWeapon(); //Takes a weapon from the room and returns it
	void update();
	void updatePlayer();
	void updatePlayerBullets();
	void updatePlayerHits(); //Checks every monster bullet in room and deals with player damage/hits accordingly
	void playerShoot(ofVec2f direction); //Shoots in a given cardinal direction
	int playerBulletsInRoom(); //Returns the number of player bullets in the room
	ofVec2f getNewPlayerPos(int cardinal); //returns the new position the player should be in after leaving the room from the given cardinal direction
	
	bool bulletIsInbounds(Bullet bullet); //Checks to see if bullet is still in screen
	bool upIsValid(ofVec2f position, int size);
	bool downIsValid(ofVec2f position, int size);
	bool leftIsValid(ofVec2f position, int size);
	bool rightIsValid(ofVec2f position, int size);

	bool isLeavingUp();
	bool isLeavingRight();
	bool isLeavingDown();
	bool isLeavingLeft();

	/*__Monster__*/
	void putMonster(Monster monster);
	int isMonsterHit(Bullet bullet); //returns if a monster is currently colliding with a player bullet
	void updateMonsterHits(); //Checks every player bullet in room and deals with hits/damage accordingly
	void setMonsters(std::vector<Monster> monsters); //sets the monsters in the room
	void monsterShoot(Monster monster); //shoots a bullet from the given monster in the vector direction of the player.
	void updateMonsters();
	void updateMonster(Monster monster);
	void drawMonsterBullets();
	void updateMonsterBullets();
	double getMonstersHealthFraction(); //returns a fraction of all monster health / total monster health
	



	ofVec2f map_coordinate_;




private:
	std::vector<Bullet> active_bullets_;
	std::vector<Bullet> monster_bullets_;
	std::vector<Monster> monsters_;
	std::vector<Weapon> room_weapons_;
	Player *player_;
	ofImage room_image_;

	int max_monsters_health;

	static const int WIDTH = 1024;
	static const int HEIGHT = 1024;
	static const int DOOR_SHIFT = 50; //Used to shift the doors outward so they aren't sitting inside the room.
	static const int PLAYER_SHIFT = 0;

	ofVec2f origin_;
	

	
	Door up_door;
	Door down_door;
	Door left_door;
	Door right_door;
};
