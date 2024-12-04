#include "enemy.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

const float HEIGHT = 1080;
const float WIDTH = 1920;

int Enemy::setTexture() {
	switch (level)
	{
	case Niveau1:
		if (!texture.loadFromFile("enemy1.png")) { cout << "Erreur lors du chargement de texure d'ennemi niveau 1" << endl; return -1; }
		sprite.setTexture(texture);
		break;
	case Niveau2:
		if (!texture.loadFromFile("enemy2.png")) { cout << "Erreur lors du chargement de texture d'ennemi niveau 2" << endl; return -1; }
		sprite.setTexture(texture);
		break;
	case Niveau3:
		if (!texture.loadFromFile("enemy3.png")) { cout << "Erreur lors du chargemnet de texture d'ennemi niveau 3" << endl; return -1; }
		sprite.setTexture(texture);
		break;
	default:
		break;
	}
	}
void Enemy::setAttackAndHP() {
	switch (level)
	{
	case Niveau1:
		Attack = 5;
		HP = 10;
		break;
	case Niveau2:
		Attack = 10;
		HP = 40;
		break;
	case Niveau3:
		Attack = 15;
		HP = 70;
		break;
	default:
		break;
	}
}





	EnemyManager::~EnemyManager() {
		for (auto enemy : enemies)
		{
			delete enemy;
		}
		enemies.clear();
	}

	Enemy* EnemyManager::creerEnemy(ennemi defLevel)
	{
		Enemy* e = new Enemy();
		e->level = defLevel;
		e->setTexture();
		e->setAttackAndHP();
		e->sprite.setPosition(HEIGHT / 1.5, WIDTH/4);
		e->sprite.rotate(-90);
		e->sprite.setScale(2, 2);
		enemies.push_back(e);
		return e;
	}
	void EnemyManager::detruireEnemy(Enemy* enemy) {
		auto it = find(enemies.begin(), enemies.end(), enemy);
		if (it != enemies.end()) {
			delete* it;
			enemies.erase(it);
		}
	}


	void EnemyManager::checkEnemy(Enemy* enemy)
	{
		if (enemy->HP < 1)
		{
			detruireEnemy(enemy);
		}
	}
	vector<Enemy* > EnemyManager::getEnemies() {
		return enemies;
	}

