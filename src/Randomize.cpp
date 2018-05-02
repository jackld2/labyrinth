#include "Randomize.h"

int randomDamage() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(5, 15);
	return dist(mt);
}

int randomBulletSpeed() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(15, 35);
	return dist(mt);
}

int randomMonsterBulletSpeed() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(5, 10);
	return dist(mt);
}

int randomMonsterShotSpeed() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(400, 600);
	return dist(mt);
}

int randomBulletSize() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(30, 60);
	return dist(mt);
}

int randomBulletMax() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(8, 25);
	return dist(mt);
}

int randomMonsterAmount() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(2, 5);
	return dist(mt);
}

int randomBossModifier() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(10, 20);
	return dist(mt);
}

int randomBossSpeed() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(4, 10);
	return dist(mt);
}

int randomBossShotSpeed() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(250, 400);
	return dist(mt);
}

int randomBossBulletSpeed() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(8, 18);
	return dist(mt);
}

int randomBossHealth() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(700, 1500);
	return dist(mt);
}

int randomBossDamage() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(10, 25);
	return dist(mt);
}

int randomBossBulletSize() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(20, 100);
	return dist(mt);
}

int randomBossSize() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(150, 250);
	return dist(mt);
}

int randomSpeed() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(2, 6);
	return dist(mt);
}

int randomMaxHealth() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(100, 200);
	return dist(mt);
}

int randomPositionX() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(448, 1472);
	return dist(mt);
}

int randomPositionY() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(28, 1052);
	return dist(mt);
}

int randomMapPosX() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(-19, 18);
	return dist(mt);
}

int randomMapPosY() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(-10, 11);
	return dist(mt);
}

ofVec2f randomMapPos() {
	return ofVec2f(randomMapPosX(), randomMapPosY());
}

int randomMonsterSize() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(30, 150);
	return dist(mt);
}

bool randomBool() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 10);
	return dist(mt) > 5;
}

bool willSpawnWeapon() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 10);
	return dist(mt) >= 7;
}

bool willBeBossRoom() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 100);
	return dist(mt) <= 5;
}

int randomBulletImageIndex(){
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 0);
	return dist(mt);
}

int randomWeaponImageIndex() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 4);
	return dist(mt);
}

int randomMonsterImageIndex() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 0);
	return dist(mt);
}


