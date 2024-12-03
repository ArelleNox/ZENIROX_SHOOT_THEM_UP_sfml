#include "player.hpp"
#include <iostream>
using namespace std;

const float HEIGHT = 1080;
const float WIDTH = 1920;

int Player::setSprite() {
	if (!texture.loadFromFile("ship.png")) { cout << "Texture du vaisseau de joueur de base non trouvee" << endl; return -1; }
	sprite.setTexture(texture);
	sprite.rotate(90);
	sprite.setPosition(200, HEIGHT / 2);
}