#include <iostream>
#include "level1.hpp"
#include "projectile.hpp"
#include "player.hpp"

using namespace std;
using namespace sf;


int main() {

	Level1 palier1;
	palier1.pal1_back();


	// Créer une fenêtre SFML
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "ZENIROX");

	// Boucle principale du jeu
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed ||
				(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)) {
				window.close();
			}
		}

		// Effacer la fenêtre
		window.clear();

		// Afficher les modifications à l'écran
		window.display();
	}

	return 0;  // Indiquer que la méthode s'est terminée sans erreurs
}

	


/*const float HEIGHT = 1080;
const float WIDTH = 1920;

class Projectile {
public:
	CircleShape sprite;
};

int main() {

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Shoot em up de fou-malade-qui-tue", Style::Fullscreen);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	Sprite player;
	player.setPosition(HEIGHT / 2, WIDTH / 2);
	player.rotate(90);
	Texture player4;
	if (!player4.loadFromFile("ship.png")) { cout << "Erreur chargement" << endl; return -1; }
	player.setTexture(player4);
	Player player;
	player.setSprite();
	
	RectangleShape background;
	background.setSize(Vector2f(1920, 1080));
	Texture space;
	if (!space.loadFromFile("background.jpg")) { cout << "Erreur chargement" << endl; return -1; }
	background.setTexture(&space);
	Projectile tir;
	tir.sprite.setRadius(5);
	tir.sprite.setFillColor(Color::Red);

	bool tirEC = false;
	while (window.isOpen())
	{
		Event event;
		if (Keyboard::isKeyPressed(Keyboard::Up))
			player.sprite.move(0, -5);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			player.move(0, 5);
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
			if (event.type == Event::MouseButtonPressed)
				if (event.mouseButton.button == Mouse::Left)
					tirEC = true;


		}

		window.clear();
		window.draw(background);
		window.draw(player);
		if (tir.sprite.getPosition().x > WIDTH)
		{
			tirEC = false;

		}
		if (tirEC == false)
		{
			tir.sprite.setPosition(player.getPosition().x, player.getPosition().y);
		}
		if (tirEC == true)
		{

			window.draw(tir.sprite);
			tir.sprite.move(5, 0);
		}
		window.display();
	}

			}
		}
			window.clear();
			window.draw(background);
			for (auto i = 0; i < manager.getProjectiles().size(); i++)
			{
				window.draw(manager.getProjectiles()[i]->sprite);
				manager.getProjectiles()[i]->sprite.move(7, 0);
				manager.checkProjectile(manager.getProjectiles()[i]);
			}
			window.draw(player.sprite);
			window.display();
			
		

		
	}
	return 0;
}*/