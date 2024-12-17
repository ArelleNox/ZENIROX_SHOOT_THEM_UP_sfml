#ifndef SCORE_HPP
#define SCORE_HPP
#include <SFML/Graphics.hpp>
#include "game.hpp"
using namespace sf;
class Game;
int setCurrentScoreText(Player player, Font &textFont, Text &scoreText);
int setTotalScoreText(Player player, Font& textFont, Text& scoreText);
void updateScoreText(Player player, Text& scoreText);
void openData(Player &player, Game &game);
void saveData(Player player, Game &game);
void saveCurrentScore(Player &player);
void removeData(Player& player, Game &game);
#endif
