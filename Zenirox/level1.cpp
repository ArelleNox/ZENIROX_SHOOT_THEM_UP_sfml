#include "level1.hpp"       
#include <stdexcept>           // Pour la gestion des exceptions

Level1::() {}

Level1::~Level1() {}

int Level1::level1() {
    // Création d'une fenêtre
    sf::RenderWindow window(sf::VideoMode(600, 800), "Flappy Bird");

    // Charger une texture
    sf::Texture background;
    if (!background.loadFromFile("background2.png")) {
        throw std::runtime_error("Erreur : texture de l'arrière-plan introuvable.");
    }

    // Associer la texture à un rectangle
    sf::RectangleShape back(sf::Vector2f(600, 800));
    back.setTexture(&background);
    back.setPosition(0, 0);


    return 0;
}