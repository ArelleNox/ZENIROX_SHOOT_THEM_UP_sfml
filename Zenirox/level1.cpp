#include "level1.hpp"       
#include <stdexcept>           // Pour la gestion des exceptions

Level1::Level1 () {}

Level1::~Level1() {}

int Level1::pal1_back() {
    // Cr�ation d'une fen�tre
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Flappy Bird");

    // Charger une texture
    sf::Texture background;
    if (!background.loadFromFile("palier1.png")) {
        throw std::runtime_error("Erreur : texture de l'arri�re-plan introuvable.");
    }

    // Associer la texture � un rectangle
    sf::RectangleShape back(sf::Vector2f(600, 800));
    back.setTexture(&background);
    back.setPosition(0, 0);


    return 0;
}