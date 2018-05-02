#pragma once

#include "ofMain.h"
#include "Player.h"
#include "Room.h"
#include "Randomize.h"
#include "ImageLoad.h"
#include "Generate.h"

class labyrinthGame : public ofBaseApp{

	enum GameState {
		START = 0,
		IN_PROGRESS,
		MAP,
		DEATH,
		WIN,
	};
	enum PlayerMode {
		NORMAL_MODE,
		PRESENTATION_MODE
	};

	public:
		//standard openframeworks functions
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key); 

		void reset(); //resets the game 
		void changeRooms(int i); //Changes rooms according to 'i' which is the cardinal number of the door leaving through
		void drawMap(); //Draws the map of the labyrinth with all of its rooms. PLayer image is drawn on the room the player is currently in
		void drawHUD(); //Draws the HUD of the game
		void drawBulletHUD(); //Draws a dynamic representation of bullets left that can be shot by the player
		void drawWeaponHUD(); //Draws weapon picture and information
		void drawPlayerHealthHUD(); //Draws player health
		void drawMonsterHealthHUD(); //Draws monster health (For all monsters: Total remaining health / Total max health)

private:
	GameState current_state_ = START;
	PlayerMode player_mode_ = NORMAL_MODE;
	int roomExists(ofVec2f coordinate);
	ofImage player_img;
	ofImage title_img;
	ofVec2f win_coordinate_;
	ofTrueTypeFont gamefont_;
	Player player_;
	Room* current_room_;
	std::vector<Room> rooms_;

	const int HEALTH_BAR_LENGTH = 200;

	const std::string MAP_MESSAGE = "PRESS M FOR MAP";
	const std::string ESCAPE_MESSAGE = "PRESS ESC TO EXIT";
	const std::string PLAYER_MESSAGE = "PLAYER";
	const std::string MONSTER_MESSAGE = "MONSTERS";
	const std::string QUIT_MESSAGE = "PRESS ESC TO QUIT";
	const std::string WEAPON_MESSAGE = "WEAPON";
	const std::string DAMAGE_MESSAGE = "DAMAGE";
	const std::string SPEED_MESSAGE = "SPEED";
	const std::string FULL_BAR_MESSAGE = "FULL";
	const std::string WIN_MESSAGE = "YOU FOUND THE END";
	const std::string DEATH_MESSAGE = "YOU DIED"; 
	const std::string RESTART_MESSAGE = "PRESS SPACE TO RESTART";

	
	

	
	
};
