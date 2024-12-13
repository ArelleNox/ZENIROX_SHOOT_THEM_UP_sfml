#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "globalvar.hpp"

using namespace std;
using namespace sf;

enum Direction {
	up = 1,
	down = 2
};



class Enemy {
public:
	int HP = 0;
	int maxHP = 0;
	int shield = 0;
	int maxShield = 0;
	float velocity = 2;
	Direction direction = up;
	Sprite sprite;
	Texture texture;
	int AttackDamages;
	ID id;
	Clock attackClock;
	Clock boostClock;
	Time attackCooldown;
	Time boostDuration;
	Clock rechargeClock;
	Time rechargeCooldown;
	bool canBeBoosted = false;
	int setTexture();
	void setAttackAndHP();
	Enemy();
	~Enemy();
	void enemyMove();
};



class EnemyManager {
private:
	vector<Enemy*> enemies;
public:
	~EnemyManager();
	Enemy* creerEnemy(ID defLevel, float width, float height);
	void detruireEnemy(Enemy* enemy);
	void checkEnemy(Enemy* enemy,int &toKill);
	vector<Enemy* > getEnemies();
};

#endif