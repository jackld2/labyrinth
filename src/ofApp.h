#pragma once

#include "ofMain.h"
#include "Player.h"
#include "Room.h"
#include "Randomize.h"
#include "ImageLoad.h"

class labyrinthGame : public ofBaseApp{

	enum GameState {
		START = 0,
		IN_PROGRESS,
		MAP,
		DEATH,
	};

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key); 

		void generateRoom(ofVec2f coordinate);
		Weapon generateWeapon();
		Bullet generateWeaponBullet();
		Bullet generateMonsterBullet();
		std::vector<Monster> generateMonsters();
		Monster generateMonster();
		pair<int, int> findNextRoomCoord();
		void changeRooms(int i); //Changes rooms according to 'i' which is the cardinal number of the door leaving through
		void drawMap();
		void drawHUD();
		void drawBulletHUD();
		void drawWeaponHUD();
		void drawPlayerHealthHUD();
		void drawMonsterHealthHUD();

private:
	GameState current_state_ = START;
	bool should_update_ = false;
	int roomExists(ofVec2f coordinate);
	ofImage player_img;
	ofImage background_img;
	ofImage bullet_img;
	ofImage weapon_img;
	ofImage monster_img;
	ofImage title_img;
	ofTrueTypeFont gamefont_;
	const std::string MAP_MESSAGE = "PRESS M FOR MAP";
	const std::string ESCAPE_MESSAGE = "PRESS ESC TO EXIT";
	const std::string PLAYER_MESSAGE = "PLAYER";
	const std::string MONSTER_MESSAGE = "MONSTERS";
	const std::string QUIT_MESSAGE = "PRESS ESC TO QUIT";
	const std::string WEAPON_MESSAGE = "WEAPON";
	const std::string DAMAGE_MESSAGE = "DAMAGE";
	const std::string SPEED_MESSAGE = "SPEED";
	const std::string FULL_BAR_MESSAGE = "FULL";
	const int HEALTH_BAR_LENGTH = 200;
	

	Bullet bullet_;

	Player player_;
	Room* current_room_;
	std::vector<Room> rooms_;
	ofVec2f current_coordinate_;
	std::vector<Weapon> game_weapons_;

	
	
};
