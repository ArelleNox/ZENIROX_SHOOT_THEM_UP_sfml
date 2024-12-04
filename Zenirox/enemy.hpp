#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

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
	int Attack;
	ennemi level;
	int setTexture();
	void setAttackAndHP();
	Enemy() {}
	~Enemy() { cout << "Un ennemi a ete detruit" << endl; };
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