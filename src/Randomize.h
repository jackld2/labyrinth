#pragma once
#include <random>
#include "ofMain.h"
	/*All random functions have parameters that can be adjusted to adjust game generation probabilites*/
	int randomDamage(); //returns a random bullet damage
	int randomBulletSpeed(); //returns a random weapon bullet speed
	int randomMonsterBulletSpeed(); //returns a random monster bullet speed
	int randomMonsterShotSpeed(); //returns the distance a monster travels before they shoot.
	int randomBulletSize(); //returns a random size for a bullet
	int randomBulletMax(); //returns a random maximum amount of bullets that a weapon can have in the room
	int randomMonsterAmount(); //returns a random amount of monsters to be spawned in the room
	
	//BOSS//
	int randomBossModifier(); //returns a modifier that will boost the weapon stats of the weapon in room
	int randomBossSpeed(); //returns random speed of boss
	int randomBossShotSpeed(); //returns random shot speed of boss
	int randomBossBulletSpeed(); //returns random boss bullet speed
	int randomBossHealth(); //returns random health for a boss
	int randomBossDamage(); //returns random boss damage
	int randomBossBulletSize(); //returns random boss bullet size
	int randomBossSize(); //returns a random boss size




	int randomSpeed(); //returns a random speed for a monster
	int randomMaxHealth(); //returns a random max health for a monster
	int randomPositionX(); //returns a random X positionw within the room
	int randomPositionY(); //returns a random Y position within the room
	int randomMapPosX(); //returns a random map X positon
	int randomMapPosY(); //returns a random map Y position
	ofVec2f randomMapPos(); //returns a random map position for a room in the labyrinth
	int randomMonsterSize(); //returns a random monster size
	bool randomBool(); //50 50 random bool, used currently for random monster movement
	bool willSpawnWeapon(); //returns true based on the probability a room spawns a weapon (currently set to 30%)
	bool willBeBossRoom(); //returns true based the probability a room will be a boss room (currently set to 5%)
	int randomBulletImageIndex(); //returns a random index of the bullet_images_ vector in ImageLoad
	int randomWeaponImageIndex(); //returns a random index of the weapon_images_ vector in ImageLoad
	int randomMonsterImageIndex(); //returns a random index of the monster_images- vector in ImageLoad




