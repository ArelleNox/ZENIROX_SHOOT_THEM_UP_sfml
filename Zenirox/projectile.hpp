#ifndef CLASS_HPP
#define CLASS_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include "enemy.hpp"
#include "player.hpp"
using namespace sf;
using namespace std;

const float HEIGHT = 1080;
const float WIDTH = 1920;

class Projectile {
public:
	CircleShape sprite;
	Projectile();
	~Projectile();
	void setProjectile();
};

class ProjectileManager {
private:
	vector<Projectile*> projectiles;
public:
	~ProjectileManager();
	Projectile* creerProjectile();
	void detruireProjectile(Projectile* projectile);
	void checkProjectileOutOfScreen(Projectile* projectile, EnemyManager &manager, Player &player);
	void checkProjectileCollisions(Projectile* projectile, EnemyManager& manager, Player& player);
	vector<Projectile* > getProjectiles();
};

#endif
