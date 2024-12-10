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
	
	
	game.Univeau1A = true;
	Text scoreText;
	Font scoreFont;

	setScoreText(player, scoreFont, scoreText);

	Background background("palier1.png",-15.f);

	Starparallaxe star("star.png",-300.f);

	Healthbar playerHealthbar;
	playerHealthbar.setTextureList();

	// Initialiser l'horloge pour g�rer le deltaTime
	sf::Clock clock;

	ProjectileManager manager;
	openScore(player);
	while (window.isOpen())
	{
		game.level1A(enemyManager, manager);
		game.level1B(enemyManager, manager);
		game.level1C(enemyManager, manager);
		game.level2A(enemyManager, manager);
		//game.level2B(enemyManager, manager);
		//game.level2C(enemyManager, manager);
		//game.level3A(enemyManager, manager);
		//game.level3B(enemyManager, manager);
		//game.level3C(enemyManager, manager);
		
		player.checkOutOfScreen();
		Event event;
		if (Keyboard::isKeyPressed(Keyboard::Up))
			player.sprite.move(0, -10);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			player.sprite.move(0, 10);
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
		// Mettre � jour l'arri�re-plan
		background.update(deltaTime);
		star.update(deltaTime);


		window.clear();

		// Dessiner l'arri�re-plan
		background.draw(window);

		// Dessine les �toile et leur defilement
		star.draw(window);

		for (auto i = 0; i < manager.getProjectiles().size(); i++)
		{
			window.draw(manager.getProjectiles()[i]->sprite);
			if(manager.getProjectiles()[i]->id == PLAYER)
				manager.getProjectiles()[i]->sprite.move(14, 0);
			if (manager.getProjectiles()[i]->id != PLAYER)
				manager.getProjectiles()[i]->sprite.move(manager.getProjectiles()[i]->velocity, 0);
			manager.checkProjectileOutOfScreen(manager.getProjectiles()[i], enemyManager, player, scoreText);
		}
		
		for (auto i = 0; i < enemyManager.getEnemies().size(); i++)
		{
			window.draw(enemyManager.getEnemies()[i]->sprite);
			enemyManager.checkEnemy(enemyManager.getEnemies()[i], game.toKill);
		}
		
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
		playerHealthbar.setHealthbar(player);
		player.checkOutOfScreen();
		if(player.HP > 0)
			window.draw(player.sprite);
		window.draw(scoreText);
		window.draw(playerHealthbar.sprite);
		window.display();




	}
	saveScore(player);
	return 0;
}