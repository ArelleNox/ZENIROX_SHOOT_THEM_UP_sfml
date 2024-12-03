#include <iostream>
#include "projectile.hpp"

using namespace std;
using namespace sf;




Clock playerAttackClock;
Time playerAttackCooldown = seconds(0.2);


int main() {

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Shoot em up de fou-malade-qui-tue", Style::Default);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	Sprite player;
	player.setPosition(WIDTH / 2, HEIGHT / 2);
	player.rotate(90);
	Texture player4;
	if (!player4.loadFromFile("ship.png")) { cout << "Erreur chargement" << endl; return -1; }
	player.setTexture(player4);
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
			player.move(0, -5);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			player.move(0, 5);
		if (Mouse::isButtonPressed(Mouse::Left) && playerAttackClock.getElapsedTime().asSeconds() > playerAttackCooldown.asSeconds())
		{
			playerAttackClock.restart();
			manager.creerProjectile();
			manager.getProjectiles()[manager.getProjectiles().size() - 1]->sprite.setPosition(player.getPosition().x, player.getPosition().y + 70);
		}
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Enter)
					window.close();
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left )
			{
				

			}
		}
			window.clear();
			window.draw(background);
			for (auto i = 0; i < manager.getProjectiles().size(); i++)
			{
				window.draw(manager.getProjectiles()[i]->sprite);
				manager.getProjectiles()[i]->sprite.move(5, 0);
				manager.checkProjectile(manager.getProjectiles()[i]);
			}
			window.draw(player);
			window.display();
			
		

		
	}
	return 0;
}