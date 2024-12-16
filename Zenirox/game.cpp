#include "game.hpp"

Game::Game() : hoveredOption(-1) {
	// background texture
	if (!backgroundTexture.loadFromFile("mainmenu.png")) {
		throw std::runtime_error("Failed to load texture");
	}
	backgroundSprite.setTexture(backgroundTexture);

	// font
	if (!font.loadFromFile("UIfont.ttf")) {
		throw std::runtime_error("Failed to load texture");
	}

	// title
	title.setFont(font);
	title.setString("ZENIROX");
	title.setCharacterSize(50);
	title.setFillColor(sf::Color::White);
	title.setPosition(200, 100);

	// Menu options
	std::vector<std::string> options = { "New Game", "Settings", "Exit" };
	for (size_t i = 0; i < options.size(); ++i) {
		sf::Text option;
		option.setFont(font);
		option.setString(options[i]);
		option.setCharacterSize(30);
		option.setFillColor(sf::Color::White);
		option.setPosition(300, 200 + static_cast<float>(i) * 50);
		menuOptions.push_back(option);
	}

	//Musique de d�faite
	if (!lose.openFromFile("sounds/lose.ogg")) throw runtime_error("Echec lors de l'ouverture de la musique de d�faite");
}



void Game::setGameDuration(float duration) {
	gameDuration = seconds(duration);
}

void Game::level1A(Player& player, EnemyManager &eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM)
{
	if (state == niveau1A && loadLevel == true && isFightingBoss == false && Univeau1A == true)
	{
		background.setupPalier1();
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(120);
		toKill = 10;

		eManager.creerEnemy(ENNEMI1, 1000, 600);
		eManager.creerEnemy(ENNEMI1, 2500, 300);
		eManager.creerEnemy(ENNEMI1, 4000, 700);
		oManager.creerObstacle(4700, 500);
		eManager.creerEnemy(ENNEMI1, 5500, 100);
		eManager.creerEnemy(ENNEMI2, 7000, 800);
		eManager.creerEnemy(ENNEMI1, 8500, 400);
		eManager.creerEnemy(ENNEMI1, 10000, 600);
		eManager.creerEnemy(ENNEMI1, 11500, 300);
		eManager.creerEnemy(ENNEMI1, 13000, 500);
		eManager.creerEnemy(ENNEMI3, 14500, 800);
		
		
		loadLevel = false;
	}
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds())
	{
		player.HP = 0;
	}
	else if (state == niveau1A && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS1, 1400, 700);
		
		//Ecran de victoire...
	}
	if (isFightingBoss == true && toKill == 0 && Univeau1A == true && state == niveau1A)
	{
		isFightingBoss = false;
		loadLevel = true;
		Univeau1B = true;
		state = niveau1B;
		pManager.~ProjectileManager();
		oManager.~ObstacleManager();
	}
}

void Game::level1B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM)
{
	
	if (state == niveau1B && loadLevel == true && isFightingBoss == false && Univeau1B == true)
	{
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(120);
		toKill = 10;
		eManager.creerEnemy(ENNEMI1, 1000, 500);
		eManager.creerEnemy(ENNEMI1, 2500, 300);
		eManager.creerEnemy(ENNEMI2, 4000, 700);
		oManager.creerObstacle(4700, 500);
		eManager.creerEnemy(ENNEMI1, 5500, 100);
		eManager.creerEnemy(ENNEMI1, 7000, 800);
		eManager.creerEnemy(ENNEMI2, 8500, 400);
		eManager.creerEnemy(ENNEMI1, 10000, 600);
		eManager.creerEnemy(ENNEMI1, 11500, 300);
		eManager.creerEnemy(ENNEMI1, 13000, 500);
		eManager.creerEnemy(ENNEMI3, 14500, 800);

		loadLevel = false;
	}
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds())
	{
		player.HP = 0;
	}
	if (state == niveau1B && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS1, 1400, 700);
	}
	if (isFightingBoss == true && toKill == 0 && Univeau1B == true && state == niveau1B)
	{
		isFightingBoss = false;
		loadLevel = true;
		Univeau1C = true;
		state = niveau1C;
		pManager.~ProjectileManager();
		oManager.~ObstacleManager();
	}
}

void Game::level1C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM)
{
	if (state == niveau1C && loadLevel == true && isFightingBoss == false && Univeau1C == true)
	{
		
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(120);
		toKill = 10;
		eManager.creerEnemy(ENNEMI1, 1000, 500);
		eManager.creerEnemy(ENNEMI1, 2500, 300);
		eManager.creerEnemy(ENNEMI2, 4000, 700);
		oManager.creerObstacle(4700, 500);
		eManager.creerEnemy(ENNEMI1, 5500, 100);
		eManager.creerEnemy(ENNEMI1, 7000, 800);
		eManager.creerEnemy(ENNEMI2, 8500, 400);
		eManager.creerEnemy(ENNEMI1, 10000, 600);
		eManager.creerEnemy(ENNEMI2, 11500, 300);
		eManager.creerEnemy(ENNEMI1, 13000, 500);
		eManager.creerEnemy(ENNEMI3, 14500, 800);

		loadLevel = false;
	}
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds())
	{
		player.HP = 0;
	}
	if (state == niveau1C && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS1, 1400, 700);
	}
	if (isFightingBoss == true && toKill == 0 && Univeau1C == true && state == niveau1C)
	{
		isFightingBoss = false;
		loadLevel = true;
		Univeau2A = true;
		state = niveau2A;
		pManager.~ProjectileManager();
		oManager.~ObstacleManager();
	}
}

void Game::level2A(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM)
{
	
	if (state == niveau2A && loadLevel == true && isFightingBoss == false && Univeau2A == true)
	{
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(120);
		toKill = 10;
		eManager.creerEnemy(ENNEMI2, 1000, 500);
		eManager.creerEnemy(ENNEMI2, 2500, 300);
		eManager.creerEnemy(ENNEMI2, 4000, 700);
		oManager.creerObstacle(4700, 500);
		eManager.creerEnemy(ENNEMI2, 5500, 100);
		eManager.creerEnemy(ENNEMI3, 7000, 800);
		eManager.creerEnemy(ENNEMI2, 8500, 400);
		eManager.creerEnemy(ENNEMI2, 10000, 600);
		eManager.creerEnemy(ENNEMI2, 11500, 300);
		eManager.creerEnemy(ENNEMI2, 13000, 500);
		eManager.creerEnemy(ENNEMI3, 14500, 800);

		loadLevel = false;
	}
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds())
	{
		player.HP = 0;
	}
	if (state == niveau2A && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS2, 1400, 700);
	}
	if (isFightingBoss == true && toKill == 0 && Univeau2A == true && state == niveau2A)
	{
		isFightingBoss = false;
		loadLevel = true;
		Univeau2B = true;
		state = niveau2B;
		pManager.~ProjectileManager();
		oManager.~ObstacleManager();
	}
}

void Game::level2B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM)
{

	if (state == niveau2B && loadLevel == true && isFightingBoss == false && Univeau2B == true)
	{
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(120);
		toKill = 10;
		eManager.creerEnemy(ENNEMI2, 1000, 500);
		eManager.creerEnemy(ENNEMI2, 2500, 300);
		eManager.creerEnemy(ENNEMI2, 4000, 700);
		oManager.creerObstacle(4700, 500);
		eManager.creerEnemy(ENNEMI2, 5500, 100);
		eManager.creerEnemy(ENNEMI3, 7000, 800);
		eManager.creerEnemy(ENNEMI2, 8500, 400);
		eManager.creerEnemy(ENNEMI2, 10000, 600);
		eManager.creerEnemy(ENNEMI3, 11500, 300);
		eManager.creerEnemy(ENNEMI2, 13000, 500);
		eManager.creerEnemy(ENNEMI3, 14500, 800);

		loadLevel = false;
	}
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds())
	{
		player.HP = 0;
	}
	if (state == niveau2B && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS2, 1400, 700);
	}
	if (isFightingBoss == true && toKill == 0 && Univeau2B == true && state == niveau2B)
	{
		isFightingBoss = false;
		loadLevel = true;
		Univeau2C = true;
		state = niveau2C;
		pManager.~ProjectileManager();
		oManager.~ObstacleManager();
	}
}

void Game::level2C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM)
{

	if (state == niveau2C && loadLevel == true && isFightingBoss == false && Univeau2C == true)
	{
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(120);
		toKill = 10;
		eManager.creerEnemy(ENNEMI3, 1000, 500);
		eManager.creerEnemy(ENNEMI2, 2500, 300);
		eManager.creerEnemy(ENNEMI2, 4000, 700);
		oManager.creerObstacle(4700, 500);
		eManager.creerEnemy(ENNEMI2, 5500, 100);
		eManager.creerEnemy(ENNEMI3, 7000, 800);
		eManager.creerEnemy(ENNEMI2, 8500, 400);
		eManager.creerEnemy(ENNEMI2, 10000, 600);
		eManager.creerEnemy(ENNEMI3, 11500, 300);
		eManager.creerEnemy(ENNEMI2, 13000, 500);
		eManager.creerEnemy(ENNEMI3, 14500, 800);

		loadLevel = false;
	}
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds())
	{
		player.HP = 0;
	}
	if (state == niveau2C && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS2, 1400, 700);
	}
	if (isFightingBoss == true && toKill == 0 && Univeau2C == true && state == niveau2C)
	{
		isFightingBoss = false;
		loadLevel = true;
		Univeau3A = true;
		state = niveau3A;
		pManager.~ProjectileManager();
		oManager.~ObstacleManager();
	}
}

void Game::level3A(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM)
{

	if (state == niveau3A && loadLevel == true && isFightingBoss == false && Univeau3A == true)
	{
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(120);
		toKill = 10;
		eManager.creerEnemy(ENNEMI3, 1000, 500);
		eManager.creerEnemy(ENNEMI3, 2500, 300);
		eManager.creerEnemy(ENNEMI3, 4000, 700);
		oManager.creerObstacle(4700, 500);
		eManager.creerEnemy(ENNEMI3, 5500, 100);
		eManager.creerEnemy(ENNEMI3, 7000, 800);
		eManager.creerEnemy(ENNEMI3, 8500, 400);
		eManager.creerEnemy(ENNEMI3, 10000, 600);
		oManager.creerObstacle(6000, 500);
		eManager.creerEnemy(ENNEMI3, 11500, 300);
		eManager.creerEnemy(ENNEMI3, 13000, 500);
		eManager.creerEnemy(ENNEMI3, 14500, 800);

		loadLevel = false;
	}
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds())
	{
		player.HP = 0;
	}
	if (state == niveau3A && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS3, 1400, 700);
	}
	if (isFightingBoss == true && toKill == 0 && Univeau3A == true && state == niveau3A)
	{
		isFightingBoss = false;
		loadLevel = true;
		Univeau3B = true;
		state = niveau3B;
		pManager.~ProjectileManager();
		oManager.~ObstacleManager();
	}
}

void Game::level3B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM)
{

	if (state == niveau3B && loadLevel == true && isFightingBoss == false && Univeau3B == true)
	{
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(150);
		toKill = 15;
		eManager.creerEnemy(ENNEMI3, 1000, 500);
		eManager.creerEnemy(ENNEMI3, 900, 700);
		eManager.creerEnemy(ENNEMI3, 2500, 300);
		eManager.creerEnemy(ENNEMI3, 2400, 500);
		eManager.creerEnemy(ENNEMI3, 4000, 700);
		oManager.creerObstacle(4700, 500);
		eManager.creerEnemy(ENNEMI3, 5500, 100);
		eManager.creerEnemy(ENNEMI3, 7000, 800);
		eManager.creerEnemy(ENNEMI3, 6900, 500);
		eManager.creerEnemy(ENNEMI3, 8500, 400);
		eManager.creerEnemy(ENNEMI3, 10000, 600);
		oManager.creerObstacle(6000, 500);
		eManager.creerEnemy(ENNEMI3, 11500, 300);
		eManager.creerEnemy(ENNEMI3, 11400, 700);
		eManager.creerEnemy(ENNEMI3, 13000, 500);
		eManager.creerEnemy(ENNEMI3, 14500, 800);
		eManager.creerEnemy(ENNEMI3, 14400, 500);

		loadLevel = false;
	}
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds())
	{
		player.HP = 0;
	}
	if (state == niveau3B && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS3, 1400, 700);
	}
	if (isFightingBoss == true && toKill == 0 && Univeau3B == true && state == niveau3B)
	{
		isFightingBoss = false;
		loadLevel = true;
		Univeau3C = true;
		state = niveau3C;
		pManager.~ProjectileManager();
		oManager.~ObstacleManager();
	}
}

void Game::level3C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM)
{

	if (state == niveau3C && loadLevel == true && isFightingBoss == false && Univeau3C == true)
	{
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(180);
		toKill = 20;
		eManager.creerEnemy(ENNEMI3, 1000, 500);
		eManager.creerEnemy(ENNEMI3, 900, 700);
		eManager.creerEnemy(ENNEMI3, 800, 300);
		eManager.creerEnemy(ENNEMI3, 2500, 300);
		eManager.creerEnemy(ENNEMI3, 2400, 500);
		eManager.creerEnemy(ENNEMI3, 2300, 700);
		eManager.creerEnemy(ENNEMI3, 4000, 700);
		oManager.creerObstacle(4700, 500);
		eManager.creerEnemy(ENNEMI3, 5500, 100);
		eManager.creerEnemy(ENNEMI3, 7000, 800);
		eManager.creerEnemy(ENNEMI3, 6900, 500);
		eManager.creerEnemy(ENNEMI3, 6800, 200);
		eManager.creerEnemy(ENNEMI3, 8500, 400);
		eManager.creerEnemy(ENNEMI3, 10000, 600);
		oManager.creerObstacle(6000, 500);
		eManager.creerEnemy(ENNEMI3, 11500, 300);
		eManager.creerEnemy(ENNEMI3, 11400, 700);
		eManager.creerEnemy(ENNEMI3, 11300, 500);
		eManager.creerEnemy(ENNEMI3, 13000, 500);
		eManager.creerEnemy(ENNEMI3, 14500, 800);
		eManager.creerEnemy(ENNEMI3, 14400, 500);
		eManager.creerEnemy(ENNEMI3, 14300, 200);

		loadLevel = false;
	}
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds())
	{
		player.HP = 0;
	}
	if (state == niveau3C && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS3, 1400, 700);
	}
	if (isFightingBoss == true && toKill == 0 && Univeau3C == true && state == niveau3C)
	{
		isFightingBoss = false;
		loadLevel = true;
		UfinalBoss = true;
		state = finalBoss;
		pManager.~ProjectileManager();
		oManager.~ObstacleManager();
	}
}

void Game::level4(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM)
{
	if (state == finalBoss && loadLevel == true && isFightingBoss == false && UfinalBoss == true)
	{
		gameClock.restart();
		setGameDuration(180);
		toKill = 0;
		
		

		loadLevel = false;
	}
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds())
	{
		player.HP = 0;
	}
	if (state == finalBoss && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		boss.stop();
		finalBossM.play();
		
		isFightingBoss = true;
		toKill = 1;
		oManager.creerObstacle(1000, 100);
		oManager.creerObstacle(1000, 900);
		eManager.creerEnemy(BOSS4, 1400, 700);
	}
	
}

void Game::levelP(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM)
{
	if (state == niveauEDIT && loadLevel == true && isFightingBoss == false)
	{
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(120);
		toKill = 10;


		eManager.creerEnemy(nb1, 1000, 600);
		eManager.creerEnemy(nb2, 2500, 300);
		eManager.creerEnemy(nb3, 4000, 700);
		oManager.creerObstacle(4700, 500);
		eManager.creerEnemy(nb4, 5500, 100);
		eManager.creerEnemy(nb5, 7000, 800);
		eManager.creerEnemy(nb6, 8500, 400);
		eManager.creerEnemy(nb7, 10000, 600);
		eManager.creerEnemy(nb8, 11500, 300);
		eManager.creerEnemy(nb9, 13000, 500);
		eManager.creerEnemy(nb10, 14500, 800);

		loadLevel = false;
	}
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds())
	{
		player.HP = 0;
	}
	else if (state == niveauEDIT && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(bossID, 1400, 700);
	}
	

}

void Game::run(RenderWindow& window, Player& player, Sprite& coin, Background& background, Starparallaxe& star, fastStarparallaxe& faststar, Healthbar& healthbar, EnemyManager& eManager, ProjectileManager& pManager, ObstacleManager& oManager, UtilitaryManager& uManager, ExplosionManager& exManager, Clock& clock, Text& scoreText, Font& scoreFont, RectangleShape& interface, Music& playing, Music& boss, Music& finalBossM, vector<Sound>& playerShot, SoundBuffer& shot)
{
	if (screen == Editor)
	{
		
		vector <ID> IDlist{ ENNEMI1, ENNEMI2, ENNEMI3, BOSS1, BOSS2, BOSS3, BOSS4 };
		Text numerotation;
		numerotation.setString(to_string(counter));
		if (counter > 10)
			numerotation.setString("Boss");
		numerotation.setFont(scoreFont);
		numerotation.setOutlineThickness(6);
		numerotation.setOutlineColor(Color::Black);
		numerotation.setPosition(1220, 35);
		numerotation.setCharacterSize(200);
		RectangleShape editorBackground(Vector2f(1920, 1080));
		Texture editorBackgroundE;
		if (!editorBackgroundE.loadFromFile("level-editor.png")) throw runtime_error("Erreur de chargement fond editeur");
		editorBackground.setTexture(&editorBackgroundE);
		Sprite up;
		Sprite down;
		Texture upT;
		Texture downT;
		if (!upT.loadFromFile("up.png")) throw runtime_error("Impossible de charger le bouton haut");
		if (!downT.loadFromFile("down.png")) throw runtime_error("Impossible de charger le bouton bas");
		up.setTexture(upT);
		down.setTexture(downT);
		up.setPosition(500, 400);
		down.setPosition(500, 600);
		Sprite enemySprite;
		Texture enemyTexture;
		enemySprite.setPosition(900, 500);
		alias = &IDlist[currentID];
		switch (*alias)
		{
		case ENNEMI1:
			if (!enemyTexture.loadFromFile("enemy1.png")) throw runtime_error("Erreur chargement ennemi1");
			break;
		case ENNEMI2:
			if (!enemyTexture.loadFromFile("enemy2.png")) throw runtime_error("Erreur chargement ennemi1");
			break;
		case ENNEMI3:
			if (!enemyTexture.loadFromFile("enemy3.png")) throw runtime_error("Erreur chargement ennemi1");
			break;
		case BOSS1:
			if (!enemyTexture.loadFromFile("boss1.png")) throw runtime_error("Erreur chargement ennemi1");
			break;
		case BOSS2:
			if (!enemyTexture.loadFromFile("boss2.png")) throw runtime_error("Erreur chargement ennemi1");
			break;
		case BOSS3:
			if (!enemyTexture.loadFromFile("boss3.png")) throw runtime_error("Erreur chargement ennemi1");
			break;
		case BOSS4:
			if (!enemyTexture.loadFromFile("boss4.png")) throw runtime_error("Erreur chargement ennemi1");
			break;
		default:
			break;
		}
		enemySprite.setTexture(enemyTexture);

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window);
				if (event.mouseButton.button == Mouse::Left && up.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					if (currentID != IDlist.size() - 1)
						currentID++;
				}
				if (event.mouseButton.button == Mouse::Left && down.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					if (currentID != 0)
						currentID--;
				}
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					switch (counter)
					{
					case 1:
						nb1 = *alias;
						alias = &nb2;
						break;
					case 2:
						nb2 = *alias;
						alias = &nb3;
						break;
					case 3:
						nb3 = *alias;
						alias = &nb4;
						break;
					case 4:

						nb4 = *alias;
						alias = &nb5;
						break;
					case 5:
						nb5 = *alias;
						alias = &nb6;
						break;
					case 6:
						nb6 = *alias;
						alias = &nb7;
						break;
					case 7:
						nb7 = *alias;
						alias = &nb8;
						break;
					case 8:
						nb8 = *alias;
						alias = &nb9;
						break;
					case 9:
						nb9 = *alias;
						alias = &nb10;
						break;
					case 10:
						nb10 = *alias;
						alias = &bossID;
						break;
					default:
						bossID = *alias;
						screen = Playing;
						break;
					}
					counter++;
				}
			}
		}
		window.draw(editorBackground);
		window.draw(numerotation);
		window.draw(enemySprite);
		window.draw(up);
		window.draw(down);
	}

	/////////////////////////////////////////////////////////////////////

	if (screen == Playing)
	{
		if (state != niveauEDIT)
		{
			level1A(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM);
			level1B(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM);
			level1C(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM);
			level2A(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM);
			level2B(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM);
			level2C(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM);
			level3A(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM);
			level3B(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM);
			level3C(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM);
			level4(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM);
		}
		else if (state == niveauEDIT)
			levelP(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM);

		if (player.boostClock.getElapsedTime().asSeconds() < player.boostDuration.asSeconds() && player.canBeBoosted == true)
		{
			player.attackCooldown = seconds(0.01);
		}
		else
			player.attackCooldown = seconds(0.2);

		player.checkOutOfScreen(); //Emp�che de sortir de l'�cran
		Event event;
		if (Keyboard::isKeyPressed(Keyboard::Up))
			player.sprite.move(0, -10);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			player.sprite.move(0, 10);

		//Cr�� un projectile lorsqu'il y a un click gauche avec un cooldown

		if (Mouse::isButtonPressed(Mouse::Left) && player.attackClock.getElapsedTime().asSeconds() > player.attackCooldown.asSeconds()) {
			player.attackClock.restart();
			pManager.creerProjectile(player);
			bool soundPlayed = false;
			for (auto& shot : playerShot)
			{
				if (shot.getStatus() != Sound::Playing)
				{
					shot.play();
					cout << "Son joue" << endl;
					soundPlayed = true;
					break;
				}
			}
			if (!soundPlayed)
				playerShot[0].play();
			pManager.getProjectiles()[pManager.getProjectiles().size() - 1]->sprite.setPosition(player.sprite.getPosition().x, player.sprite.getGlobalBounds().top + 50);
		}



		while (window.pollEvent(event)) {
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
		faststar.update(deltaTime);

		window.clear();
		background.draw(window);
		// Dessine les �toile et leur defilement
		star.draw(window);
		faststar.draw(window);

		//Gestion de l'affichage, de la dur�e de vie des projectiles et des d�g�ts inflig�s
		for (auto i = 0; i < pManager.getProjectiles().size(); i++)
		{
			window.draw(pManager.getProjectiles()[i]->sprite);
			if (pManager.getProjectiles()[i]->id == PLAYER)
				pManager.getProjectiles()[i]->sprite.move(14, 0);
			if (pManager.getProjectiles()[i]->id != PLAYER)
				pManager.getProjectiles()[i]->sprite.move(pManager.getProjectiles()[i]->velocity, 0);
			pManager.checkProjectileOutOfScreen(pManager.getProjectiles()[i], eManager, player, scoreText);
		}
		for (auto i = 0; i < uManager.getUtilitaryList().size(); i++)
		{
			window.draw(uManager.getUtilitaryList()[i]->sprite);
			uManager.getUtilitaryList()[i]->moveUtilitary();
			uManager.checkUtilitary(uManager.getUtilitaryList()[i], player, eManager);
		}
		//Regarde si un ennemi sort de l'�cran ou si il est mort
		for (auto i = 0; i < eManager.getEnemies().size(); i++)
		{
			window.draw(eManager.getEnemies()[i]->sprite);
			cout << eManager.getEnemies()[i]->HP << endl;
			eManager.checkEnemy(eManager.getEnemies()[i], toKill, exManager);
		}
		for (auto i = 0; i < eManager.getEnemies().size(); i++)
		{
			if (eManager.getEnemies()[i]->boostClock.getElapsedTime().asSeconds() < eManager.getEnemies()[i]->boostDuration.asSeconds() && eManager.getEnemies()[i]->canBeBoosted == true)
			{
				eManager.getEnemies()[i]->attackCooldown = seconds(0.01);
			}
			else
			{
				switch (eManager.getEnemies()[i]->id)
				{
				case ENNEMI1:
					eManager.getEnemies()[i]->attackCooldown = seconds(3);
					break;
				case ENNEMI2:
					eManager.getEnemies()[i]->attackCooldown = seconds(1.5);
					break;
				case ENNEMI3:
					eManager.getEnemies()[i]->attackCooldown = seconds(1);
					break;
				case BOSS1:
					eManager.getEnemies()[i]->attackCooldown = seconds(0.08);
					break;
				case BOSS2:
					eManager.getEnemies()[i]->attackCooldown = seconds(0.2);
					break;
				case BOSS3:
					eManager.getEnemies()[i]->attackCooldown = seconds(0.2);
					break;
				case BOSS4:
					eManager.getEnemies()[i]->attackCooldown = seconds(0.06);
					break;
				}
			}
		}
		//Gestion des obstacles
		for (int i = 0; i < oManager.getObstacles().size(); i++) {
			window.draw(oManager.getObstacles()[i]->sprite);
			int randValue = rand() % 3;
			if (state != finalBoss)
				oManager.getObstacles()[i]->moveObstacle(randValue);
			else if (state == finalBoss)
				oManager.getObstacles()[i]->moveObstacleF();
			oManager.getObstacles()[i]->checkObstacle(player);
		}
		//Gestion de l'attaque des ennemis
		for (auto i = 0; i < eManager.getEnemies().size(); i++)
		{
			eManager.getEnemies()[i]->enemyMove();
			if (eManager.getEnemies()[i]->rechargeClock.getElapsedTime().asSeconds() > eManager.getEnemies()[i]->rechargeCooldown.asSeconds())
			{

				if (eManager.getEnemies()[i]->attackClock.getElapsedTime().asSeconds() > eManager.getEnemies()[i]->attackCooldown.asSeconds())
				{
					int projVelocityChance = rand() % 3;
					int projVelocity;
					switch (projVelocityChance) {
					case 1:
						projVelocity = -6;
						break;
					case 2:
						projVelocity = -7;
						break;
					case 3:
						projVelocity = -8;
						break;
					default:
						projVelocity = -9;
						break;
					}
					eManager.getEnemies()[i]->attackClock.restart();
					pManager.creerProjectile(eManager.getEnemies()[i], projVelocity);
					if (eManager.getEnemies()[i]->sprite.getPosition().x > 0 && eManager.getEnemies()[i]->sprite.getPosition().x < WIDTH)
						eManager.getEnemies()[i]->lasershot.play();

				}


				if (eManager.getEnemies()[i]->rechargeClock.getElapsedTime().asSeconds() > eManager.getEnemies()[i]->rechargeCooldown.asSeconds() * 2)
					eManager.getEnemies()[i]->rechargeClock.restart();
			}

		}

		for (int i = 0; i < exManager.getExplosions().size(); i++)
		{
			exManager.getExplosions()[i]->animate();
			window.draw(exManager.getExplosions()[i]->sprite);
			exManager.getExplosions()[i]->sprite.move(-4, 0);
			if (exManager.getExplosions()[i]->frame == 8)
			{
				exManager.detruireExplosion(exManager.getExplosions()[i]);
			}
		}
		updateScoreText(player, scoreText);
		healthbar.setHealthbar(player);
		player.checkOutOfScreen();

		window.draw(interface);

		if (player.HP > 0)
			window.draw(player.sprite);
		else
		{
			if (player.isAlive == true)
			{
				exManager.creerExplosion(player);
				player.isAlive = false;
				boss.stop();
				finalBossM.stop();
				playing.stop();
				lose.play();
			}
		}

		window.draw(scoreText);
		window.draw(coin);
		window.draw(healthbar.psprite);
		if (player.shield > 0)
			window.draw(healthbar.pShield);

		if(isFightingBoss == true)
		{
			for (int i = 0; i < eManager.getEnemies().size(); i++)
			{
				if (eManager.getEnemies()[i]->id == BOSS1 || eManager.getEnemies()[i]->id == BOSS2 || eManager.getEnemies()[i]->id == BOSS3 || eManager.getEnemies()[i]->id == BOSS4)
				{
					healthbar.setHealthbar(eManager.getEnemies()[i]);
					window.draw(healthbar.esprite);
					if (eManager.getEnemies()[i]->shield > 0)
						window.draw(healthbar.eShield);
				}
			}
		}
	}
}