#include "powerups.hpp"

Utilitary::Utilitary() {}
Utilitary::~Utilitary() { cout << "Un powerup de heal a ete detruit" << endl; }
void Utilitary::setTexture() {
	if(type == heart)
		if (!texture.loadFromFile("heartboost.png")) { throw runtime_error("Impossible de charger la texture de heal"); }
	if(type == evilHeart)
		if (!texture.loadFromFile("heartnerf.png")) { throw runtime_error("Impossible de charger la texture de heal ennemi"); }
	if(type == battery)
		if (!texture.loadFromFile("cooldownboost.png")) { throw runtime_error("Impossible de charger la texture de boost de cooldown"); }
	if(type == evilBattery)
		if (!texture.loadFromFile("cooldownnerf.png")) { throw runtime_error("Impossible de charger la texture de boost du cooldown ennemi"); }
	if(type == shield)
		if(!texture.loadFromFile("shield.png")) { throw runtime_error("Impossible de charger la texture de boost du shield"); }
	if(type == evilShield)
		if(!texture.loadFromFile("evilshield.png")) { throw runtime_error("Impossible de charger la texture de shield ennemi"); }
	sprite.setTexture(texture);
}
void Utilitary::moveUtilitary()
{
	sprite.move(-velocity, 0);
}


UtilitaryManager::~UtilitaryManager()
{
	for (auto h : utilitaryList)
	{
		delete h;
	}
	utilitaryList.clear();
}

Utilitary* UtilitaryManager::creerUtilitary(Powerup defType, float width, float height) {
	Utilitary* h = new Utilitary();
	h->type = defType;
	h->setTexture();
	h->sprite.setPosition(width, height);
	h->sprite.setScale(0.5,0.5);
	if (defType == shield || defType == evilShield)
		h->sprite.setScale(1, 1);
	utilitaryList.push_back(h);
	return h;

}

vector<Utilitary*> UtilitaryManager::getUtilitaryList()
{
	return utilitaryList;
}
void UtilitaryManager::detruireUtilitary(Utilitary* h)
{
	auto it = find(utilitaryList.begin(), utilitaryList.end(), h);
	if (it != utilitaryList.end()) {
		delete* it;
		utilitaryList.erase(it);
	}
}
void UtilitaryManager::checkUtilitary(Utilitary* h, Player& player, EnemyManager& eManager)
{
	cout << h->sprite.getPosition().x << endl;
	if (h->sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()))
	{
		if(h->type == heart)
		{
			player.HP += (player.maxHP*0.5);
			if (player.HP >= player.maxHP)
				player.HP = player.maxHP;
			cout << player.HP;
		}
		if (h->type == evilHeart)
		{
			for (int i = 0; i < eManager.getEnemies().size(); i++)
			{
				eManager.getEnemies()[i]->HP += eManager.getEnemies()[i]->maxHP * 0.5;
				if (eManager.getEnemies()[i]->HP > eManager.getEnemies()[i]->maxHP)
					eManager.getEnemies()[i]->HP = eManager.getEnemies()[i]->maxHP;
			}
		}
		if (h->type == battery)
		{
			player.canBeBoosted = true;
			player.boostClock.restart();
		}
		if (h->type == evilBattery)
		{
			for (int i = 0; i < eManager.getEnemies().size(); i++)
			{
				eManager.getEnemies()[i]->canBeBoosted = true;
				eManager.getEnemies()[i]->boostClock.restart();
			}
		}
		if (h->type == shield)
		{
			player.shield = player.maxShield;
		}
		if (h->type == evilShield)
		{
			for (int i = 0; i < eManager.getEnemies().size(); i++)
			{
				if (eManager.getEnemies()[i]->id == ENNEMI1 || eManager.getEnemies()[i]->id == ENNEMI2 || eManager.getEnemies()[i]->id == ENNEMI3 || eManager.getEnemies()[i]->id == BOSS1 || eManager.getEnemies()[i]->id == BOSS2)
				{
					eManager.getEnemies()[i]->maxShield = eManager.getEnemies()[i]->maxHP * 0.5;
				}
				eManager.getEnemies()[i]->shield = eManager.getEnemies()[i]->maxShield;
			}
		}
		detruireUtilitary(h);
	}
	if (h->sprite.getPosition().x < -500)
	{
		detruireUtilitary(h);
	}

}
