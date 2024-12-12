#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include "enemy.hpp"
#include "projectile.hpp"
#include "obstacle.hpp"
#include "player.hpp"

enum gameState {
	titleScreen, paused, gameOver, shop, deleteData, editor, niveau1A, niveau1B, niveau1C, niveau2A, niveau2B, niveau2C, niveau3A, niveau3B, niveau3C, finalBoss
};

class Game {
public:
	gameState state = niveau1A;
	bool Univeau1A, loadLevel = true;
	bool Univeau2A, Univeau3A, Univeau1B, Univeau2B, Univeau3B, Univeau1C, Univeau2C, Univeau3C, UfinalBoss, isFightingBoss = false;
	int toKill = 0;
	Clock gameClock;
	Time gameDuration;
	void setGameDuration(float duration);
	void level1A(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager);
	void level1B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager);
	void level1C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager);
	void level2A(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager);
	void level2B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager);
	void level2C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager);
	void level3A(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager);
	void level3B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager);
	void level3C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager);
	void level4(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager);
};

#endif
