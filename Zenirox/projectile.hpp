#ifndef CLASS_HPP
#define CLASS_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include "enemy.hpp"
#include "player.hpp"
#include "globalvar.hpp"
using namespace sf;
using namespace std;


class Projectile {
public:
	CircleShape sprite;
	ID id;
	Projectile();
	~Projectile();
	void setProjectile();
};

class ProjectileManager {
private:
	vector<Projectile*> projectiles;
public:
	~ProjectileManager();
	Projectile* creerProjectile(Player player);
	Projectile* creerProjectile(Enemy* enemy);
	void detruireProjectile(Projectile* projectile);
	void checkProjectileOutOfScreen(Projectile* projectile, EnemyManager &manager, Player &player);
	void checkProjectileCollisions(Projectile* projectile, EnemyManager& manager, Player& player);
	vector<Projectile* > getProjectiles();
};

#endif
