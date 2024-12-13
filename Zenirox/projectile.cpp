#include <iostream>
#include <SFML/Graphics.hpp>
#include "projectile.hpp"
#include "enemy.hpp"
#include "player.hpp"
#include "score.hpp"
using namespace sf;

Projectile::Projectile() {};
Projectile::~Projectile() { std::cout << "Projectile detruit" << std::endl; }

int Projectile::setProjectile() {
	if(id == PLAYER)
	{
		if (!texture.loadFromFile("projectiles/11.png")) { cout << "Erreur chargement projectile joueur" << endl; return -1; }
	}
	else
	{
		if (!texture.loadFromFile("projectiles/14.png")) { cout << "Erreur chargement projectile ennemis" << endl; return -1; }
	}
	sprite.setTexture(texture);
	sprite.setScale(0.3 , 0.3);
		
}

ProjectileManager::~ProjectileManager() {
		for (auto projectile : projectiles)
		{
			delete projectile;
		}
		projectiles.clear();
	}
	Projectile* ProjectileManager::creerProjectile(Player player) {
			Projectile* p = new Projectile();
			p->sprite.setOrigin(p->sprite.getGlobalBounds().width / 2, p->sprite.getGlobalBounds().height / 2);
			p->id = player.id;
			p->setProjectile();
			projectiles.push_back(p);
			return p;
	}

	Projectile* ProjectileManager::creerProjectile(Enemy* enemy, int defVelocity) {
		Projectile* p = new Projectile();
		p->sprite.setOrigin(p->sprite.getGlobalBounds().width, p->sprite.getGlobalBounds().height / 2);
		p->sprite.rotate(180);
		p->id = enemy->id;
		p->setProjectile();
		p->velocity = defVelocity;
		projectiles.push_back(p);
		switch (enemy->id)
		{
		case ENNEMI1:
			p->sprite.setPosition(enemy->sprite.getPosition().x, enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height -60);
			break;
		case ENNEMI2:
			p->sprite.setPosition(enemy->sprite.getPosition().x, enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height - 85);
			break;
		case ENNEMI3:
			p->sprite.setPosition(enemy->sprite.getPosition().x, enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height - 135);
			break;
		case BOSS1:
			p->sprite.setPosition(enemy->sprite.getPosition().x, enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height -70);
			break;
		case BOSS2:
			p->sprite.setPosition(enemy->sprite.getPosition().x, enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height -140);
			break;
		case BOSS3:
			p->sprite.setPosition(enemy->sprite.getPosition().x, enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height -68);
			break;
		case BOSS4:
			p->sprite.setPosition(enemy->sprite.getPosition().x, enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height - 110);
			break;
		default:
			break;
		}
		return p;
	}
	void ProjectileManager::detruireProjectile(Projectile* projectile)
	{
		auto it = find(projectiles.begin(), projectiles.end(), projectile);
		if (it != projectiles.end()) {
			delete* it;
			projectiles.erase(it);
		}
	}
	vector<Projectile*> ProjectileManager::getProjectiles() { return projectiles; }

	void ProjectileManager::checkProjectileOutOfScreen(Projectile* projectile, EnemyManager &manager, Player &player, Text &scoreText) {
		if (projectile->sprite.getPosition().y > HEIGHT || projectile->sprite.getPosition().y < 0 || projectile->sprite.getPosition().x > WIDTH || projectile->sprite.getPosition().x < 0)
		detruireProjectile(projectile);
		else
			for (auto i = 0; i < manager.getEnemies().size(); i++)
			{
				if (projectile->sprite.getGlobalBounds().intersects(manager.getEnemies()[i]->sprite.getGlobalBounds()) && projectile->id == PLAYER)
				{
					detruireProjectile(projectile);
					if (manager.getEnemies()[i]->shield == 0)
						manager.getEnemies()[i]->HP -= player.attack;
					else
						manager.getEnemies()[i]->shield -= player.attack;
					player.increaseScore(5);
					if (manager.getEnemies()[i]->HP <= 0 && manager.getEnemies()[i]->id != BOSS1 && manager.getEnemies()[i]->id != BOSS2 && manager.getEnemies()[i]->id != BOSS3 && manager.getEnemies()[i]->id != BOSS4)
						player.increaseScore(100);
					else if (manager.getEnemies()[i]->HP <= 0 && manager.getEnemies()[i]->id != ENNEMI1 && manager.getEnemies()[i]->id != ENNEMI2 && manager.getEnemies()[i]->id != ENNEMI3)
						player.increaseScore(200);
					break;
				}
				if (projectile->sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()) && projectile->id != PLAYER)
				{
					
					detruireProjectile(projectile);
					if (player.shield == 0)
						player.HP -= manager.getEnemies()[i]->AttackDamages;
					else
						player.shield -= manager.getEnemies()[i]->AttackDamages;
					
					break;
				}
				
			}
	}


