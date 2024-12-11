#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Obstacle {
public:
	Sprite sprite;
	Texture texture;
	float velocity;
	int damages;
	Obstacle(Texture texture, Sprite sprite, float velocity, int damages);
	~Obstacle();
};

class ObstacleManager {
private:
	vector<Obstacle*> obstacles;
public:
	~ObstacleManager();
	Obstacle* creerObstacle(float width, float height);
	void detruireObstacle(Obstacle* obstacle);
	void checkObstacle(Obstacle* obstacle);
	vector<Obstacle* > getObstacles();
};





#endif