#include "enemy.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>



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
		AttackDamages = 5;
		HP = 100;
		break;
	case Niveau2:
		AttackDamages = 10;
		HP = 200;
		break;
	case Niveau3:
		AttackDamages = 15;
		HP = 150;
		break;
	default:
		break;
	}
}

Enemy::Enemy() {}
Enemy::~Enemy() {
	{ cout << "Un ennemi a ete detruit" << endl; };
}
void Enemy::enemyMove() {
	if (sprite.getPosition().y < 0)
		direction = down;
	else if (sprite.getPosition().y > HEIGHT - sprite.getGlobalBounds().height)
		direction = up;
	if (id == Niveau2)
	{
		if (direction == up)
			sprite.move(0, -velocity);
		else
			sprite.move(0, velocity);
	}
	if (id == Niveau3)
	{
		if (direction == up)
			sprite.move(0, -velocity);
		else
			sprite.move(0, velocity);
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
		e->sprite.setScale(2, 2);
		switch (defLevel)
		{
		case Niveau1:
			e->id = ENNEMI1;
			break;
		case Niveau2:
			e->id = ENNEMI2;
			break;
		case Niveau3:
			e->id = ENNEMI3;
			break;
		default:
			break;
		}
		switch (e->id)
		{
		case ENNEMI1:
			e->attackCooldown = seconds(0.5);
			e->rechargeCooldown = seconds(0);
			break;
		case ENNEMI2:
			e->attackCooldown = seconds(0.5);
			e->rechargeCooldown = seconds(0);
			break;
		case ENNEMI3:
			e->attackCooldown = seconds(0.2);
			e->rechargeCooldown = seconds(1);
			break;
		case BOSS1:
			e->attackCooldown = seconds(0.08);
			e->rechargeCooldown = seconds(2);
			break;
		case BOSS2:
			e->attackCooldown = seconds(0.2);
			e->rechargeCooldown = seconds(0);
			break;
		case BOSS3:
			e->attackCooldown = seconds(0.2);
			e->rechargeCooldown = seconds(0);
			break;
		case BOSS4:
			e->attackCooldown = seconds(0.02);
			e->rechargeCooldown = seconds(2);
		}
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

