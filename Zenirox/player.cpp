#include "player.hpp"
#include <iostream>
#include "globalvar.hpp"
using namespace std;


int Player::setSprite() {
	if (!texture.loadFromFile("ship.png")) { cout << "Texture du vaisseau de joueur de base non trouvee" << endl; return -1; }
	sprite.setTexture(texture);
	sprite.rotate(90);
	sprite.setPosition(200, HEIGHT / 2);
}

Player::Player() : attackCooldown(seconds(0.2)), boostDuration(seconds(2.5)) {
	if (!impactB.loadFromFile("sounds/hit.ogg")) throw runtime_error("Erreur de chargement du son d'impact");
	impact.setBuffer(impactB);
	if (!bonusB.loadFromFile("sounds/boost.ogg")) throw runtime_error("Erreur de chargement du son de bonus");
	if (!malusB.loadFromFile("sounds/malus.ogg")) throw runtime_error("Erreur de chargement du son de malus");
	bonus.setBuffer(bonusB);
	malus.setBuffer(malusB);
	if (difficulty == Easy)
	{
		HP = 2000;
		maxHP = 2000;
		maxShield = 1000;
	}
	if (difficulty == Hardcore)
	{
		HP = 500;
		maxHP = 500;
		maxShield == 250;
	}
}

void Player::checkOutOfScreen() {
	if (sprite.getPosition().y < MAXHEIGHT)
		sprite.setPosition(sprite.getPosition().x, MAXHEIGHT);
	else if (sprite.getPosition().y > HEIGHT - sprite.getGlobalBounds().height)
		sprite.setPosition(sprite.getPosition().x, HEIGHT-sprite.getGlobalBounds().height);
	
}
void Player::increaseScore(int toIncrease)
{
	score += toIncrease;
}
void Player::decreaseScore(Text& scoreText, int toDecrease)
{
	score -= toDecrease;
	if (score < 0)
		score = 0;
}