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
	Sprite sprite;
	Texture texture;
	ID id;
	int velocity;
	Projectile();
	~Projectile();
	int setProjectile();
};

class ProjectileManager {
private:
	vector<Projectile*> projectiles;
public:
	~ProjectileManager();
	Projectile* creerProjectile(Player player);
	Projectile* creerProjectile(Enemy* enemy, int defVelocity);
	void detruireProjectile(Projectile* projectile);
	void checkProjectileOutOfScreen(Projectile* projectile, EnemyManager &manager, Player &player, Text &scoreText);
	vector<Projectile* > getProjectiles();
};

#endif
