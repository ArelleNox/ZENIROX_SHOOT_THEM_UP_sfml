#include "player.hpp"
#include <iostream>
using namespace std;



int Player::setSprite() {
	if (!texture.loadFromFile("ship.png")) { cout << "Texture du vaisseau de joueur de base non trouvee" << endl; return -1; }
	sprite.setTexture(texture);
	sprite.rotate(90);
	sprite.setPosition(200, HEIGHT / 2);
}

Player::Player() : attackCooldown(seconds(0.2)) {}