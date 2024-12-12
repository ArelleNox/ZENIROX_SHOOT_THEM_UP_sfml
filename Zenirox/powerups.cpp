#include "powerups.hpp"

Utilitary::Utilitary() {}
Utilitary::~Utilitary() { cout << "Un powerup de heal a ete detruit" << endl; }
void Utilitary::setTexture() {
	if(type == heart)
		if (!texture.loadFromFile("heartboost.png")) { throw runtime_error("Impossible de charger la texture de heal"); }
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
	h->type == defType;
	h->setTexture();
	h->sprite.setPosition(width, height);
	h->sprite.setScale(0.5,0.5);
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
void UtilitaryManager::checkUtilitary(Utilitary* h, Player& player)
{
	if (h->sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()))
	{
		if(h->type == heart)
			player.HP += player.maxHP * 0.5;
		detruireUtilitary(h);
	}
	if (h->sprite.getPosition().x < -500)
		detruireUtilitary(h);

}
