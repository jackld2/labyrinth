#pragma once
#include "Bullet.h"
#include "Monster.h"
#include "ofMain.h"
#include "Room.h"
#include  "ImageLoad.h"
#include "Randomize.h"

/*Normal Rooms*/
Room generateRoom(ofVec2f coordinate); //creates a randomly generated room at coordinate
Room generateStartRoom(); //creates the starting room at a random location, no monsters and a garunteed weapon spawn
Weapon generateWeapon(); //creates a randomly generated weapon
Bullet generateWeaponBullet(); //creates a randomly generated weapon bullet
Bullet generateMonsterBullet(); //creates a randomly generated monster bullet
std::vector<Monster> generateMonsters(); //creates an array of randomly generated monsters
Monster generateMonster(); // creates a single randomly generated monster

/*Boss Rooms*/
Room generateBossRoom(ofVec2f coordinate); //creates a boss room with a single strong monster and an above average weapon
Monster generateBoss(); //creates a boss monster with higher stats
Weapon generateBossWeapon(); //creates a randomly generated above average weapon
Bullet generateBossWeaponBullet(); //creates a randomly generated above average weapon bullet
Bullet generateBossBullet(); //creates a randomly generated boss bullet




