#include "player.hpp"
#include "enemy.hpp"
#include "explosion.hpp"
void Explosion::setExplosion()
{
	if (!texture.loadFromFile("explosion.png")) { throw runtime_error("Erreur de chargement des explosions"); }
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 133, 200));
	sprite.setPosition(0, 0);
	if (!boomB.loadFromFile("sounds/explosion.ogg")) { throw runtime_error("Erreur de chargement du bruit de l'explosion."); }
	boom.setBuffer(boomB);
	boom.play();
}
void Explosion::animate()
{
	if (explosionClock.getElapsedTime().asSeconds() > frameDuration.asSeconds() && frame <= 7)
	{
		explosionClock.restart();
		switch (frame)
		{
		case 0:
			sprite.setTextureRect(IntRect(0, 0, 133, 200));
			break;
		case 1: 
			sprite.setTextureRect(IntRect(133, 0, 133, 200));
			break;
		case 2:
			sprite.setTextureRect(IntRect(270, 0, 133, 200));
			break;
		case 3:
			sprite.setTextureRect(IntRect(400, 0, 133, 200));
			break;
		case 4:
			sprite.setTextureRect(IntRect(559, 0, 133, 200));
			break;
		case 5:
			sprite.setTextureRect(IntRect(690, 0, 133, 200));
			break;
		case 6:
			sprite.setTextureRect(IntRect(821, 0, 133, 200));
			break;
		default:
			break;
		}
	
		frame++;
		
	}
}

ExplosionManager::~ExplosionManager()
{
	for (auto Explosion : explosions)
	{
		delete Explosion;
	}
	explosions.clear();
}

Explosion* ExplosionManager::creerExplosion(Enemy* enemy) {
	Explosion* e = new Explosion();
	e->setExplosion();
	e->sprite.setPosition(enemy->sprite.getPosition().x, enemy->sprite.getPosition().y);
	explosions.push_back(e);
	return e;
}
Explosion* ExplosionManager::creerExplosion(Player player)
{
	Explosion* e = new Explosion();
	e->setExplosion();
	e->sprite.setPosition(player.sprite.getPosition().x, player.sprite.getPosition().y);
	explosions.push_back(e);
	return e;
}

vector<Explosion*> ExplosionManager::getExplosions()
{
	return explosions;
}
void ExplosionManager::detruireExplosion(Explosion* Explosion)
{
	auto it = find(explosions.begin(), explosions.end(), Explosion);
	if (it != explosions.end()) {
		delete* it;
		explosions.erase(it);
	}
}