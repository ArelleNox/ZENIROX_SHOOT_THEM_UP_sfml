#include "score.hpp"
#include "player.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

using namespace std;
using namespace sf;

int setScoreText(Player player, Font &scoreFont, Text &scoreText)
{
	scoreText.setString("Score: " + to_string(player.score));
	scoreText.setFillColor(Color::White);
	scoreText.setOutlineColor(Color::Black);
	scoreText.setOutlineThickness(4);

	if (!scoreFont.loadFromFile("font.otf")) { cout << "Erreur lors du chargement de la police d'ecriture" << endl; return -1; }
	scoreText.setFont(scoreFont);
}
void updateScoreText(Player player, Text& scoreText)
{
	scoreText.setString("Score: " + to_string(player.score));
}
void openScore(Player &player) {
	ifstream scoreFile("score.txt");
	int score;
	scoreFile >> score;
	player.score = score;
}
void saveScore(Player player)
{
	ofstream scoreFile("score.txt");
	scoreFile << player.score;
}
