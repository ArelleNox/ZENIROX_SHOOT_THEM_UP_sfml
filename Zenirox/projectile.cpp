#include <iostream>
#include <SFML/Graphics.hpp>
#include "projectile.hpp"
#include "enemy.hpp"
#include "player.hpp"
using namespace sf;

Projectile::Projectile() {};
Projectile::~Projectile() { std::cout << "Projectile detruit" << std::endl; }
void Projectile::setProjectile() {
	sprite.setRadius(4);
	sprite.setFillColor(Color::Red);
}

ProjectileManager::~ProjectileManager() {
		for (auto projectile : projectiles)
		{
			delete projectile;
		}
		projectiles.clear();
	}
	Projectile* ProjectileManager::creerProjectile() {
			Projectile* p = new Projectile();
			p->setProjectile();
			projectiles.push_back(p);
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
				if (projectile->sprite.getGlobalBounds().intersects(manager.getEnemies()[i]->sprite.getGlobalBounds()))
				{
					detruireProjectile(projectile);
					manager.getEnemies()[i]->HP -= player.attack;
					break;
				}
			}
	}


