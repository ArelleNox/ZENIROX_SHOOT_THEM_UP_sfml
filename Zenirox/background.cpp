#include "Background.hpp"
#include "globalvar.hpp"
#include <iostream>
using namespace std;

int Background::setTexture() {
	switch (pal)
	{
	case palier1:
		if (!texture.loadFromFile("palier1.jpg")) { cout << "Erreur lors du chargement de texure d'ennemi niveau 1" << endl; return -1; }
		sprite.setTexture(texture);
		break;
	case palier2:
		if (!texture.loadFromFile("palier2.jpg")) { cout << "Erreur lors du chargement de texture d'ennemi niveau 2" << endl; return -1; }
		sprite.setTexture(texture);
		break;
	case palier3:
		if (!texture.loadFromFile("palier3.jpg")) { cout << "Erreur lors du chargemnet de texture d'ennemi niveau 3" << endl; return -1; }
		sprite.setTexture(texture);
		break;
	case palier4:
		if (!texture.loadFromFile("palier4.jpg")) { cout << "Erreur lors du chargemnet de texture d'ennemi niveau 3" << endl; return -1; }
		sprite.setTexture(texture);
		break;
	default:
		break;
	}
}
Background::Background(const std::string& pal, float speed)
    : scrollSpeed(speed) {
    if (!texture.loadFromFile(pal)) {
        throw std::runtime_error("Failed to load texture");
    }

	sf::RectangleShape sprite(sf::Vector2f(1920, 1080));
    sprite.setTexture(&texture);
    sprite.setPosition(0, 0); // Initial position
}

void Background::update(float deltaTime) {
    // Move the sprite slowly to the right
    sprite.move(scrollSpeed * deltaTime, 0);

    
    if (sprite.getPosition().x > sprite.getTexture()->getSize().x) {
        sprite.setPosition(sprite.getTexture()->getSize().x, 0);
    }
}

void Background::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}