#include "Labyrinth.h"



Labyrinth::Labyrinth() {
	current_room_ = Room();
	room_map[pair<int, int>(0, 0)] = current_room_;
}


Labyrinth::~Labyrinth()
{
}
