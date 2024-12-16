#include "game.hpp"
using namespace std;
using namespace sf;





int main() {
	srand(time(NULL));
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "ZENIROX", Style::Default);
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

	setScoreText(player, scoreFont, scoreText);

	Background background("palier11.png", -10.0f); // Default texture and speed

	Starparallaxe star("star.png", -300.f);
	fastStarparallaxe faststar("star.png", -1500.f);

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
	

	while (window.isOpen()){
		//Chargement des niveaux
		game.run(window, player, coin, background, star, faststar, healthbar, eManager, pManager, oManager, uManager, exManager, clock, scoreText, scoreFont, interface, playing, boss, finalBossM, playerShot, shot);
		if(game.state == niveauEDIT && game.isFightingBoss == false)
		{
			for (int i = 0; i < eManager.getEnemies().size(); i++)
			{
				if (eManager.getEnemies()[i]->id == BOSS1 || eManager.getEnemies()[i]->id == BOSS2 || eManager.getEnemies()[i]->id == BOSS3 || eManager.getEnemies()[i]->id == BOSS4)
					eManager.getEnemies()[i]->sprite.move(-4, 0);
			}
		}

		window.display();

	}
	saveScore(player);
	return 0;
}