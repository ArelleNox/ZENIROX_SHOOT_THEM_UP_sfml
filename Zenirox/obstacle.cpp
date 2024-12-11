#include "obstacle.hpp"
#include "globalvar.hpp"


Obstacle::Obstacle(){}
Obstacle::~Obstacle() { cout << "Un obstacle a ete detruit" << endl; }
void Obstacle::setTexture() {
	if (!texture.loadFromFile("meteor.png")) { throw runtime_error("Impossible de charger la texture de l'obstacle"); }
	sprite.setTexture(texture);
}
void Obstacle::moveObstacle()
{
	sprite.move(-velocity, 0);
	if (sprite.getPosition().x < -500)
	{
		sprite.setPosition(WIDTH + 3000, sprite.getPosition().y);
	}
}

void Obstacle::checkObstacle(Player& player)
{
	if (sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()) && damageClock.getElapsedTime().asSeconds() > damageCooldown.asSeconds())
	{
		player.HP -= 10;
		damageClock.restart();
	}
}


ObstacleManager::~ObstacleManager()
{
	for (auto obstacle : obstacles)
	{
		delete obstacle;
	}
	obstacles.clear();
}

Obstacle* ObstacleManager::creerObstacle(float width, float height) {
	Obstacle* o = new Obstacle();
	o->setTexture();
	o->sprite.setPosition(width, height);
	o->sprite.setScale(0.5, 0.5);
	obstacles.push_back(o);
	return o;
	
}

vector<Obstacle*> ObstacleManager::getObstacles()
{
	return obstacles;
}
void ObstacleManager::detruireObstacle(Obstacle* obstacle)
{
	auto it = find(obstacles.begin(), obstacles.end(), obstacle);
	if (it != obstacles.end()) {
		delete* it;
		obstacles.erase(it);
	}
}
