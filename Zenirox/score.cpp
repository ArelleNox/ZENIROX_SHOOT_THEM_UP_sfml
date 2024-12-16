#include "score.hpp"
#include "player.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

using namespace std;
using namespace sf;

int setCurrentScoreText(Player player, Font &scoreFont, Text &scoreText)
{
	scoreText.setString("Score: " + to_string(player.currentScore));
	scoreText.setFillColor(Color::White);
	scoreText.setOutlineColor(Color::Black);
	scoreText.setOutlineThickness(4);
	scoreText.setPosition(0, 50);

	if (!scoreFont.loadFromFile("font.otf")) { cout << "Erreur lors du chargement de la police d'ecriture" << endl; return -1; }
	scoreText.setFont(scoreFont);
}
int setTotalScoreText(Player player, Font& scoreFont, Text& scoreText)
{
	scoreText.setString("       " + to_string(player.totalScore));
	scoreText.setFillColor(Color::White);
	scoreText.setOutlineColor(Color::Black);
	scoreText.setOutlineThickness(4);
	scoreText.setCharacterSize(60);
	scoreText.setPosition(800, 500);

	if (!scoreFont.loadFromFile("font.otf")) { cout << "Erreur lors du chargement de la police d'ecriture" << endl; return -1; }
	scoreText.setFont(scoreFont);
}
void updateScoreText(Player player, Text& scoreText)
{
	scoreText.setString("       " + to_string(player.currentScore));
}
void openScore(Player &player) {
	ifstream scoreFile("score.txt");
	int totalScore;
	scoreFile >> totalScore;
	player.totalScore = totalScore;
}
void saveScore(Player player)
{
	ofstream scoreFile("score.txt");
	scoreFile << player.totalScore;
}
void saveCurrentScore(Player& player)
{
	player.totalScore += player.currentScore;
}