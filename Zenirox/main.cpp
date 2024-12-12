#include <iostream>
#include <ctime>
#include "projectile.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "Background.hpp"
#include "parallaxe.hpp"
#include "score.hpp"
#include "healthbar.hpp"
#include "game.hpp"
#include "obstacle.hpp"
#include "powerups.hpp"

using namespace std;
using namespace sf;






int main() {
	srand(time(NULL));
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "ZENIROX", Style::Fullscreen);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	Game game;
	Player player;
	player.setSprite();
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

	Background background("palier1.png",-15.f);

	Starparallaxe star("star.png",-300.f);

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

		game.level1A(player, eManager, oManager, pManager, uManager);
		game.level1B(player, eManager, oManager, pManager, uManager);
		game.level1C(player, eManager, oManager, pManager, uManager);
		game.level2A(player, eManager, oManager, pManager, uManager);
		game.level2B(player, eManager, oManager, pManager, uManager);
		game.level2C(player, eManager, oManager, pManager, uManager);
		game.level3A(player, eManager, oManager, pManager, uManager);
		game.level3B(player, eManager, oManager, pManager, uManager);
		game.level3C(player, eManager, oManager, pManager, uManager);
		game.level4(player, eManager, oManager, pManager, uManager);
		

		player.checkOutOfScreen(); //Empêche de sortir de l'écran
		Event event;
		if (Keyboard::isKeyPressed(Keyboard::Up))
			player.sprite.move(0, -10);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			player.sprite.move(0, 10);

		//Créé un projectile lorsqu'il y a un click gauche avec un cooldown

		if (Mouse::isButtonPressed(Mouse::Left) && player.attackClock.getElapsedTime().asSeconds() > player.attackCooldown.asSeconds())
		{
			player.attackClock.restart();
			pManager.creerProjectile(player);
			pManager.getProjectiles()[pManager.getProjectiles().size() - 1]->sprite.setPosition(player.sprite.getPosition().x, player.sprite.getGlobalBounds().top+50);
		}
		
		while (window.pollEvent(event)){
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Enter)
					window.close();
			
		}

		// Calcul du deltaTime
		float deltaTime = clock.restart().asSeconds();
		// Mettre à jour l'arrière-plan
		background.update(deltaTime);
		star.update(deltaTime);


		window.clear();

		// Dessiner l'arrière-plan
		background.draw(window);

		// Dessine les étoile et leur defilement
		star.draw(window);

		//Gestion de l'affichage, de la durée de vie des projectiles et des dégâts infligés
		for (auto i = 0; i < pManager.getProjectiles().size(); i++)
		{
			window.draw(pManager.getProjectiles()[i]->sprite);
			if(pManager.getProjectiles()[i]->id == PLAYER)
				pManager.getProjectiles()[i]->sprite.move(14, 0);
			if (pManager.getProjectiles()[i]->id != PLAYER)
				pManager.getProjectiles()[i]->sprite.move(pManager.getProjectiles()[i]->velocity, 0);
			pManager.checkProjectileOutOfScreen(pManager.getProjectiles()[i], eManager, player, scoreText);
		}
		for (int i = 0; i < uManager.getUtilitaryList().size(); i++)
		{
			window.draw(uManager.getUtilitaryList()[i]->sprite);
			uManager.getUtilitaryList()[i]->moveUtilitary();
			uManager.checkUtilitary(uManager.getUtilitaryList()[i], player);
		}
		//Regarde si un ennemi sort de l'écran ou si il est mort
		for (auto i = 0; i < eManager.getEnemies().size(); i++)
		{
			window.draw(eManager.getEnemies()[i]->sprite);
			eManager.checkEnemy(eManager.getEnemies()[i], game.toKill);
		}
		//Gestion des obstacles
		for (int i = 0; i < oManager.getObstacles().size(); i++)
		{
			window.draw(oManager.getObstacles()[i]->sprite);
			int randValue = rand() % 3;
			oManager.getObstacles()[i]->moveObstacle(randValue);
			oManager.getObstacles()[i]->checkObstacle(player);
		}
		//Gestion de l'attaque des ennemis
		for (auto i = 0; i < eManager.getEnemies().size(); i++)
		{
			eManager.getEnemies()[i]->enemyMove();
			if(eManager.getEnemies()[i]->rechargeClock.getElapsedTime().asSeconds() > eManager.getEnemies()[i]->rechargeCooldown.asSeconds())
			{
				
				if (eManager.getEnemies()[i]->attackClock.getElapsedTime().asSeconds() > eManager.getEnemies()[i]->attackCooldown.asSeconds())
				{
					int projVelocityChance = rand() % 3;
					int projVelocity;
					switch (projVelocityChance)
					{
					case 1:
						projVelocity = -4;
						break;
					case 2:
						projVelocity = -6;
						break;
					case 3:
						projVelocity = -7;
						break;
					default:
						projVelocity = -4;
						break;
					}
					eManager.getEnemies()[i]->attackClock.restart();
					pManager.creerProjectile(eManager.getEnemies()[i], projVelocity);
				}
				

				if(eManager.getEnemies()[i]->rechargeClock.getElapsedTime().asSeconds() > eManager.getEnemies()[i]->rechargeCooldown.asSeconds() *2)
					eManager.getEnemies()[i]->rechargeClock.restart();
			}

		}

		updateScoreText(player, scoreText);
		healthbar.setHealthbar(player);
		player.checkOutOfScreen();
		window.draw(interface);
		if(player.HP > 0)
			window.draw(player.sprite);
		window.draw(scoreText);
		window.draw(coin);
		window.draw(healthbar.psprite);
		
		for (int i = 0; i < eManager.getEnemies().size(); i++)
		{
			if (eManager.getEnemies()[i]->id == BOSS1 || eManager.getEnemies()[i]->id == BOSS2 || eManager.getEnemies()[i]->id == BOSS3 || eManager.getEnemies()[i]->id == BOSS4)
			{
				healthbar.setHealthbar(eManager.getEnemies()[i]);
				window.draw(healthbar.esprite);
			}
		}
		window.display();




	}
	saveScore(player);
	return 0;
}