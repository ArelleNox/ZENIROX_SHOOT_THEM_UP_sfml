#include "parallaxe.hpp"

#include <iostream>
using namespace std;

Starparallaxe::Starparallaxe(const std::string& texturePath, float speed)
	: starSpeed(speed) {
	if (!texture.loadFromFile(texturePath)) {
		throw std::runtime_error("Failed to load texture");
	}

	sprite.setTexture(texture);
	sprite.setPosition(0, 0); // position initial

    sprite2.setTexture(texture);
    sprite2.setPosition(sprite.getGlobalBounds().width, 0); // Position it next to the first
}


void Starparallaxe::startexture() {
	if (!texture.loadFromFile("star.png")) {
		throw std::runtime_error("Failed to load texture");
	}
}

void Starparallaxe::cloudtexture() {
	if (!texture.loadFromFile("cloud.png")) {
		throw std::runtime_error("Failed to load texture");
	}
}

void Starparallaxe::update(float deltaTime) {
	
	sprite.move(starSpeed * deltaTime, 0);
    sprite2.move(starSpeed * deltaTime, 0);

    if (sprite.getPosition().x + sprite.getGlobalBounds().width <= 0) {
        sprite.setPosition(sprite2.getPosition().x + sprite2.getGlobalBounds().width, 0);
    }
    if (sprite2.getPosition().x + sprite2.getGlobalBounds().width <= 0) {
        sprite2.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width, 0);
    }
}



void Starparallaxe::draw(sf::RenderWindow& window) {
	window.draw(sprite);
	window.draw(sprite2);
}






    