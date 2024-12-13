#include <iostream>
#include <ctime>
#include "projectile.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "Background.hpp"
#include "parallaxe.hpp"
#include "parallaxe2.hpp"
#include "score.hpp"
#include "healthbar.hpp"
#include "game.hpp"
#include "obstacle.hpp"
#include "HUD.hpp"
#include "powerups.hpp"

using namespace std;
using namespace sf;





int main() {
	srand(time(NULL));
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "ZENIROX", Style::Fullscreen);
	window.setFramerateLimit(240);
	window.setVerticalSyncEnabled(false);

	Game game;

	Player player;
	player.setSprite();
	player.attackCooldown = seconds(0.01);
	EnemyManager eManager;

	RectangleShape interface(Vector2f(1920, 95));
	interface.setFillColor(Color::White);

	Sprite coin;
	Texture coinTexture;
	if (!coinTexture.loadFromFile("coin.png")) { cout << "Erreur de chargement de la texture de piece" << endl; return -1; }
	coin.setTexture(coinTexture);
	coin.setScale(0.2, 0.2);
	coin.setPosition(0, 45);

	game.Univeau1A = true;
	Text scoreText;
	Font scoreFont;

	setScoreText(player, scoreFont, scoreText);

	Background background("palier22.png",-10.f);

	Starparallaxe star("star.png",-300.f);
	fastStarparallaxe faststar("star.png", -1500.f);

	Healthbar healthbar;
	healthbar.setTextureList();

	// Initialiser l'horloge pour gérer le deltaTime
	sf::Clock clock;

	ProjectileManager pManager;
	openScore(player);
	
	ObstacleManager oManager;

	UtilitaryManager uManager;

	
	while (window.isOpen())
	{
		//Chargement des niveaux
		game.run(window, player, coin, background, star, faststar, healthbar, eManager, pManager, oManager, uManager, clock, scoreText, scoreFont, interface);
		window.display();

	}
	saveScore(player);
	return 0;
}