#include "enemy.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>



int Enemy::setTexture() {
	switch (id)
	{
	case ENNEMI1:
		if (!texture.loadFromFile("enemy1.png")) { cout << "Erreur lors du chargement de texure d'ennemi niveau 1" << endl; return -1; }
		sprite.setTexture(texture);
		break;
	case ENNEMI2:
		if (!texture.loadFromFile("enemy2.png")) { cout << "Erreur lors du chargement de texture d'ennemi niveau 2" << endl; return -1; }
		sprite.setTexture(texture);
		break;
	case ENNEMI3:
		if (!texture.loadFromFile("enemy3.png")) { cout << "Erreur lors du chargement de texture d'ennemi niveau 3" << endl; return -1; }
		sprite.setTexture(texture);
		break;
	case BOSS1:
		if (!texture.loadFromFile("Boss1.png")) { cout << "Erreur lors du chargement de texture de boss niveau 1" << endl; return -1; }
		sprite.setTexture(texture);
		break;
	case BOSS2:
		if (!texture.loadFromFile("Boss2.png")) { cout << "Erreur lors du chargement de texture de boss niveau 2" << endl; return -1; }
		sprite.setTexture(texture);
		break;
	case BOSS3:
		if (!texture.loadFromFile("Boss3.png")) { cout << "Erreur lors du chargement de texture de boss niveau 3" << endl; return -1; }
		sprite.setTexture(texture);
		break;
	case BOSS4:
		if (!texture.loadFromFile("Boss4.png")) { cout << "Erreur lors du chargement de texture de boss niveau 4" << endl; return -1; }
		sprite.setTexture(texture);
		break;
	default:
		break;
	}
	}
void Enemy::setAttackAndHP() {
	switch (id)
	{
	case ENNEMI1:
		AttackDamages = 5;
		HP = 100;
		maxHP = 100;
		break;
	case ENNEMI2:
		AttackDamages = 10;
		HP = 200;
		maxHP = 200;
		break;
	case ENNEMI3:
		AttackDamages = 15;
		HP = 150;
		maxHP = 150;
		break;
	case BOSS1:
		AttackDamages = 10;
		HP = 400;
		maxHP = 400;
		break;
	case BOSS2:
		AttackDamages = 10;
		HP = 500;
		maxHP = 500;
		break;
	case BOSS3:
		AttackDamages = 10;
		HP = 600;
		maxHP = 600;
		shield = 200;
		maxShield = 200;
		break;
	case BOSS4:
		AttackDamages = 15;
		HP = 1000;
		maxHP = 1000;
		shield = 500;
		maxShield = 500;
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
	if (id == ENNEMI2 || id == ENNEMI3)
	{
		if (direction == up)
			sprite.move(-2, -velocity);
		else
			sprite.move(-2, velocity);
	}
	if (id == BOSS1 || id == BOSS2 || id == BOSS3 ||id == BOSS4)
	{
		if (direction == up)
			sprite.move(0, -velocity);
		else
			sprite.move(0, velocity);
	}
	if (id == ENNEMI1)
	{
		sprite.move(-2, 0);
	}
	if (sprite.getPosition().x < -500 && id != ENNEMI3)
	{
		sprite.setPosition(sprite.getPosition().x + WIDTH + 1000, sprite.getPosition().y);
	}
	if (sprite.getPosition().x < -500 && id == ENNEMI3)
	{
		sprite.setPosition(sprite.getPosition().x + WIDTH + 2000, sprite.getPosition().y);
	}
}




	EnemyManager::~EnemyManager() {
		for (auto enemy : enemies)
		{
			delete enemy;
		}
		enemies.clear();
	}

	Enemy* EnemyManager::creerEnemy(ID defLevel, float width, float height)
	{
		Enemy* e = new Enemy();
		e->id = defLevel;
		e->setTexture();
		e->setAttackAndHP();
		e->sprite.setPosition(width, height);
		e->sprite.setScale(2, 2);
		if (defLevel == BOSS2)
			e->sprite.setScale(1.5, 1.5);
		else if (defLevel == BOSS3)
			e->sprite.setScale(1, 1);
		else if (defLevel == BOSS4)
			e->sprite.setScale(1, 1);
		switch (defLevel)
		{
		case ENNEMI1:
			e->id = ENNEMI1;
			break;
		case ENNEMI2:
			e->id = ENNEMI2;
			break;
		case ENNEMI3:
			e->id = ENNEMI3;
			break;
		case BOSS1:
			e->id = BOSS1;
			break;
		case BOSS2:
			e->id = BOSS2;
			break;
		case BOSS3:
			e->id = BOSS3;
			break;
		case BOSS4:
			e->id = BOSS4;
		default:
			break;
		}
		switch (e->id)
		{
		case ENNEMI1:
			e->attackCooldown = seconds(3);
			e->rechargeCooldown = seconds(0);
			break;
		case ENNEMI2:
			e->attackCooldown = seconds(1.5);
			e->rechargeCooldown = seconds(0);
			break;
		case ENNEMI3:
			e->attackCooldown = seconds(1);
			e->rechargeCooldown = seconds(1);
			break;
		case BOSS1:
			e->attackCooldown = seconds(0.08);
			e->rechargeCooldown = seconds(2);
			e->velocity = 3;
			break;
		case BOSS2:
			e->attackCooldown = seconds(0.2);
			e->rechargeCooldown = seconds(2);
			e->velocity = 5;
			break;
		case BOSS3:
			e->attackCooldown = seconds(0.2);
			e->rechargeCooldown = seconds(2);
			break;
		case BOSS4:
			e->attackCooldown = seconds(0.02);
			e->rechargeCooldown = seconds(0.5);
			e->velocity = 7;
			break;
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


	void EnemyManager::checkEnemy(Enemy* enemy, int &toKill)
	{
		if (enemy->HP < 1)
		{
			detruireEnemy(enemy);
			--toKill;
		}
	}
	vector<Enemy* > EnemyManager::getEnemies() {
		return enemies;
	}

