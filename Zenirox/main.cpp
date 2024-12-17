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
	EnemyManager eManager;

	RectangleShape interface(Vector2f(1920, 95));
	Texture interfaceT;
	if (!interfaceT.loadFromFile("cockpit.png")) { throw runtime_error("Erreur de chargement cockpit"); }
	interface.setTexture(&interfaceT);

	Sprite coin;
	Texture coinTexture;
	if (!coinTexture.loadFromFile("coin.png")) { cout << "Erreur de chargement de la texture de piece" << endl; return -1; }
	coin.setTexture(coinTexture);
	coin.setScale(0.2, 0.2);
	coin.setPosition(0, 45);

	game.Univeau1A = true;
	Text scoreText;
	Font scoreFont;
	Text totalScoreText;

	setCurrentScoreText(player, scoreFont, scoreText);
	Background background("palier1Test.jpg", -31); // Default texture and speed

	/*switch (background.pal) {
	case palier1:
		background.setupPalier1();
		break;
	case palier2:
		background.setupPalier2();
		break;
	case palier3:
		background.setupPalier3();
		break;
	case palier4:
		background.setupPalier4();
		break;
	}*/


	Starparallaxe star("star.png", -100.f);
	fastStarparallaxe faststar("starR.png", -250.f);

	Healthbar healthbar;
	healthbar.setTextureList();

	// Initialiser l'horloge pour gérer le deltaTime
	sf::Clock clock;

	ProjectileManager pManager;
	openScore(player);
	
	ObstacleManager oManager;

	UtilitaryManager uManager;

	ExplosionManager exManager;

	Music playing;
	Music boss;

	Music finalBossM;
	
	if (!playing.openFromFile("sounds/playing.ogg")) throw runtime_error("Musique de combat classique non chargee");
	playing.setLoop(true);

	if(!boss.openFromFile("sounds/boss.ogg")) throw runtime_error("Musique de combat de boss non chargee");
	boss.setLoop(true);
	if(!finalBossM.openFromFile("sounds/finalboss.ogg")) throw runtime_error("Musique de combat final non chargee");
	finalBossM.setLoop(true);

	playing.setVolume(50);
	boss.setVolume(50);
	finalBossM.setVolume(50);

	SoundBuffer shot;
	if (!shot.loadFromFile("sounds/shot.ogg")) throw runtime_error("Son de tir non charge");
	vector<Sound> playerShot{ 10 };
	for (int i = 0; i < playerShot.size(); i++)
	{
		playerShot[i].setBuffer(shot);
	}

	Clock warningClock;
	Time warningCooldown = seconds(1);
	Text warningText;
	warningText.setFont(scoreFont);
	warningText.setString("HURRY UP!");
	warningText.setFillColor(Color::Red);
	warningText.setOutlineColor(Color::Black);
	warningText.setOutlineThickness(4);
	warningText.setScale(1.5, 1.5);
	warningText.setPosition(450, 20);
	Sprite skull;
	Texture skullT;
	if (!skullT.loadFromFile("skull.png")) throw runtime_error("Erreur chargement crane");
	skull.setTexture(skullT);
	skull.setColor(Color::Red);
	skull.setScale(0.1, 0.1);
	skull.setPosition(350, 0);
	

	while (window.isOpen()){
		//Chargement des niveaux
		game.run(window, player, coin, background, star, faststar, healthbar, eManager, pManager, oManager, uManager, exManager, clock, scoreText, scoreFont, interface, playing, boss, finalBossM, playerShot, shot, totalScoreText);
		if(game.state == niveauEDIT && game.isFightingBoss == false)
		{
			for (int i = 0; i < eManager.getEnemies().size(); i++)
			{
				if (eManager.getEnemies()[i]->id == BOSS1 || eManager.getEnemies()[i]->id == BOSS2 || eManager.getEnemies()[i]->id == BOSS3 || eManager.getEnemies()[i]->id == BOSS4)
					eManager.getEnemies()[i]->sprite.move(-4, 0);
			}
		}
		


		if(game.finalhours.getStatus() == Sound::Playing)
		{
			if(warningClock.getElapsedTime().asSeconds() > warningCooldown.asSeconds())
			{
				window.draw(skull);
				window.draw(warningText);
			}
			if (warningClock.getElapsedTime().asSeconds() > warningCooldown.asSeconds() + 1)
				warningClock.restart();
		}
		window.display();

	}



	saveScore(player);
	return 0;
}