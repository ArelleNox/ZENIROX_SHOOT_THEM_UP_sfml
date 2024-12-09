#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <SFML/Graphics.hpp>

enum palier {
    palier1 = 1,
    palier2 = 2,
    palier3 = 3,
    palier4 = 4,
};

class Background {
private:

    
    float scrollSpeed;

public:
    sf::Texture texture;
    sf::Texture texture2;
    sf::Sprite sprite;
    sf::Sprite sprite2;
    int setTexture();
    palier pal;
    Background(const std::string& texturePath, float speed);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
};

#endif