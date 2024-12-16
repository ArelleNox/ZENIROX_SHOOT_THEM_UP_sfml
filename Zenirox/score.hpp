#ifndef SCORE_HPP
#define SCORE_HPP
#include <SFML/Graphics.hpp>
#include "player.hpp"
using namespace sf;


int setCurrentScoreText(Player player, Font &textFont, Text &scoreText);
int setTotalScoreText(Player player, Font& textFont, Text& scoreText);
void updateScoreText(Player player, Text& scoreText);
void openScore(Player &player);
void saveScore(Player player);
void saveCurrentScore(Player &player);
#endif
