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
	EnemyManager enemyManager;
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

	ProjectileManager manager;
	openScore(player);
	
	ObstacleManager oManager;
	while (window.isOpen())
	{
		//Chargement des niveaux

		game.level1A(player, enemyManager, oManager, manager);
		//game.level1B(player, enemyManager, oManager, manager);
		//game.level1C(player, enemyManager, oManager, manager);
		//game.level2A(player, enemyManager, oManager, manager);
		//game.level2B(enemyManager, manager);
		//game.level2C(enemyManager, manager);
		//game.level3A(enemyManager, manager);
		//game.level3B(enemyManager, manager);
		//game.level3C(enemyManager, manager);
		

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
			manager.creerProjectile(player);
			manager.getProjectiles()[manager.getProjectiles().size() - 1]->sprite.setPosition(player.sprite.getPosition().x, player.sprite.getGlobalBounds().top+50);
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
		for (auto i = 0; i < manager.getProjectiles().size(); i++)
		{
			window.draw(manager.getProjectiles()[i]->sprite);
			if(manager.getProjectiles()[i]->id == PLAYER)
				manager.getProjectiles()[i]->sprite.move(14, 0);
			if (manager.getProjectiles()[i]->id != PLAYER)
				manager.getProjectiles()[i]->sprite.move(manager.getProjectiles()[i]->velocity, 0);
			manager.checkProjectileOutOfScreen(manager.getProjectiles()[i], enemyManager, player, scoreText);
		}
		
		//Regarde si un ennemi sort de l'écran ou si il est mort
		for (auto i = 0; i < enemyManager.getEnemies().size(); i++)
		{
			window.draw(enemyManager.getEnemies()[i]->sprite);
			enemyManager.checkEnemy(enemyManager.getEnemies()[i], game.toKill);
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
		for (auto i = 0; i < enemyManager.getEnemies().size(); i++)
		{
			enemyManager.getEnemies()[i]->enemyMove();
			if(enemyManager.getEnemies()[i]->rechargeClock.getElapsedTime().asSeconds() > enemyManager.getEnemies()[i]->rechargeCooldown.asSeconds())
			{
				
				if (enemyManager.getEnemies()[i]->attackClock.getElapsedTime().asSeconds() > enemyManager.getEnemies()[i]->attackCooldown.asSeconds())
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
					enemyManager.getEnemies()[i]->attackClock.restart();
					manager.creerProjectile(enemyManager.getEnemies()[i], projVelocity);
				}
				

				if(enemyManager.getEnemies()[i]->rechargeClock.getElapsedTime().asSeconds() > enemyManager.getEnemies()[i]->rechargeCooldown.asSeconds() *2)
					enemyManager.getEnemies()[i]->rechargeClock.restart();
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
		for (int i = 0; i < enemyManager.getEnemies().size(); i++)
		{
			if (enemyManager.getEnemies()[i]->id == BOSS1 || enemyManager.getEnemies()[i]->id == BOSS2 || enemyManager.getEnemies()[i]->id == BOSS3 || enemyManager.getEnemies()[i]->id == BOSS4)
			{
				healthbar.setHealthbar(enemyManager.getEnemies()[i]);
				window.draw(healthbar.esprite);
			}
		}
		window.display();




	}
	saveScore(player);
	return 0;
}