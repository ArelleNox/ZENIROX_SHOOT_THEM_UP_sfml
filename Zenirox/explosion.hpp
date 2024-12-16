#ifndef EXPLOSION_HPP
#define EXPLOSION_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class Enemy;
class Player;

class Explosion {
public:
	Sprite sprite;
	Texture texture;
	Sound boom;
	SoundBuffer boomB;
	Clock explosionClock;
	Time frameDuration = seconds(0.05);
	int frame = 0;
	void setExplosion();
	void animate();
};

class ExplosionManager {
private:
	vector<Explosion* > explosions;
public:
	~ExplosionManager();
	Explosion* creerExplosion(Enemy* enemy);
	Explosion* creerExplosion(Player player);
	vector<Explosion* > getExplosions();
	void detruireExplosion(Explosion* explosion);
};

#endif 