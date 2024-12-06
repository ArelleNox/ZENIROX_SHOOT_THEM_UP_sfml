#include <iostream>
#include "projectile.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "Background.hpp"


using namespace std;
using namespace sf;






int main() {

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "ZENIROX", Style::Fullscreen);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	Player player;
	player.setSprite();

	EnemyManager enemyManager;
	enemyManager.creerEnemy(Niveau3);

//	Background background("palier1.jpg", -1);
	

	// Initialiser l'horloge pour gérer le deltaTime
//	sf::Clock clock;

	ProjectileManager manager;
	bool tirEC = false;
	while (window.isOpen())
	{
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
			manager.getProjectiles()[manager.getProjectiles().size() - 1]->sprite.setPosition(player.sprite.getPosition().x, player.sprite.getGlobalBounds().top+10);
		}
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Enter)
					window.close();
			
		}

		// Calcul du deltaTime
//		float deltaTime = clock.restart().asSeconds();

		// Mettre à jour l'arrière-plan
//		background.update(deltaTime);


		window.clear();

		// Dessiner l'arrière-plan
//		background.draw(window);

		for (auto i = 0; i < manager.getProjectiles().size(); i++)
		{
			window.draw(manager.getProjectiles()[i]->sprite);
			if(manager.getProjectiles()[i]->id == PLAYER)
				manager.getProjectiles()[i]->sprite.move(14, 0);
			if (manager.getProjectiles()[i]->id != PLAYER)
				manager.getProjectiles()[i]->sprite.move(-7, 0);
			manager.checkProjectileOutOfScreen(manager.getProjectiles()[i], enemyManager, player);
		}
		for (auto i = 0; i < enemyManager.getEnemies().size(); i++)
		{
			window.draw(enemyManager.getEnemies()[i]->sprite);
			enemyManager.checkEnemy(enemyManager.getEnemies()[i]);
		}
		for (auto i = 0; i < enemyManager.getEnemies().size(); i++)
		{
			enemyManager.getEnemies()[i]->enemyMove();
			if(enemyManager.getEnemies()[i]->rechargeClock.getElapsedTime().asSeconds() > enemyManager.getEnemies()[i]->rechargeCooldown.asSeconds())
			{
				
				if (enemyManager.getEnemies()[i]->attackClock.getElapsedTime().asSeconds() > enemyManager.getEnemies()[i]->attackCooldown.asSeconds())
				{
					enemyManager.getEnemies()[i]->attackClock.restart();
					manager.creerProjectile(enemyManager.getEnemies()[i]);
					

				}
				if(enemyManager.getEnemies()[i]->rechargeClock.getElapsedTime().asSeconds() > enemyManager.getEnemies()[i]->rechargeCooldown.asSeconds() *2 )
					enemyManager.getEnemies()[i]->rechargeClock.restart();
			}

		}
		player.checkOutOfScreen();
		window.draw(player.sprite);
		window.display();




	}
	return 0;
}