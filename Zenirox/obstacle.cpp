#include "obstacle.hpp"


Obstacle::Obstacle(Texture texture, Sprite sprite, float velocity, int damages)
{
	texture.loadFromFile("meteor.png");
	sprite.setTexture(texture);
	velocity = 3;
	damages = 10;
}
Obstacle::~Obstacle() { cout << "Un obstacle a ete detruit" << endl; }


ObstacleManager::~ObstacleManager()
{
	for (auto obstacle : obstacles)
	{
		delete obstacle;
	}
	obstacles.clear();
}
vector<Obstacle*> ObstacleManager::getObstacles()
{
	return obstacles;
}
