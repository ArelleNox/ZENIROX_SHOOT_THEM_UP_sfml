#ifndef PARALLAXE_HPP
#define PARALLAXE_HPP
#include "globalvar.hpp"
#include "game.hpp"
#include <SFML/Graphics.hpp>

class Starparallaxe {
private:

    float starSpeed;

public:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Sprite sprite2;
    Starparallaxe(const std::string& texturePath, float speed);
    void startexture();
    void cloudtexture();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
};

#endif