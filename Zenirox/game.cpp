#include "game.hpp"

Game::Game() : hoveredOption(-1) {
	// font
	if (!font.loadFromFile("UIfont.ttf")) {
		throw std::runtime_error("Failed to load texture");
	}

	//Musique de défaite
	if (!lose.openFromFile("sounds/lose.ogg")) throw runtime_error("Echec lors de l'ouverture de la musique de defaite");

	//Musique finalhours
	if (!finalhours.openFromFile("sounds/finalhours.ogg")) throw runtime_error("Echec lors de l'ouverture de la musique de defaite");
	finalhours.setLoop(true);

	//Musique écran titre
	if (!titleScreenM.openFromFile("sounds/titlescreen.ogg")) throw runtime_error("Echec lors de l'ouverture de l'opening");
	titleScreenM.setLoop(true);

	//Musique niveau suivant
	if (!nextLevelM.openFromFile("sounds/nextlevel.ogg")) throw runtime_error("Echec lors de l'ouverture de la musique de niveau suivant");

	//Musique éditeur
	if (!editorM.openFromFile("sounds/editor.ogg")) throw runtime_error("Echec lors de l'ouverture de la musique de l'editeur");
	editorM.setLoop(true);

	//Musique victoire
	if (!victoryM.openFromFile("sounds/victory.ogg")) throw runtime_error("Echec lors de l'ouverture de la musique de fin");

	//Son de confirmation
	if (!confirmSoundBuffer.loadFromFile("sounds/confirm.ogg")) throw runtime_error("Echec lors de l'ouverture du son de confirmation");
	confirmSound.setBuffer(confirmSoundBuffer);

	//Son de click sans confirmation
	if (!clickSoundBuffer.loadFromFile("sounds/click.ogg")) throw runtime_error("Echec lors de l'ouverture du son de click");
	clickSound.setBuffer(clickSoundBuffer);
	clickSound.setVolume(50);
}



void Game::setGameDuration(float duration) {
	gameDuration = seconds(duration);
}

void Game::level1A(Player& player, EnemyManager &eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{
	if (state == niveau1A && loadLevel == true && isFightingBoss == false && Univeau1A == true)
	{
		background.setupPalier1();
		doLoadBackground = false;
		finalhours.stop();
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(240);
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
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds() - gameDuration.asSeconds() / 4 && finalhours.getStatus() != Sound::Playing && player.HP >= 0 && lose.getStatus() != Sound::Playing)
	{
		playing.stop();
		finalBossM.stop();
		boss.stop();
		finalhours.play();
	}
	else if (state == niveau1A && toKill == 0 && isFightingBoss == false)
	{
		playing.stop(); 
		finalBossM.stop();
		if(finalhours.getStatus() != Sound::Playing)
			boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS1, 1400, 700);
		if(player.difficulty != Hardcore)
		{
			uManager.creerUtilitary(shield, 2000, 700);
			uManager.creerUtilitary(battery, 6000, 500);
			uManager.creerUtilitary(heart, 10000, 300);
		}
		if (player.difficulty == Hardcore)
		{
			uManager.creerUtilitary(evilBattery, 2000, 200);
			uManager.creerUtilitary(evilShield, 6000, 300);
			uManager.creerUtilitary(evilHeart, 10000, 700);
		}
		
		
		//Ecran de victoire...
	}
	if (isFightingBoss == true && toKill == 0 && Univeau1A == true && state == niveau1A)
	{
		screen = NextLevel;
	}
}

void Game::level1B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{
	
	if (state == niveau1B && loadLevel == true && isFightingBoss == false && Univeau1B == true)
	{
		background.setupPalier1();
		doLoadBackground = false;
		finalhours.stop();
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(240);
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
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds() - gameDuration.asSeconds() / 4 && finalhours.getStatus() != Sound::Playing && player.HP >= 0 && lose.getStatus() != Sound::Playing)
	{
		playing.stop();
		finalBossM.stop();
		boss.stop();
		finalhours.play();
	}
	if (state == niveau1B && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		if (finalhours.getStatus() != Sound::Playing)
			boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS1, 1400, 700);
		if (player.difficulty != Hardcore)
		{
			uManager.creerUtilitary(shield, 2000, 700);
			uManager.creerUtilitary(battery, 6000, 500);
			uManager.creerUtilitary(heart, 10000, 300);
		}
		if (player.difficulty == Hardcore)
		{
			uManager.creerUtilitary(evilBattery, 2000, 200);
			uManager.creerUtilitary(evilShield, 6000, 300);
			uManager.creerUtilitary(evilHeart, 10000, 700);
		}
	}
	if (isFightingBoss == true && toKill == 0 && Univeau1B == true && state == niveau1B)
	{
		screen = NextLevel;
	}
}

void Game::level1C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{
	if (state == niveau1C && loadLevel == true && isFightingBoss == false && Univeau1C == true)
	{
		background.setupPalier1();
		finalhours.stop();
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(240);
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
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds() - gameDuration.asSeconds() / 4 && finalhours.getStatus() != Sound::Playing && player.HP >= 0 && lose.getStatus() != Sound::Playing)
	{
		playing.stop();
		finalBossM.stop();
		boss.stop();
		finalhours.play();
	}
	if (state == niveau1C && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		if (finalhours.getStatus() != Sound::Playing)
			boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS1, 1400, 700);
		if (player.difficulty != Hardcore)
		{
			uManager.creerUtilitary(shield, 2000, 700);
			uManager.creerUtilitary(battery, 6000, 500);
			uManager.creerUtilitary(heart, 10000, 300);
		}
		if (player.difficulty == Hardcore)
		{
			uManager.creerUtilitary(evilBattery, 2000, 200);
			uManager.creerUtilitary(evilShield, 6000, 300);
			uManager.creerUtilitary(evilHeart, 10000, 700);
		}
	}
	if (isFightingBoss == true && toKill == 0 && Univeau1C == true && state == niveau1C)
	{
		screen = NextLevel;
	}
}

void Game::level2A(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{
	
	if (state == niveau2A && loadLevel == true && isFightingBoss == false && Univeau2A == true)
	{
		background.setupPalier2();
		finalhours.stop();
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(240);
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
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds() - gameDuration.asSeconds() / 4 && finalhours.getStatus() != Sound::Playing && player.HP >= 0 && lose.getStatus() != Sound::Playing)
	{
		playing.stop();
		finalBossM.stop();
		boss.stop();
		finalhours.play();
	}
	if (state == niveau2A && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		if (finalhours.getStatus() != Sound::Playing)
			boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS2, 1400, 700);
		if (player.difficulty != Hardcore)
		{
			uManager.creerUtilitary(shield, 2000, 700);
			uManager.creerUtilitary(battery, 6000, 500);
			uManager.creerUtilitary(heart, 10000, 300);
		}
		if (player.difficulty == Hardcore)
		{
			uManager.creerUtilitary(evilBattery, 2000, 200);
			uManager.creerUtilitary(evilShield, 6000, 300);
			uManager.creerUtilitary(evilHeart, 10000, 700);
		}
	}
	if (isFightingBoss == true && toKill == 0 && Univeau2A == true && state == niveau2A)
	{
		screen = NextLevel;
	}
}

void Game::level2B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{

	if (state == niveau2B && loadLevel == true && isFightingBoss == false && Univeau2B == true)
	{
		background.setupPalier2();
		finalhours.stop();
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(240);
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
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds() - gameDuration.asSeconds() / 4 && finalhours.getStatus() != Sound::Playing && player.HP >= 0 && lose.getStatus() != Sound::Playing)
	{
		playing.stop();
		finalBossM.stop();
		boss.stop();
		finalhours.play();
	}
	if (state == niveau2B && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		if (finalhours.getStatus() != Sound::Playing)
			boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS2, 1400, 700);
		if (player.difficulty != Hardcore)
		{
			uManager.creerUtilitary(shield, 2000, 700);
			uManager.creerUtilitary(battery, 6000, 500);
			uManager.creerUtilitary(heart, 10000, 300);
		}
		if (player.difficulty == Hardcore)
		{
			uManager.creerUtilitary(evilBattery, 2000, 200);
			uManager.creerUtilitary(evilShield, 6000, 300);
			uManager.creerUtilitary(evilHeart, 10000, 700);
		}
	}
	if (isFightingBoss == true && toKill == 0 && Univeau2B == true && state == niveau2B)
	{
		screen = NextLevel;
	}
}

void Game::level2C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{

	if (state == niveau2C && loadLevel == true && isFightingBoss == false && Univeau2C == true)
	{
		background.setupPalier2();
		finalhours.stop();
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(240);
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
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds() - gameDuration.asSeconds() / 4 && finalhours.getStatus() != Sound::Playing && player.HP >= 0 && lose.getStatus() != Sound::Playing)
	{
		playing.stop();
		finalBossM.stop();
		boss.stop();
		finalhours.play();
	}
	if (state == niveau2C && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		if (finalhours.getStatus() != Sound::Playing)
			boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS2, 1400, 700);
		if (player.difficulty != Hardcore)
		{
			uManager.creerUtilitary(shield, 2000, 700);
			uManager.creerUtilitary(battery, 6000, 500);
			uManager.creerUtilitary(heart, 10000, 300);
		}
		if (player.difficulty == Hardcore)
		{
			uManager.creerUtilitary(evilBattery, 2000, 200);
			uManager.creerUtilitary(evilShield, 6000, 300);
			uManager.creerUtilitary(evilHeart, 10000, 700);
		}
	}
	if (isFightingBoss == true && toKill == 0 && Univeau2C == true && state == niveau2C)
	{
		screen = NextLevel;
	}
}

void Game::level3A(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{

	if (state == niveau3A && loadLevel == true && isFightingBoss == false && Univeau3A == true)
	{
		background.setupPalier3();
		finalhours.stop();
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(240);
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
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds() - gameDuration.asSeconds() / 4 && finalhours.getStatus() != Sound::Playing && player.HP >= 0 && lose.getStatus() != Sound::Playing)
	{
		playing.stop();
		finalBossM.stop();
		boss.stop();
		finalhours.play();
	}
	if (state == niveau3A && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		if (finalhours.getStatus() != Sound::Playing)
			boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS3, 1400, 700);
		if (player.difficulty != Hardcore)
		{
			uManager.creerUtilitary(shield, 2000, 700);
			uManager.creerUtilitary(battery, 6000, 500);
			uManager.creerUtilitary(heart, 10000, 300);
		}
		if (player.difficulty == Hardcore)
		{
			uManager.creerUtilitary(evilBattery, 2000, 200);
			uManager.creerUtilitary(evilShield, 6000, 300);
			uManager.creerUtilitary(evilHeart, 10000, 700);
		}
	}
	if (isFightingBoss == true && toKill == 0 && Univeau3A == true && state == niveau3A)
	{
		screen = NextLevel;
	}
}

void Game::level3B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{

	if (state == niveau3B && loadLevel == true && isFightingBoss == false && Univeau3B == true)
	{
		background.setupPalier3();
		finalhours.stop();
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(300);
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
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds() - gameDuration.asSeconds() / 4 && finalhours.getStatus() != Sound::Playing && player.HP >= 0 && lose.getStatus() != Sound::Playing)
	{
		playing.stop();
		finalBossM.stop();
		boss.stop();
		finalhours.play();
	}
	if (state == niveau3B && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		if (finalhours.getStatus() != Sound::Playing)
			boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS3, 1400, 700);
		if (player.difficulty != Hardcore)
		{
			uManager.creerUtilitary(shield, 2000, 700);
			uManager.creerUtilitary(battery, 6000, 500);
			uManager.creerUtilitary(heart, 10000, 300);
		}
		if (player.difficulty == Hardcore)
		{
			uManager.creerUtilitary(evilBattery, 2000, 200);
			uManager.creerUtilitary(evilShield, 6000, 300);
			uManager.creerUtilitary(evilHeart, 10000, 700);
		}
	}
	if (isFightingBoss == true && toKill == 0 && Univeau3B == true && state == niveau3B)
	{
		screen = NextLevel;
	}
}

void Game::level3C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{

	if (state == niveau3C && loadLevel == true && isFightingBoss == false && Univeau3C == true)
	{
		background.setupPalier3();
		finalhours.stop();
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(360);
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
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds() - gameDuration.asSeconds() / 4 && finalhours.getStatus() != Sound::Playing && player.HP >= 0 && lose.getStatus() != Sound::Playing)
	{
		playing.stop();
		finalBossM.stop();
		boss.stop();
		finalhours.play();
	}
	if (state == niveau3C && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		if (finalhours.getStatus() != Sound::Playing)
			boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS3, 1400, 700);
		if (player.difficulty != Hardcore)
		{
			uManager.creerUtilitary(shield, 2000, 700);
			uManager.creerUtilitary(battery, 6000, 500);
			uManager.creerUtilitary(heart, 10000, 300);
		}
		if (player.difficulty == Hardcore)
		{
			uManager.creerUtilitary(evilBattery, 2000, 200);
			uManager.creerUtilitary(evilShield, 6000, 300);
			uManager.creerUtilitary(evilHeart, 10000, 700);
		}
	}
	if (isFightingBoss == true && toKill == 0 && Univeau3C == true && state == niveau3C)
	{
		screen = NextLevel;
	}
}

void Game::level4(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background, Starparallaxe& star, fastStarparallaxe& faststar)
{
	if (state == finalBoss && loadLevel == true && isFightingBoss == false && UfinalBoss == true)
	{
		background.setupPalier4();
		star.sprite.setColor(Color(245, 194, 254));
		star.sprite2.setColor(Color(245, 194, 254));
		faststar.sprite.setColor(Color(245, 194, 254));
		faststar.sprite2.setColor(Color(245, 194, 254));
		finalhours.stop();
		gameClock.restart();
		setGameDuration(360);
		toKill = 0;
		
		

		loadLevel = false;
	}
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds())
	{
		player.HP = 0;
	}
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds() - gameDuration.asSeconds() / 4 && finalhours.getStatus() != Sound::Playing && player.HP >= 0 && lose.getStatus() != Sound::Playing)
	{
		playing.stop();
		finalBossM.stop();
		boss.stop();
		finalhours.play();
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
		if (player.difficulty != Hardcore)
		{
			uManager.creerUtilitary(shield, 2000, 700);
			uManager.creerUtilitary(battery, 6000, 500);
			uManager.creerUtilitary(heart, 10000, 300);
		}
		uManager.creerUtilitary(evilBattery, 2000, 200);
		uManager.creerUtilitary(evilShield, 6000, 300);
		uManager.creerUtilitary(evilHeart, 10000, 700);
	}
	if (isFightingBoss == true && toKill == 0 && state == finalBoss)
	{
		screen = Win;
	}
	
}

void Game::levelP(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{
	if (state == niveauEDIT && loadLevel == true && isFightingBoss == false)
	{
		background.setupPalier1();
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(240);
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
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds() - gameDuration.asSeconds() / 4 && finalhours.getStatus() != Sound::Playing && player.HP >= 0 && lose.getStatus() != Sound::Playing)
	{
		playing.stop();
		finalBossM.stop();
		boss.stop();
		finalhours.play();
	}
	else if (state == niveauEDIT && toKill == 0 && isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		if (finalhours.getStatus() != Sound::Playing)
			boss.play();
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(bossID, 1400, 700);
		if (player.difficulty != Hardcore)
		{
			uManager.creerUtilitary(shield, 2000, 700);
			uManager.creerUtilitary(battery, 6000, 500);
			uManager.creerUtilitary(heart, 10000, 300);
		}
	}
	if (isFightingBoss == true && toKill == 0 && state == niveauEDIT)
	{
		screen = NextLevel;
	}

}

void Game::run(RenderWindow& window, Player& player, Sprite& coin, Background& background, Starparallaxe& star, fastStarparallaxe& faststar, Healthbar& healthbar, EnemyManager& eManager, ProjectileManager& pManager, ObstacleManager& oManager, UtilitaryManager& uManager, ExplosionManager& exManager, Clock& clock, Text& scoreText, Font& scoreFont, RectangleShape& interface, Music& playing, Music& boss, Music& finalBossM, vector<Sound>& playerShot, SoundBuffer& shot, Text& totalScoreText)
{

	if (screen == Menu) {

		// background texture
		if (!backgroundTexture.loadFromFile("mainmenu.png")) {
			throw std::runtime_error("Failed to load texture");
		}
		backgroundSprite.setTexture(backgroundTexture);
		backgroundSprite.setPosition(0, 0);

		// title
		title.setFont(font);
		title.setString("ZENIROX");
		title.setCharacterSize(150);
		title.setFillColor(sf::Color::White);
		title.setOutlineColor(sf::Color::Black);
		title.setOutlineThickness(6);
		title.setPosition(665, 100);


		// Load the texture and set the sprite
		if (!close.loadFromFile("close.png")) {
			throw runtime_error("Erreur : texture de l'oiseau introuvable.");
		}

		close.setTexture(close);
		bird.setPosition(200.f, 400.f); // Initial position of the bird



		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Enter)
					window.close();
			}
		}
		window.draw(backgroundSprite);
		window.draw(title);
	}


	if (screen == Win)
	{
		finalBossM.stop();
		boss.stop();
		playing.stop();
		nextLevelM.stop();
		editorM.stop();
		editorM.stop();
		if(victoryM.getStatus() != Sound::Playing)
			victoryM.play();
		Sprite winBackground;
		Texture winBackgroundT;
		if (!winBackgroundT.loadFromFile("winscreen.png")) throw runtime_error("Erreur lors du chargement de l'ecran de victoire");
		winBackground.setTexture(winBackgroundT);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				saveCurrentScore(player);
				saveScore(player);
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Enter)
				{
					window.close();
					saveCurrentScore(player);
					saveScore(player);
				}
			}
		}
		window.draw(winBackground);
	}
	if (screen == Lost)
	{
		Sprite lostScreen;
		Texture lostScreenT;
		if (!lostScreenT.loadFromFile("lostscreen.png")) throw runtime_error("Erreur lors du chargement de l'ecran de defaite");
		lostScreen.setTexture(lostScreenT);
		Event event;
		pManager.~ProjectileManager();
		oManager.~ObstacleManager();
		uManager.~UtilitaryManager();
		exManager.~ExplosionManager();
		eManager.~EnemyManager();
		player.currentScore = 0;
		player.isAlive = true;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Enter)
				{
				confirmSound.play();
					switch (state)
					{
					case niveauEDIT:
						isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						screen = Editor;
						counter = 1;
						break;
					case niveau1A:
						isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case niveau1B:
						isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case niveau1C:
						isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case niveau2A:
						isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case niveau2B:
						isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case niveau2C:
						isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case niveau3A:
						isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case niveau3B:
						isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case niveau3C:
						isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case finalBoss:
						isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					default:
						break;
					}
					lose.stop();
					player.HP = player.maxHP;
					if(state != niveauEDIT)
						screen = Playing;
				}
			}
		}
		window.draw(lostScreen);
	}

	if (screen == NextLevel)
	{
		boss.stop();
		if (nextLevelM.getStatus() != Sound::Playing)
			nextLevelM.play();
		finalBossM.stop();
		finalhours.stop();
		pManager.~ProjectileManager();
		oManager.~ObstacleManager();
		uManager.~UtilitaryManager();
		exManager.~ExplosionManager();
		coin.setScale(0.5, 0.5);
		coin.setPosition(750, 470);
		saveCurrentScore(player);
		setTotalScoreText(player, scoreFont, totalScoreText);
		player.currentScore = 0;
		Sprite nextLevelBackground;
		Texture nextLevelBackgroundT;
		if (!nextLevelBackgroundT.loadFromFile("levelwin.png")) throw runtime_error("Erreur de chargement du fond de niveau suivant");
		nextLevelBackground.setTexture(nextLevelBackgroundT);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				saveCurrentScore(player);
				saveScore(player);
				window.close();
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Enter)
				{
				confirmSound.play();
					switch (state)
					{
					case niveauEDIT:
						saveCurrentScore(player);
						saveScore(player);
						loadLevel = true;
						doLoadBackground = true;
						isFightingBoss = false;
						counter = 1;
						state = niveauEDIT;
						screen = Editor;
						nextLevelM.stop();
						break;
					case niveau1A:
						isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						Univeau1B = true;
						state = niveau1B;
						break;
					case niveau1B:
						isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						Univeau1C = true;
						state = niveau1C;
						break;
					case niveau1C:
						isFightingBoss = false;
						loadLevel = true;
						Univeau2A = true;
						state = niveau2A;
						break;
					case niveau2A:
						isFightingBoss = false;
						loadLevel = true;
						Univeau2B = true;
						state = niveau2B;
						break;
					case niveau2B:
						isFightingBoss = false;
						loadLevel = true;
						Univeau2C = true;
						state = niveau2C;
						break;
					case niveau2C:
						isFightingBoss = false;
						loadLevel = true;
						Univeau3A = true;
						state = niveau3A;
						break;
					case niveau3A:
						isFightingBoss = false;
						loadLevel = true;
						Univeau3B = true;
						state = niveau3B;
						break;
					case niveau3B:
						isFightingBoss = false;
						loadLevel = true;
						Univeau3C = true;
						state = niveau3C;
						break;
					case niveau3C:
						isFightingBoss = false;
						loadLevel = true;
						UfinalBoss = true;
						state = finalBoss;
						break;
					case finalBoss:
						break;
					default:
						break;
					}
					saveCurrentScore(player);
					player.currentScore = 0;
					coin.setPosition(0, 50);
					coin.setScale(0.2, 0.2);
					if(state != niveauEDIT)
					{
						screen = Playing;
						nextLevelM.stop();
					}

				}
			}
		}
		window.draw(nextLevelBackground);
		window.draw(totalScoreText);
		window.draw(coin);
	}
	if (screen == Editor)
	{
		if(editorM.getStatus() != Sound::Playing)
			editorM.play();
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
			if (event.type == Event::MouseButtonPressed || event.type == Event::KeyPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window);
				if (event.mouseButton.button == Mouse::Left && up.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) || event.key.code == Keyboard::Up)
				{
					
					if (currentID != IDlist.size() - 1)
					{
						currentID++;
						clickSound.play();
					}
				}
				if (event.mouseButton.button == Mouse::Left && down.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) || event.key.code == Keyboard::Down)
				{
					
					if (currentID != 0)
					{
						currentID--;
						clickSound.play();
					}
				}
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
				confirmSound.play();
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
						player.HP = player.maxHP;
						screen = Playing;
						editorM.stop();
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
			if(state == niveau1A)
				level1A(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);
			else if(state == niveau1B)
				level1B(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);
			else if (state == niveau1C)
				level1C(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);
			else if (state == niveau2A)
				level2A(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);
			else if (state == niveau2B)
				level2B(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);
			else if (state == niveau2C)
				level2C(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);
			else if (state == niveau3A)
				level3A(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);
			else if (state == niveau3B)
				level3B(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);
			else if (state == niveau3C)
				level3C(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);
			else if (state == finalBoss)
				level4(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background, star, faststar);
		}
		else if (state == niveauEDIT)
			levelP(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);

		if (player.boostClock.getElapsedTime().asSeconds() < player.boostDuration.asSeconds() && player.canBeBoosted == true)
		{
			player.attackCooldown = seconds(0.1);
		}
		else
			player.attackCooldown = seconds(0.2);

		player.checkOutOfScreen(); //Empêche de sortir de l'écran
		Event event;
		if (Keyboard::isKeyPressed(Keyboard::Up))
			player.sprite.move(0, -10);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			player.sprite.move(0, 10);

		//Créé un projectile lorsqu'il y a un click gauche avec un cooldown

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
		// Mettre à jour l'arrière-plan
		background.update(deltaTime);
		star.update(deltaTime);
		faststar.update(deltaTime);

		window.clear();

		background.draw(window);
		star.draw(window);
		faststar.draw(window);

		//Gestion de l'affichage, de la durée de vie des projectiles et des dégâts infligés
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
		//Regarde si un ennemi sort de l'écran ou si il est mort
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
				eManager.getEnemies()[i]->attackCooldown = seconds(0.05);
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
				finalhours.stop();
				lose.play();
				screen = Lost;
				player.shield = 0;
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