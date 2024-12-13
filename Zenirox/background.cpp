#include "background.hpp"
#include <iostream>
#include <stdexcept>

Background::Background(const std::string& texturePath, float speed)
    : scrollSpeed(speed) {
    if (!texture.loadFromFile(texturePath)) {
        throw std::runtime_error("Failed to load texture");
    }

    if (!texture2.loadFromFile(texturePath)) {
        throw std::runtime_error("Failed to load texture");
    }

    if (!texture3.loadFromFile(texturePath)) {
        throw std::runtime_error("Failed to load texture");
    }

    sprite.setTexture(texture);
    sprite.setPosition(0, 0);

    sprite2.setTexture(texture2);
    sprite2.setPosition(sprite.getGlobalBounds().width, 0);

    sprite3.setTexture(texture3);
    sprite3.setPosition(sprite2.getGlobalBounds().width, 0);
}

void Background::update(float deltaTime) {
    sprite.move(scrollSpeed * deltaTime, 0);
    sprite2.move(scrollSpeed * deltaTime, 0);
    sprite3.move(scrollSpeed * deltaTime, 0);

    if (sprite.getPosition().x + sprite.getGlobalBounds().width <= 0) {
        sprite.setPosition(sprite2.getPosition().x + sprite2.getGlobalBounds().width, 0);
    }
    if (sprite2.getPosition().x + sprite2.getGlobalBounds().width <= 0) {
        sprite2.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width, 0);
    }
    if (sprite3.getPosition().x + sprite3.getGlobalBounds().width <= 0) {
        sprite3.setPosition(sprite.getPosition().x + sprite2.getGlobalBounds().width, 0);
    }
}

void Background::draw(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(sprite2);
    window.draw(sprite3);
}

// Setup for Palier 1
void Background::setupPalier1() {
    if (!texture.loadFromFile("palier1.png")) {
        std::cerr << "Error loading texture for Palier 1" << std::endl;
    }
    sprite.setTexture(texture);

    if (!texture.loadFromFile("palier11.png")) {
        std::cerr << "Error loading texture for Palier 1" << std::endl;
    }
    sprite2.setTexture(texture2);

    if (!texture.loadFromFile("palier11.png")) {
        std::cerr << "Error loading texture for Palier 1" << std::endl;
    }
    sprite3.setTexture(texture3);
}

// Setup for Palier 2
void Background::setupPalier2() {
    if (!texture.loadFromFile("palier22.png")) {
        std::cerr << "Error loading texture for Palier 2" << std::endl;
    }
    sprite.setTexture(texture);
}

// Setup for Palier 3
void Background::setupPalier3() {
    if (!texture.loadFromFile("palier3.jpg")) {
        std::cerr << "Error loading texture for Palier 3" << std::endl;
    }
    sprite.setTexture(texture);

    if (!texture.loadFromFile("palier33.jpg")) {
        std::cerr << "Error loading texture for Palier 3" << std::endl;
    }
    sprite2.setTexture(texture2);
}

// Setup for Palier 4
void Background::setupPalier4() {
    if (!texture.loadFromFile("palier4.jpg")) {
        std::cerr << "Error loading texture for Palier 4" << std::endl;
    }
    sprite.setTexture(texture);
}
