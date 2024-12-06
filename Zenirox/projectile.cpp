#include <iostream>
#include <SFML/Graphics.hpp>
#include "projectile.hpp"
#include "enemy.hpp"
#include "player.hpp"
using namespace sf;

Projectile::Projectile() {};
Projectile::~Projectile() { std::cout << "Projectile detruit" << std::endl; }
int Projectile::setProjectile() {
	if(id == PLAYER)
	{
		if (!texture.loadFromFile("projectiles/01.png")) { cout << "Erreur chargement projectile joueur" << endl; return -1; }
	}
	else
	{
		if (!texture.loadFromFile("projectiles/02.png")) { cout << "Erreur chargement projectile ennemis" << endl; return -1; }
	}
	sprite.setTexture(texture);
	sprite.setScale(0.5 , 0.5);
		
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
		case Niveau1:
			p->sprite.setPosition(enemy->sprite.getPosition().x, enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height -50);
			break;
		case Niveau2:
			p->sprite.setPosition(enemy->sprite.getPosition().x, enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height - 70);
			break;
		case Niveau3:
			p->sprite.setPosition(enemy->sprite.getPosition().x, enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height - 125);
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

	void ProjectileManager::checkProjectileOutOfScreen(Projectile* projectile, EnemyManager &manager, Player &player) {
		if (projectile->sprite.getPosition().y > HEIGHT || projectile->sprite.getPosition().y < 0 || projectile->sprite.getPosition().x > WIDTH || projectile->sprite.getPosition().x < 0)
		detruireProjectile(projectile);
		else
			for (auto i = 0; i < manager.getEnemies().size(); i++)
			{
				if (projectile->sprite.getGlobalBounds().intersects(manager.getEnemies()[i]->sprite.getGlobalBounds()) && projectile->id == PLAYER)
				{
					detruireProjectile(projectile);
					manager.getEnemies()[i]->HP -= player.attack;
					break;
				}
				if (projectile->sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()) && projectile->id != PLAYER)
				{
					detruireProjectile(projectile);
					player.HP -= manager.getEnemies()[i]->AttackDamages;
					break;
				}
				
			}
	}


