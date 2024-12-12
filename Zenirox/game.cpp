#include "game.hpp"
#include "projectile.hpp"

void Game::setGameDuration(float duration) {
	gameDuration = seconds(duration);
}

void Game::level1A(Player& player, EnemyManager &eManager, ObstacleManager& oManager, ProjectileManager& pManager)
{
	if (state == niveau1A && loadLevel == true && isFightingBoss == false && Univeau1A == true)
	{
		gameClock.restart();
		setGameDuration(120);
		toKill = 10;

		eManager.creerEnemy(ENNEMI1, 1000, 500);
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
void Game::level1B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager)
{
	
	if (state == niveau1B && loadLevel == true && isFightingBoss == false && Univeau1B == true)
	{
		gameClock.restart();
		setGameDuration(120);
		toKill = 10;
		eManager.creerEnemy(ENNEMI1, 1000, 500);
		eManager.creerEnemy(ENNEMI1, 2500, 300);
		eManager.creerEnemy(ENNEMI2, 4000, 700);
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
void Game::level1C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager)
{
	if (state == niveau1C && loadLevel == true && isFightingBoss == false && Univeau1C == true)
	{
		gameClock.restart();
		setGameDuration(120);
		toKill = 10;
		eManager.creerEnemy(ENNEMI1, 1000, 500);
		eManager.creerEnemy(ENNEMI1, 2500, 300);
		eManager.creerEnemy(ENNEMI2, 4000, 700);
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

void Game::level2A(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager)
{
	
	if (state == niveau2A && loadLevel == true && isFightingBoss == false && Univeau2A == true)
	{
		gameClock.restart();
		setGameDuration(120);
		toKill = 10;
		eManager.creerEnemy(ENNEMI2, 1000, 500);
		eManager.creerEnemy(ENNEMI2, 2500, 300);
		eManager.creerEnemy(ENNEMI2, 4000, 700);
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
}