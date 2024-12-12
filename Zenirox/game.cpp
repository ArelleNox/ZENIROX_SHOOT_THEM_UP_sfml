#include "game.hpp"
#include "projectile.hpp"
#include "powerups.hpp"

void Game::setGameDuration(float duration) {
	gameDuration = seconds(duration);
}

void Game::level1A(Player& player, EnemyManager &eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager)
{
	if (state == niveau1A && loadLevel == true && isFightingBoss == false && Univeau1A == true)
	{
		gameClock.restart();
		setGameDuration(120);
		toKill = 10;

		eManager.creerEnemy(ENNEMI1, 1000, 500);
		eManager.creerEnemy(ENNEMI1, 2500, 300);
		uManager.creerUtilitary(heart, 2500, 800);
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

void Game::level1B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager)
{
	
	if (state == niveau1B && loadLevel == true && isFightingBoss == false && Univeau1B == true)
	{
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

void Game::level1C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager)
{
	if (state == niveau1C && loadLevel == true && isFightingBoss == false && Univeau1C == true)
	{
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

void Game::level2A(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager)
{
	
	if (state == niveau2A && loadLevel == true && isFightingBoss == false && Univeau2A == true)
	{
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

void Game::level2B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager)
{

	if (state == niveau2B && loadLevel == true && isFightingBoss == false && Univeau2B == true)
	{
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

void Game::level2C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager)
{

	if (state == niveau2C && loadLevel == true && isFightingBoss == false && Univeau2C == true)
	{
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

void Game::level3A(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager)
{

	if (state == niveau3A && loadLevel == true && isFightingBoss == false && Univeau3A == true)
	{
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

void Game::level3B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager)
{

	if (state == niveau3B && loadLevel == true && isFightingBoss == false && Univeau3B == true)
	{
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

void Game::level3C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager)
{

	if (state == niveau3C && loadLevel == true && isFightingBoss == false && Univeau3C == true)
	{
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

void Game::level4(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager)
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
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS4, 1400, 700);
	}
	
}