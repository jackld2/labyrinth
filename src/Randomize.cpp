#include "Randomize.h"

int randomDamage()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(5, 20);
	return dist(mt);
}

int randomBulletSpeed() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(10, 35);
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
	std::uniform_int_distribution<int> dist(300, 500);
	return dist(mt);
}

int randomBulletSize() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(20, 50);
	return dist(mt);
}

int randomBulletMax() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(5, 20);
	return dist(mt);
}

int randomMonsterAmount() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 5);
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

int randomBulletImageIndex(){
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 1);
	return dist(mt);
}


