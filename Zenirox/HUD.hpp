#ifndef HUD_HPP
#define HUD_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class HUD {
private:
    sf::Font font;
    std::vector<sf::Text> menuItems;
    int selectedItemIndex;

public:
    HUD();
    ~HUD() = default;

    void loadFont(const std::string& fontPath);
    void setupMenu(const std::vector<std::string>& options, float startX, float startY, float spacing);
    void handleInput(const sf::Event& event);
    void render(sf::RenderWindow& window);

    int getSelectedItemIndex() const;
};

#endif // HUD_HPP
