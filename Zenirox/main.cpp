#include <iostream>
#include "projectile.hpp"
#include "player.hpp"
#include "enemy.hpp"


using namespace std;
using namespace sf;






int main() {

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Shoot em up de fou-malade-qui-tue", Style::Default);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	Player player;
	player.setSprite();
	EnemyManager enemyManager;
	enemyManager.creerEnemy(Niveau3);

	RectangleShape background;
	background.setSize(Vector2f(1920, 1080));
	Texture space;
	if (!space.loadFromFile("background.jpg")) { cout << "Erreur chargement" << endl; return -1; }
	background.setTexture(&space);
	ProjectileManager manager;
	bool tirEC = false;
	while (window.isOpen())
	{

		Event event;
		if (Keyboard::isKeyPressed(Keyboard::Up))
			player.sprite.move(0, -5);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			player.sprite.move(0, 5);
		if (Mouse::isButtonPressed(Mouse::Left) && player.attackClock.getElapsedTime().asSeconds() > player.attackCooldown.asSeconds())
		{
			player.attackClock.restart();
			manager.creerProjectile(player);
			manager.getProjectiles()[manager.getProjectiles().size() - 1]->sprite.setPosition(player.sprite.getPosition().x, player.sprite.getPosition().y + 70);
		}
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Enter)
					window.close();
			
		}
		window.clear();
		window.draw(background);
		for (auto i = 0; i < manager.getProjectiles().size(); i++)
		{
			window.draw(manager.getProjectiles()[i]->sprite);
			if(manager.getProjectiles()[i]->id == PLAYER)
				manager.getProjectiles()[i]->sprite.move(7, 0);
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
			if (enemyManager.getEnemies()[i]->attackClock.getElapsedTime().asSeconds() > enemyManager.getEnemies()[i]->attackCooldown.asSeconds() && enemyManager.getEnemies()[i]->rechargeClock.getElapsedTime().asSeconds() > enemyManager.getEnemies()[i]->rechargeCooldown.asSeconds())
			{
				enemyManager.getEnemies()[i]->attackClock.restart();
				enemyManager.getEnemies()[i]->rechargeClock.restart();
				manager.creerProjectile(enemyManager.getEnemies()[i]);
				manager.getProjectiles()[manager.getProjectiles().size() - 1]->sprite.setPosition(enemyManager.getEnemies()[i]->sprite.getPosition().x, enemyManager.getEnemies()[i]->sprite.getPosition().y - 170);

			}
		}
		window.draw(player.sprite);
		window.display();




	}
	return 0;
}