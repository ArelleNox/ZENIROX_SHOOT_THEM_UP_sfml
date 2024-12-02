#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

const float HEIGHT = 1080;
const float WIDTH = 1920;

class Projectile {
public:
	CircleShape sprite;
};

int main() {

	RenderWindow window(VideoMode(HEIGHT, WIDTH), "Shoot em up de fou-malade-qui-tue", Style::Fullscreen);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	Sprite player;
	player.setPosition(HEIGHT / 2, WIDTH / 2);
	player.rotate(90);
	Texture player4;
	if (!player4.loadFromFile("C:\\Users\\rdumont\\source\\repos\\Shoot em up\\ship.png")) { cout << "Erreur chargement" << endl; return -1; }
	player.setTexture(player4);
	RectangleShape background;
	background.setSize(Vector2f(1920, 1080));
	Texture space;
	if (!space.loadFromFile("C:\\Users\\rdumont\\source\\repos\\Shoot em up\\background.jpg")) { cout << "Erreur chargement" << endl; return -1; }
	background.setTexture(&space);
	Projectile tir;
	tir.sprite.setRadius(5);
	tir.sprite.setFillColor(Color::Red);

	bool tirEC = false;
	while (window.isOpen())
	{
		Event event;
		if (Keyboard::isKeyPressed(Keyboard::Up))
			player.move(0, -5);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			player.move(0, 5);
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Escape)
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

	return 0;
}