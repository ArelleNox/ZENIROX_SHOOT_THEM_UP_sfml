#include "HUD.hpp"       
#include <stdexcept>    

HUD::HUD() : selectedItemIndex(0) {}

void HUD::loadFont(const std::string& fontPath) {
    if (!font.loadFromFile(fontPath)) {
        throw std::runtime_error("Failed to load font");
    }
}

void HUD::setupMenu(const std::vector<std::string>& options, float startX, float startY, float spacing) {
    for (size_t i = 0; i < options.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(options[i]);
        text.setCharacterSize(30);
        text.setFillColor(i == 0 ? sf::Color::Red : sf::Color::White);
        text.setPosition(startX, startY + i * spacing);
        menuItems.push_back(text);
    }
}

void HUD::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            menuItems[selectedItemIndex].setFillColor(sf::Color::White);
            selectedItemIndex = (selectedItemIndex - 1 + menuItems.size()) % menuItems.size();
            menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
        }
        else if (event.key.code == sf::Keyboard::Down) {
            menuItems[selectedItemIndex].setFillColor(sf::Color::White);
            selectedItemIndex = (selectedItemIndex + 1) % menuItems.size();
            menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
        }
    }
}

void HUD::render(sf::RenderWindow& window) {
    for (const auto& item : menuItems) {
        window.draw(item);
    }
}

int HUD::getSelectedItemIndex() const {
    return selectedItemIndex;
}

