#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"
using namespace std;
using namespace sf;

class Obstacle {
public:
	Sprite sprite;
	Texture texture;
	Clock damageClock;
	Time damageCooldown = seconds(2);
	float velocity = 5;
	int damages = 10;
	Obstacle();
	~Obstacle();
	void setTexture();
	void moveObstacle();
	void checkObstacle(Player& player);
};

class ObstacleManager {
private:
	vector<Obstacle*> obstacles;
public:
	~ObstacleManager();
	Obstacle* creerObstacle(float width, float height);
	void detruireObstacle(Obstacle* obstacle);
	vector<Obstacle* > getObstacles();
};





#endif