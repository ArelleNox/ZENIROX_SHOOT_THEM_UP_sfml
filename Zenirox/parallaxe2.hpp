#ifndef PARALLAXE2_HPP
#define PARALLAXE2_HPP

#include <SFML/Graphics.hpp>

class fastStarparallaxe {
private:

    float starSpeed;

public:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Sprite sprite2;
    fastStarparallaxe(const std::string& texturePath, float speed);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
};

#endif