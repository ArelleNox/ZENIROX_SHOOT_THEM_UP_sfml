#include "player.hpp"
#include <iostream>
#include "globalvar.hpp"
using namespace std;


int Player::setSprite() {
	switch (ship)
	{
	case Default:
		if (!texture.loadFromFile("ship.png")) { cout << "Texture du vaisseau de joueur de base non trouvee" << endl; return -1; }
		break;
	case Ship1:
		if (!texture.loadFromFile("ship1.png")) throw runtime_error("Erreur de chargement DLC1");
		break;
	case Ship2:
		if (!texture.loadFromFile("ship2.png")) throw runtime_error("Erreur de chargement DLC2");
		break;
	case Ship3:
		if (!texture.loadFromFile("ship3.png")) throw runtime_error("Erreur de chargement DLC3");
	default:
		break;
	}
	


	sprite.setTexture(texture);
	sprite.rotate(90);
	sprite.setPosition(200, HEIGHT / 2);
}
void Player::changeShip()
{
	switch (ship)
	{
	case Default:
		if (!texture.loadFromFile("ship.png")) throw runtime_error("Erreur de chargement ship par defaut");
		break;
	case Ship1:
		if (!texture.loadFromFile("ship1.png")) throw runtime_error("Erreur de chargement DLC1");
		break;
	case Ship2:
		if (!texture.loadFromFile("ship2.png")) throw runtime_error("Erreur de chargement DLC2");
		break;
	case Ship3:
		if (!texture.loadFromFile("ship3.png")) throw runtime_error("Erreur de chargement DLC3");
	default:
		break;
	}
	sprite.setTexture(texture);
}

Player::Player() : attackCooldown(seconds(0.2)), boostDuration(seconds(2.5)) {
	if (!impactB.loadFromFile("sounds/hit.ogg")) throw runtime_error("Erreur de chargement du son d'impact");
	impact.setBuffer(impactB);
	if (!bonusB.loadFromFile("sounds/boost.ogg")) throw runtime_error("Erreur de chargement du son de bonus");
	if (!malusB.loadFromFile("sounds/malus.ogg")) throw runtime_error("Erreur de chargement du son de malus");
	if (!buyB.loadFromFile("sounds/buy.ogg")) throw runtime_error("Erreur de chargement du son d'achat");
	bonus.setBuffer(bonusB);
	malus.setBuffer(malusB);
	buy.setBuffer(buyB);
	if (difficulty == Easy)
	{
		HP = 2000;
		maxHP = 2000;
		maxShield = 1000;
		attack = 20;
	}
	if (difficulty == Hardcore)
	{
		HP = 500;
		maxHP = 500;
		maxShield = 250;
	}
	HP = maxHP;
}

void Player::checkOutOfScreen() {
	if (sprite.getPosition().y < MAXHEIGHT)
		sprite.setPosition(sprite.getPosition().x, MAXHEIGHT);
	else if (sprite.getPosition().y > HEIGHT - sprite.getGlobalBounds().height)
		sprite.setPosition(sprite.getPosition().x, HEIGHT-sprite.getGlobalBounds().height);
	
}
void Player::increaseScore(int toIncrease)
{
	currentScore += toIncrease;
}
void Player::decreaseScore(Text& scoreText, int toDecrease)
{
	currentScore -= toDecrease;
	if (currentScore < 0)
		currentScore = 0;
}

void Player::setDifficulty(Difficulty defDifficulty)
{
	difficulty = defDifficulty;
	{
		if (difficulty == Easy)
		{
			maxHP = 2000;
			maxShield = 1000;
			attack = 200;
		}
		else if (difficulty == Normal)
		{
			maxHP = 1000;
			maxShield = 500;
			attack = 10;
		}
		else if (difficulty == Hardcore)
		{
			maxHP = 500;
			maxShield = 250;
			attack = 10;
		}
		HP = maxHP;
	}
}