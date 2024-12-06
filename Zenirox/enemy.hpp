#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "globalvar.hpp"

using namespace std;
using namespace sf;

enum ennemi {
	Niveau1 = 1,
	Niveau2 = 2,
	Niveau3 = 3
};
enum Direction {
	up = 1,
	down = 2
};



class Enemy {
public:
	int HP;
	float velocity = 2;
	Direction direction = up;
	Sprite sprite;
	Texture texture;
	int AttackDamages;
	ennemi level;
	ID id;
	Clock attackClock;
	Time attackCooldown;
	Clock rechargeClock;
	Time rechargeCooldown;
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
	Enemy* creerEnemy(ennemi defLevel, float width, float height);
	void detruireEnemy(Enemy* enemy);
	void checkEnemy(Enemy* enemy);
	vector<Enemy* > getEnemies();
};
#endif