#include <iostream>
#include "projectile.hpp"
#include "player.hpp"
#include "enemy.hpp"

using namespace std;
using namespace sf;




Clock playerAttackClock;
Time playerAttackCooldown = seconds(0.2);


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
		if (Mouse::isButtonPressed(Mouse::Left) && playerAttackClock.getElapsedTime().asSeconds() > playerAttackCooldown.asSeconds())
		{
			playerAttackClock.restart();
			manager.creerProjectile();
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
			manager.getProjectiles()[i]->sprite.move(7, 0);
			manager.checkProjectileOutOfScreen(manager.getProjectiles()[i], enemyManager, player);
		}
		for (auto i = 0; i < enemyManager.getEnemies().size(); i++)
		{
			window.draw(enemyManager.getEnemies()[i]->sprite);
			enemyManager.checkEnemy(enemyManager.getEnemies()[i]);
		}
		window.draw(player.sprite);
		window.display();




	}
	return 0;
}