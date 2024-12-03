#ifndef CLASS_HPP
#define CLASS_HPP
#include <SFML/Graphics.hpp>
#include <vector>
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
	void checkProjectile(Projectile* projectile);
	vector<Projectile* > getProjectiles();
};

#endif
