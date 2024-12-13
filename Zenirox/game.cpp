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
		isFightingBoss = true;
		toKill = 1;
		eManager.creerEnemy(BOSS1, 1400, 700);
		uManager.creerUtilitary(heart, 1000, 800);
		uManager.creerUtilitary(evilHeart, 1000, 700);
		uManager.creerUtilitary(battery, 1000, 600);
		uManager.creerUtilitary(evilBattery, 1000, 500);
		uManager.creerUtilitary(shield, 1000, 400);
		uManager.creerUtilitary(evilShield, 1000, 300);
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
		oManager.creerObstacle(1000, 100);
		oManager.creerObstacle(1000, 900);
		eManager.creerEnemy(BOSS4, 1400, 700);
	}
	
}

void Game::run(RenderWindow& window, Player& player, Sprite& coin, Background& background, Starparallaxe& star, fastStarparallaxe& faststar, Healthbar& healthbar, EnemyManager& eManager, ProjectileManager& pManager, ObstacleManager& oManager, UtilitaryManager& uManager, Clock& clock, Text& scoreText, Font& scoreFont, RectangleShape& interface)
{
	level1A(player, eManager, oManager, pManager, uManager);
	level1B(player, eManager, oManager, pManager, uManager);
	level1C(player, eManager, oManager, pManager, uManager);
	level2A(player, eManager, oManager, pManager, uManager);
	level2B(player, eManager, oManager, pManager, uManager);
	level2C(player, eManager, oManager, pManager, uManager);
	level3A(player, eManager, oManager, pManager, uManager);
	level3B(player, eManager, oManager, pManager, uManager);
	level3C(player, eManager, oManager, pManager, uManager);
	level4(player, eManager, oManager, pManager, uManager);
	if (player.boostClock.getElapsedTime().asSeconds() < player.boostDuration.asSeconds() && player.canBeBoosted == true)
	{
		player.attackCooldown = seconds(0.01);
	}
	else
		player.attackCooldown = seconds(0.01);

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
	// Dessine les étoile et leur defilement
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
		eManager.checkEnemy(eManager.getEnemies()[i], toKill);
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
		if(state != finalBoss)
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
					projVelocity = -4;
					break;
				case 2:
					projVelocity = -6;
					break;
				case 3:
					projVelocity = -7;
					break;
				default:
					projVelocity = -4;
					break;
				}
				eManager.getEnemies()[i]->attackClock.restart();
				pManager.creerProjectile(eManager.getEnemies()[i], projVelocity);
			}


			if (eManager.getEnemies()[i]->rechargeClock.getElapsedTime().asSeconds() > eManager.getEnemies()[i]->rechargeCooldown.asSeconds() * 2)
				eManager.getEnemies()[i]->rechargeClock.restart();
		}

	}

	updateScoreText(player, scoreText);
	healthbar.setHealthbar(player);
	player.checkOutOfScreen();

	window.draw(interface);

	if (player.HP > 0)
		window.draw(player.sprite);

	window.draw(scoreText);
	window.draw(coin);
	window.draw(healthbar.psprite);

	for (int i = 0; i < eManager.getEnemies().size(); i++)
	{
		if (eManager.getEnemies()[i]->id == BOSS1 || eManager.getEnemies()[i]->id == BOSS2 || eManager.getEnemies()[i]->id == BOSS3 || eManager.getEnemies()[i]->id == BOSS4)
		{
			healthbar.setHealthbar(eManager.getEnemies()[i]);
			window.draw(healthbar.esprite);
		}
	}
}