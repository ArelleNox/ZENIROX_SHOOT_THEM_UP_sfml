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



class Enemy {
public:
	int HP;
	float velocity = 5;
	float up = 0;
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
	void Attack();
};



class EnemyManager {
private:
	vector<Enemy*> enemies;
public:
	~EnemyManager();
	Enemy* creerEnemy(ennemi defLevel);
	void detruireEnemy(Enemy* enemy);
	void checkEnemy(Enemy* enemy);
	vector<Enemy* > getEnemies();
};
#endif