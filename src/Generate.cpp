#include "Generate.h"

Room generateRoom(ofVec2f coordinate) {
	Room room = Room();
	room.setMapCoordinate(coordinate);
	room.setImage(ImageLoad::getBGImage());
	if (willSpawnWeapon()) {
		room.putWeapon(generateWeapon());
	}
	room.setMonsters(generateMonsters());
	return room;
}

Room generateStartRoom() {
	Room room = Room();
	room.setMapCoordinate(randomMapPos());
	room.setImage(ImageLoad::getBGImage());
	room.putWeapon(generateWeapon());
	return room;
}

Room generateBossRoom(ofVec2f coordinate) {
	Room room = Room();
	room.setMapCoordinate(coordinate);
	room.setImage(ImageLoad::getBGImage());
	room.putWeapon(generateBossWeapon());
	room.putMonster(generateBoss());
	return room;
}

Weapon generateWeapon() {
	Weapon weapon = Weapon(generateWeaponBullet(), randomBulletMax());
	weapon.setImage(ImageLoad::getWeaponImage());
	weapon.setPosition(ofVec2f(randomPositionX(), randomPositionY()));
	return weapon;
}

Bullet generateBossWeaponBullet() {
	int boss_modifier = randomBossModifier(); //increases the stats of the bullet due to being dropped by a boss
	int bullet_size = randomBulletSize() + boss_modifier;
	Bullet bullet = Bullet(randomDamage() + boss_modifier, randomBulletSpeed() + boss_modifier, bullet_size, bullet_size);
	bullet.setImage(ImageLoad::getBulletImage());
	return bullet;
}

Bullet generateWeaponBullet() {
	int bullet_size = randomBulletSize();
	Bullet bullet = Bullet(randomDamage(), randomBulletSpeed(), bullet_size, bullet_size);
	bullet.setImage(ImageLoad::getBulletImage());
	return bullet;
}

Bullet generateMonsterBullet() {
	int bullet_size = randomBulletSize();
	Bullet bullet = Bullet(randomDamage(), randomMonsterBulletSpeed(), bullet_size, bullet_size);
	bullet.setImage(ImageLoad::getMonsterBulletImage());
	return bullet;
}

Bullet generateBossBullet() {
	int bullet_size = randomBossBulletSize();
	Bullet bullet = Bullet(randomBossDamage(), randomBossBulletSpeed(), bullet_size, bullet_size);
	bullet.setImage(ImageLoad::getMonsterBulletImage());
	return bullet;
}

std::vector<Monster> generateMonsters() {
	std::vector<Monster> monsters;
	for (int i = 0; i < randomMonsterAmount(); i++) {
		monsters.push_back(generateMonster());
	}
	return monsters;
}

Monster generateMonster() {
	int size = randomMonsterSize();
	Monster monster = Monster(randomMaxHealth(), randomSpeed(), randomMonsterShotSpeed(), generateMonsterBullet(), size, size);
	monster.setPosition(ofVec2f(randomPositionX(), randomPositionY()));
	monster.setDirection(randomBool(), randomBool(), randomBool(), randomBool());
	monster.setImage(ImageLoad::getMonsterImage());
	return monster;
}

Monster generateBoss() {
	int size = randomBossSize();
	Monster monster = Monster(randomBossHealth(), randomBossSpeed(), randomBossShotSpeed(), generateBossBullet(), size, size);
	monster.setPosition(ofVec2f(randomPositionX(), randomPositionY()));
	monster.setDirection(randomBool(), randomBool(), randomBool(), randomBool());
	monster.setImage(ImageLoad::getMonsterImage());
	return monster;
}

Weapon generateBossWeapon() {
	Weapon weapon = Weapon(generateBossWeaponBullet(), randomBulletMax());
	weapon.setImage(ImageLoad::getWeaponImage());
	weapon.setPosition(ofVec2f(randomPositionX(), randomPositionY()));
	return weapon;
}
