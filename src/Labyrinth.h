#pragma once
#include "Room.h"
#include "Player.h"
#include "Weapon.h"
#include "ofMain.h"
class Labyrinth
{
public:
	Labyrinth();
	~Labyrinth();
	void generateRoom(int cardinalDirection);



private:
	std::map<pair<int,int>, Room> room_map;
	Room current_room_;
	Player game_player_;
	std::vector<Weapon> game_weapons_;
};

