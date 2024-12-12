#include "background.hpp"
#include "globalvar.hpp"
#include <iostream>
using namespace std;

int Background::setTexture() {
	switch (pal)
	{
	case palier1:
		if (!texture.loadFromFile("palier1.png")) { cout << "Erreur lors du chargement de texture du palier 1" << endl; return -1; }
		sprite.setTexture(texture);
		break;
	case palier2:
		if (!texture.loadFromFile("palier2.jpg")) { cout << "Erreur lors du chargement de texture du palier 2" << endl; return -1; }
		sprite.setTexture(texture);
		break;
	case palier3:
		if (!texture.loadFromFile("palier3.jpg")) { cout << "Erreur lors du chargement de texture du palier 3" << endl; return -1; }
		sprite.setTexture(texture);
		break;
	case palier4:
		if (!texture.loadFromFile("palier4.jpg")) { cout << "Erreur lors du chargement de texture du palier 4" << endl; return -1; }
		sprite.setTexture(texture);
		break;
	default:
		break;
	}
}


Background::Background(const std::string&texturePath, float speed)
    : scrollSpeed(speed) {
    if (!texture.loadFromFile(texturePath)) {
		throw std::runtime_error("Failed to load texture");
    }

	if (!texture2.loadFromFile(texturePath)) {
		throw std::runtime_error("Failed to load texture");
	}

    sprite.setTexture(texture);
    sprite.setPosition(0, 0); // Initial position

	sprite2.setTexture(texture2);
	sprite2.setPosition(sprite.getGlobalBounds().width, 0);


}

void Background::update(float deltaTime) {
    // Move the sprite to the right
    sprite.move(scrollSpeed * deltaTime, 0);
	sprite2.move(scrollSpeed * deltaTime, 0);

	if (sprite.getPosition().x + sprite.getGlobalBounds().width <= 0) {
		sprite.setPosition(sprite2.getPosition().x + sprite2.getGlobalBounds().width, 0);
	}
	if (sprite2.getPosition().x + sprite2.getGlobalBounds().width <= 0) {
		sprite2.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width, 0);
	}
}

void Background::draw(sf::RenderWindow& window) {
    window.draw(sprite);
	window.draw(sprite2);
}