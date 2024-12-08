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

Player::Player() : attackCooldown(seconds(0.2)) {}

void Player::checkOutOfScreen() {
	if (sprite.getPosition().y < 0)
		sprite.setPosition(sprite.getPosition().x, 0);
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