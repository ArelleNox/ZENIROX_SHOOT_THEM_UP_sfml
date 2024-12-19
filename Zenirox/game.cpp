#include "game.hpp"
#include <stdexcept>

Game::Game() : hoveredOption(-1) {
	// font
	if (!font.loadFromFile("UIfont.ttf")) {
		throw std::runtime_error("Failed to load texture");
	}

	// background texture
	if (!backgroundTexture.loadFromFile("mainmenu.png")) {
		throw std::runtime_error("Failed to load texture");
	}

	//Load the texture and set the sprite
	if (!closeT.loadFromFile("button/close.png")) {
		throw runtime_error("Erreur : texture de close introuvable.");
	}
	closeS.setTexture(closeT);
	closeS.setScale(2, 2);

	//Load the texture and set the sprite
	if (!confirmT.loadFromFile("button/confirm.png")) {
		throw runtime_error("Erreur : texture de close introuvable.");
	}
	confirmS.setTexture(confirmT);
	confirmS.setScale(2, 2);

	//Load the texture and set the sprite
	if (!editorT.loadFromFile("button/editor.png")) {
		throw runtime_error("Erreur : texture de close introuvable.");
	}
	editorS.setTexture(editorT);
	editorS.setScale(2, 2);

	//Load the texture and set the sprite
	if (!cancelT.loadFromFile("button/cancel.png")) {
		throw runtime_error("Erreur : texture de close introuvable.");
	}
	cancelS.setTexture(cancelT);
	cancelS.setScale(2, 2);

	//Load the texture and set the sprite
	if (!dataT.loadFromFile("button/data.png")) {
		throw runtime_error("Erreur : texture de close introuvable.");
	}
	dataS.setTexture(dataT);
	dataS.setScale(2, 2);

	//Load the texture and set the sprite
	if (!easyT.loadFromFile("button/easy.png")) {
		throw runtime_error("Erreur : texture de close introuvable.");
	}
	easyS.setTexture(easyT);
	easyS.setScale(2, 2);

	//Load the texture and set the sprite
	if (!hardcoreT.loadFromFile("button/hardcore.png")) {
		throw runtime_error("Erreur : texture de close introuvable.");
	}
	hardcoreS.setTexture(hardcoreT);
	hardcoreS.setScale(2, 2);

	//Load the texture and set the sprite
	if (!menuT.loadFromFile("button/menu.png")) {
		throw runtime_error("Erreur : texture de close introuvable.");
	}
	menuS.setTexture(menuT);
	menuS.setScale(2, 2);

	//Load the texture and set the sprite
	if (!normalT.loadFromFile("button/normal.png")) {
		throw runtime_error("Erreur : texture de close introuvable.");
	}
	normalS.setTexture(normalT);
	normalS.setScale(2, 2);

	//Load the texture and set the sprite
	if (!questT.loadFromFile("button/quest.png")) {
		throw runtime_error("Erreur : texture de close introuvable.");
	}
	questS.setTexture(questT);
	questS.setScale(2, 2);

	//Load the texture and set the sprite
	if (!resumeT.loadFromFile("button/resume.png")) {
		throw runtime_error("Erreur : texture de close introuvable.");
	}
	resumeS.setTexture(resumeT);
	resumeS.setScale(2, 2);

	//Load the texture and set the sprite
	if (!settingsT.loadFromFile("button/settings.png")) {
		throw runtime_error("Erreur : texture de close introuvable.");
	}
	settingsS.setTexture(settingsT);
	settingsS.setScale(2, 2);


	//Load the texture and set the sprite
	if (!buyT.loadFromFile("button/buy.png")) {
		throw runtime_error("Erreur : texture de close introuvable.");
	}
	buyS.setTexture(buyT);
	buyS.setScale(2, 2);

	//Load the texture and set the sprite
	if (!yesT.loadFromFile("button/yes.png")) {
		throw runtime_error("Erreur : texture de close introuvable.");
	}
	yesS.setTexture(yesT);
	yesS.setScale(1.5, 1.5);
	yes2S.setTexture(yesT);
	yes2S.setScale(1.5, 1.5);

	//Load the texture and set the sprite
	if (!noT.loadFromFile("button/no.png")) {
		throw runtime_error("Erreur : texture de close introuvable.");
	}
	noS.setTexture(noT);
	noS.setScale(1.5, 1.5);
	no2S.setTexture(noT);
	no2S.setScale(1.5, 1.5);

	//Load the texture and set the sprite
	if (!backT.loadFromFile("button/back.png")) throw runtime_error("Erreur: texture de back introuvable");
	backS.setTexture(backT);
	backS.setScale(2, 2);

	//Load the texture and set the sprite
	if (!shopT.loadFromFile("button/shop.png")) throw runtime_error("Erreur: texture de back introuvable");
	shopS.setTexture(shopT);

	//Load the texture and set the sprite
	if (!continueT.loadFromFile("button/continue.png")) throw runtime_error("Erreur: texture de continue introuvable");
	continueS.setTexture(continueT);
	continueS.setScale(2, 2);

	//Load the texture and set the sprite
	if (!resetT.loadFromFile("button/reset.png")) throw runtime_error("Erreur: texture du bouton reset inrouvable");
	resetS.setTexture(resetT);
	resetS.setScale(2, 2);
	

	//Musique de d�faite
	if (!lose.openFromFile("sounds/lose.ogg")) throw runtime_error("Echec lors de l'ouverture de la musique de defaite");

	//Musique finalhours
	if (!finalhours.openFromFile("sounds/finalhours.ogg")) throw runtime_error("Echec lors de l'ouverture de la musique de defaite");
	finalhours.setLoop(true);

	//Musique �cran titre
	if (!titleScreenM.openFromFile("sounds/titlescreen.ogg")) throw runtime_error("Echec lors de l'ouverture de l'opening");
	titleScreenM.setLoop(true);
	titleScreenM.setVolume(15);

	//Musique niveau suivant
	if (!nextLevelM.openFromFile("sounds/nextlevel.ogg")) throw runtime_error("Echec lors de l'ouverture de la musique de niveau suivant");

	//Musique �diteur
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

	//Son de click impossible
	if (!impossibleActionSoundBuffer.loadFromFile("sounds/impossible.ogg")) throw runtime_error("Echec lors de l'ouverture du son de click impossible");
	impossibleAction.setBuffer(impossibleActionSoundBuffer);

	//Texte du niveau actuel
	if (!currentLevelFont.loadFromFile("font.otf")) throw runtime_error("Erreur de chargement de la police de niveau actuel");
	currentLevelText.setFont(currentLevelFont);
	currentLevelText.setPosition(750, 25);
	currentLevelText.setCharacterSize(40);
	currentLevelText.setOutlineColor(Color::Black);
	currentLevelText.setOutlineThickness(4);

	//Sprites DLC
	if (!inventoryShipT.loadFromFile("inventory/ship.png")) throw runtime_error("Erreur lors du chargement de la texture d'inventaire du vaisseau par d�faut");
	if (!inventoryShip1T.loadFromFile("inventory/ship1.png")) throw runtime_error("Erreur lors du chargement de la texture d'inventaire du vaisseau 1");
	if (!inventoryShip2T.loadFromFile("inventory/ship2.png")) throw runtime_error("Erreur lors du chargement de la texture d'inventaire du vaisseau 2");
	if (!inventoryShip3T.loadFromFile("inventory/ship3.png")) throw runtime_error("Erreur lors du chargement de la texture d'inventaire du vaisseau 3");
	if (!buyShip1T.loadFromFile("shop/ship1.png")) throw runtime_error("Erreur chargement texture shop ship1");
	if (!buyShip2T.loadFromFile("shop/ship2.png")) throw runtime_error("Erreur chargement texture shop ship2");
	if (!buyShip3T.loadFromFile("shop/ship3.png")) throw runtime_error("Erreur chargement texture shop ship3");
	inventoryShipS.setTexture(inventoryShipT);
	inventoryShip1S.setTexture(inventoryShip1T);
	inventoryShip2S.setTexture(inventoryShip2T);
	inventoryShip3S.setTexture(inventoryShip3T);
	buyShip1S.setTexture(buyShip1T);
	buyShip2S.setTexture(buyShip2T);
	buyShip3S.setTexture(buyShip3T);
}



void Game::setGameDuration(float duration) {
	gameDuration = seconds(duration);
}

void Game::level1A(Player& player, EnemyManager &eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{
	if (state == niveau1A && loadLevel == true && isFightingBoss == false && Univeau1A == true)
	{
		currentLevelText.setString("TIER: 1 - LEVEL: 1");
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
		previousScreen = screen;
		screen = NextLevel;
	}
}

void Game::level1B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{
	
	if (state == niveau1B && loadLevel == true && isFightingBoss == false && Univeau1B == true)
	{
		currentLevelText.setString("TIER: 1 - LEVEL: 2");
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
		previousScreen = screen;
		screen = NextLevel;
	}
}

void Game::level1C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{
	if (state == niveau1C && loadLevel == true && isFightingBoss == false && Univeau1C == true)
	{
		currentLevelText.setString("TIER: 1 - LEVEL: 3");
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
		previousScreen = screen;
		screen = NextLevel;
	}
}

void Game::level2A(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{
	
	if (state == niveau2A && loadLevel == true && isFightingBoss == false && Univeau2A == true)
	{
		currentLevelText.setString("TIER: 2 - LEVEL: 1");
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
		previousScreen = screen;
		screen = NextLevel;
	}
}

void Game::level2B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{

	if (state == niveau2B && loadLevel == true && isFightingBoss == false && Univeau2B == true)
	{
		currentLevelText.setString("TIER: 2 - LEVEL: 2");
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
		previousScreen = screen;
		screen = NextLevel;
	}
}

void Game::level2C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{

	if (state == niveau2C && loadLevel == true && isFightingBoss == false && Univeau2C == true)
	{
		currentLevelText.setString("TIER: 2 - LEVEL: 3");
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
		previousScreen = screen;
		screen = NextLevel;
	}
}

void Game::level3A(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{

	if (state == niveau3A && loadLevel == true && isFightingBoss == false && Univeau3A == true)
	{
		currentLevelText.setString("TIER: 3 - LEVEL: 1");
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
		previousScreen = screen;
		screen = NextLevel;
	}
}

void Game::level3B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{

	if (state == niveau3B && loadLevel == true && isFightingBoss == false && Univeau3B == true)
	{
		currentLevelText.setString("TIER: 3 - LEVEL: 2");
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
		previousScreen = screen;
		screen = NextLevel;
	}
}

void Game::level3C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{

	if (state == niveau3C && loadLevel == true && isFightingBoss == false && Univeau3C == true)
	{
		currentLevelText.setString("TIER: 3 - LEVEL: 3");
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
		previousScreen = screen;
		screen = NextLevel;
	}
}

void Game::level4(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background, Starparallaxe& star, fastStarparallaxe& faststar)
{
	if (state == finalBoss && loadLevel == true && isFightingBoss == false && UfinalBoss == true)
	{
		currentLevelText.setString("FINAL BOSS");
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
		previousScreen = screen;
		hasWon = true;
		screen = Win;

		saveData(player, *this);
		openData(player, *this);
	}
	
}

void Game::levelP(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{
	if (state == niveauEDIT && loadLevel == true && isFightingBoss == false)
	{
		currentLevelText.setString("EDITED LEVEL");
		background.setupPalier1();
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(240);
		toKill = 10;

		if(EloadObstacle == true)
			oManager.creerObstacle(4700, 500);
		eManager.creerEnemy(nb1, 1000, 600);
		eManager.creerEnemy(nb2, 2500, 300);
		eManager.creerEnemy(nb3, 4000, 700);
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
		if (EloadPowerups == true)
		{
			if (player.difficulty == Easy)
			{
				uManager.creerUtilitary(shield, 2000, 700);
				uManager.creerUtilitary(battery, 6000, 500);
				uManager.creerUtilitary(heart, 10000, 300);
			}
			else if (player.difficulty == Hardcore)
			{
				uManager.creerUtilitary(evilBattery, 2000, 200);
				uManager.creerUtilitary(evilShield, 6000, 300);
				uManager.creerUtilitary(evilHeart, 10000, 700);
			}
			else if (player.difficulty == Normal)
			{
				uManager.creerUtilitary(shield, 2000, 700);
				uManager.creerUtilitary(battery, 6000, 500);
				uManager.creerUtilitary(heart, 10000, 300);
				uManager.creerUtilitary(evilBattery, 2000, 200);
				uManager.creerUtilitary(evilShield, 6000, 300);
				uManager.creerUtilitary(evilHeart, 10000, 700);
			}
		}
	}
	if (isFightingBoss == true && toKill == 0 && state == niveauEDIT)
	{
		isFightingBoss = false;
		doLoadBackground = true;
		loadLevel = true;
		boss.stop();
		previousScreen = screen;
		screen = Editor;
		counter = 1;
		currentID = 0;
		previousScreen = SetDifficulty;


	}

}

void Game::run(RenderWindow& window, Player& player, Sprite& coin, Background& background, Starparallaxe& star, fastStarparallaxe& faststar, Healthbar& healthbar, EnemyManager& eManager, ProjectileManager& pManager, ObstacleManager& oManager, UtilitaryManager& uManager, ExplosionManager& exManager, Clock& clock, Text& scoreText, Font& scoreFont, RectangleShape& interface, Music& playing, Music& boss, Music& finalBossM, vector<Sound>& playerShot, SoundBuffer& shot, Text& totalScoreText)
{
	if (screen == Shop)
	{
			Sprite shopBackgroundS;
			Texture shopBackgroundT;
			if (!shopBackgroundT.loadFromFile("shop.png")) throw runtime_error("Erreur chargement fond shop");
			buyShip1S.setPosition(112, 351);
			buyShip2S.setPosition(810, 351);
			buyShip3S.setPosition(1508, 351);
			backS.setScale(2, 2);
			backS.setPosition(360, 860);
			settingsS.setPosition(1163, 860);
			settingsS.setScale(2, 2);
			coin.setScale(0.26, 0.26);
			coin.setPosition(880, 5);
			totalScoreText.setScale(1, 1);
			setTotalScoreText(player, scoreFont, totalScoreText);
			totalScoreText.setPosition(880, 0);
			


			shopBackgroundS.setTexture(shopBackgroundT);

			Event event;

			while (window.pollEvent(event))
				if (event.type == Event::Closed)
					window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window);

				if (player.UShip1 == false && event.mouseButton.button == Mouse::Left && buyShip1S.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					if (player.totalScore >= 2500)
					{
						player.buy.play();
						player.totalScore -= 2500;
						player.UShip1 = true;
						saveData(player, *this);
					}
					else
						impossibleAction.play();
				}
				if (player.UShip2 == false && event.mouseButton.button == Mouse::Left && buyShip2S.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					if (player.totalScore >= 4000)
					{
						player.buy.play();
						player.totalScore -= 4000;
						player.UShip2 = true;
						saveData(player, *this);
					}
					else
						impossibleAction.play();
				}
				if (player.UShip3 == false && event.mouseButton.button == Mouse::Left && buyShip3S.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					if (player.totalScore >= 7500)
					{
						player.buy.play();
						player.totalScore -= 7500;
						player.UShip3 = true;
						saveData(player, *this);
					}
					else
						impossibleAction.play();
				}
				if (event.mouseButton.button == Mouse::Left && backS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					screen = previousScreen;
				}
				if (event.mouseButton.button == Mouse::Left && settingsS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					screen = Settings;
				}
			}

			
			window.draw(shopBackgroundS);
			if (player.UShip1 == false)
				window.draw(buyShip1S);
			if (player.UShip2 == false)
				window.draw(buyShip2S);
			if (player.UShip3 == false)
				window.draw(buyShip3S);
			window.draw(backS);
			window.draw(settingsS);
			window.draw(coin);
			window.draw(totalScoreText);
	}
	if (screen == Settings)
	{
		Sprite settingsBackgroundS;
		Texture settingsBackgroundT;
		if (!settingsBackgroundT.loadFromFile("inventory.png")) throw runtime_error("Erreur chargement fond inventaire");
		inventoryShipS.setPosition(49, 471);
		inventoryShip1S.setPosition(561, 471);
		inventoryShip2S.setPosition(1059, 471);
		inventoryShip3S.setPosition(1571, 471);
		backS.setScale(2, 2);
		backS.setPosition(360, 860);
		shopS.setPosition(1163, 860);
		settingsBackgroundS.setTexture(settingsBackgroundT);

		Event event;

		while(window.pollEvent(event))
			if(event.type == Event::Closed)
				window.close();
		if (event.type == Event::MouseButtonPressed)
		{
			Vector2i mousePos = Mouse::getPosition(window);

			if (event.mouseButton.button == Mouse::Left && backS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
			{
				confirmSound.play();
				screen = previousScreen;
			}
			if (event.mouseButton.button == Mouse::Left && shopS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
			{
				confirmSound.play();
				screen = Shop;
			}
			if (event.mouseButton.button == Mouse::Left && inventoryShipS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
			{
				confirmSound.play();
				player.ship = Default;
				player.changeShip();
				screen = previousScreen;
			}
			if (player.UShip1 == true && event.mouseButton.button == Mouse::Left && inventoryShip1S.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
			{
				confirmSound.play();
				player.ship = Ship1;
				player.changeShip();
				screen = previousScreen;
			}
			if (player.UShip2 == true && event.mouseButton.button == Mouse::Left && inventoryShip2S.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
			{
				confirmSound.play();
				player.ship = Ship2;
				player.changeShip();
				screen = previousScreen;
			}
			if (player.UShip3 == true && event.mouseButton.button == Mouse::Left && inventoryShip3S.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
			{
				confirmSound.play();
				player.ship = Ship3;
				player.changeShip();
				screen = previousScreen;
			}
		}

		window.draw(settingsBackgroundS);
		window.draw(inventoryShipS);
		if(player.UShip1 == true)
			window.draw(inventoryShip1S);
		if(player.UShip2 == true)
			window.draw(inventoryShip2S);
		if(player.UShip3 == true)
			window.draw(inventoryShip3S);
		window.draw(backS);
		window.draw(shopS);
	}

	if (screen == SetDifficulty)
	{
		openData(player, *this);
		if (previousScreen == Editor)
			loadEdited = true;
		backS.setScale(2, 2);
		Sprite SetDifficultyS;
		Texture SetDifficultyT;
		if (!SetDifficultyT.loadFromFile("difficulty.png")) throw runtime_error("Erreur : texture fond difficult� non trouv�");
		SetDifficultyS.setTexture(SetDifficultyT);
		easyS.setPosition(276, 496);
		normalS.setPosition(760, 496);
		hardcoreS.setPosition(1240, 496);
		backS.setPosition(760, 777);
		if (previousScreen == Editor)
			if (editorM.getStatus() != Sound::Playing)
				editorM.play();
		if (previousScreen == Menu)
			if (titleScreenM.getStatus() != Sound::Playing)
				titleScreenM.play();

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window);

				if (event.mouseButton.button == Mouse::Left && easyS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					player.setDifficulty(Easy);
					confirmSound.play();
					titleScreenM.stop();
					previousScreen = screen;
					if (loadCampain == true)
					{
						screen = Playing;
						loadCampain = false;
						if (UfinalBoss == true)
							state = finalBoss;
						else if (Univeau3C == true)
							state = niveau3C;
						else if (Univeau3B == true)
							state = niveau3B;
						else if (Univeau3A == true)
							state = niveau3A;
						else if (Univeau2C == true)
							state = niveau2C;
						else if (Univeau2B == true)
							state = niveau2B;
						else if (Univeau2A == true)
							state = niveau2A;
						else if (Univeau1C == true)
							state = niveau1C;
						else if (Univeau1B == true)
							state = niveau1B;
						else
							state = niveau1A;
					}
					else if (loadEdited == true)
					{
						screen = previousScreen;
						screen = Editor;
						loadEdited = false;
					}
					
				}
				if (event.mouseButton.button == Mouse::Left && normalS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					player.setDifficulty(Normal);
					confirmSound.play();
					titleScreenM.stop();
					previousScreen = screen;
					if (loadCampain == true)
					{
						screen = Playing;
						loadCampain = false;
						if (UfinalBoss == true)
							state = finalBoss;
						else if (Univeau3C == true)
							state = niveau3C;
						else if (Univeau3B == true)
							state = niveau3B;
						else if (Univeau3A == true)
							state = niveau3A;
						else if (Univeau2C == true)
							state = niveau2C;
						else if (Univeau2B == true)
							state = niveau2B;
						else if (Univeau2A == true)
							state = niveau2A;
						else if (Univeau1C == true)
							state = niveau1C;
						else if (Univeau1B == true)
							state = niveau1B;
						else
							state = niveau1A;
					}
					else if (loadEdited == true)
					{
						screen = Editor;
						loadEdited = false;
					}
					
				}
				if (event.mouseButton.button == Mouse::Left && hardcoreS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					player.setDifficulty(Hardcore);
					confirmSound.play();
					titleScreenM.stop();
					previousScreen = screen;
					if (loadCampain == true)
					{
						screen = Playing;
						loadCampain = false;
						if (UfinalBoss == true)
							state = finalBoss;
						else if (Univeau3C == true)
							state = niveau3C;
						else if (Univeau3B == true)
							state = niveau3B;
						else if (Univeau3A == true)
							state = niveau3A;
						else if (Univeau2C == true)
							state = niveau2C;
						else if (Univeau2B == true)
							state = niveau2B;
						else if (Univeau2A == true)
							state = niveau2A;
						else if (Univeau1C == true)
							state = niveau1C;
						else if (Univeau1B == true)
							state = niveau1B;
						else
							state = niveau1A;
					}
					else if (loadEdited == true)
					{
						screen = Editor;
						loadEdited = false;
					}
				}
				if (event.mouseButton.button == Mouse::Left && backS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					screen = Menu;
					loadCampain = false;
					loadEdited = false;
				}
			}
		}
		window.draw(SetDifficultyS);
		window.draw(hardcoreS);
		window.draw(easyS);
		window.draw(normalS);
		window.draw(backS);
	}

	if (screen == EreaseData)
	{
		Sprite EreaseDataS;
		Texture EreaseDataT;
		if (!EreaseDataT.loadFromFile("erease-Red.png")) throw runtime_error("Erreur: texture du fond non charg�e");
		EreaseDataS.setTexture(EreaseDataT);
		confirmS.setPosition(1160, 519);
		cancelS.setPosition(360, 519);
		resetS.setPosition(760, 778);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window);

				if (event.mouseButton.button == Mouse::Left && cancelS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					screen = previousScreen;
				}
				if (event.mouseButton.button == Mouse::Left && confirmS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					screen = previousScreen;
					removeData(player, *this);
					state = niveau1A;
					saveData(player, *this);
					openData(player, *this);
				}
				if (event.mouseButton.button == Mouse::Left && resetS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) && hasWon == true)
				{
					confirmSound.play();
					screen = previousScreen;
					resetQuest(player, *this);
					state = niveau1A;
					saveData(player, *this);
					openData(player, *this);
				}
			}
		}
		window.draw(EreaseDataS);
		window.draw(confirmS);
		window.draw(cancelS);
		if(hasWon == true)
		window.draw(resetS);
	}

	if (screen == Menu) {
		setTotalScoreText(player, scoreFont, totalScoreText);
		editorM.stop();
		if (titleScreenM.getStatus() != Sound::Playing)
			titleScreenM.play();
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
		closeS.setPosition(510, 733); closeS.setScale(1.5, 1.5);
		editorS.setPosition(1110, 321); editorS.setScale(1.5, 1.5);
		dataS.setPosition(1110, 733); dataS.setScale(1.5, 1.5);
		questS.setPosition(510, 321); questS.setScale(1.5, 1.5);
		settingsS.setPosition(510, 527); settingsS.setScale(1.5, 1.5);
		shopS.setPosition(1110, 527); shopS.setScale(1.5, 1.5);
		


		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window);

				if (event.mouseButton.button == Mouse::Left && editorS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					state = niveauEDIT;
					previousScreen = screen;
					screen = SetDifficulty;
					loadEdited = true;
					openData(player, *this);
				}
				if (event.mouseButton.button == Mouse::Left && dataS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					previousScreen = screen;
					screen = EreaseData;
					openData(player, *this);
				}
				if (event.mouseButton.button == Mouse::Left && questS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					previousScreen = screen;
					screen = SetDifficulty;
					loadCampain = true; //Load campain veut dire charger Quest (Playing)
					openData(player, *this);
				}
				if (event.mouseButton.button == Mouse::Left && settingsS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					previousScreen = screen;
					screen = Settings;
					openData(player, *this);
				}
				if (event.mouseButton.button == Mouse::Left && shopS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					previousScreen = screen;
					screen = Shop;
					openData(player, *this);
				}
				if (event.mouseButton.button == Mouse::Left && closeS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					window.close();
				}
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Enter || event.key.code == Keyboard::Escape)
					window.close();
			}
		}
		window.draw(backgroundSprite);
		window.draw(title);
		window.draw(closeS);
		//window.draw(confirmS);
		window.draw(editorS);
		//window.draw(cancelS);
		window.draw(dataS);
		//window.draw(easyS);
		//window.draw(hardcoreS);
		//window.draw(menuS);
		//window.draw(normalS);
		window.draw(questS);
		//window.draw(resumeS);
		window.draw(settingsS);
		//window.draw(buyS);
		//window.draw(yesS);
		//window.draw(noS);
		window.draw(shopS);
	}

	if (screen == Win)
	{
		resetS.setPosition(764, 872);
		settingsS.setScale(2, 2);
		settingsS.setPosition(192, 872);
		closeS.setScale(2, 2);
		closeS.setPosition(1328, 872);
		menuS.setScale(2, 2);
		menuS.setPosition(1329, 642);
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
				saveCurrentScore(player);
				saveData(player, *this);
				openData(player, *this);
				window.close();
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Enter)
				{
					saveCurrentScore(player);
					saveData(player, *this);
					openData(player, *this);
					window.close();
				}
			}
			if (event.type == Event::MouseButtonPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window);

				if (event.mouseButton.button == Mouse::Left && resetS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					screen = previousScreen;
					resetQuest(player, *this);
					state = niveau1A;
					saveData(player, *this);
					openData(player, *this);
				}

				if (event.mouseButton.button == Mouse::Left && settingsS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					previousScreen = screen;
					screen = Settings;
				}
				if (event.mouseButton.button == Mouse::Left && closeS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					saveCurrentScore(player);
					saveData(player, *this);
					openData(player, *this);
					window.close();
				}
				if (event.mouseButton.button == Mouse::Left && menuS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					saveCurrentScore(player);
					saveData(player, *this);
					previousScreen = screen;
					victoryM.stop();
					screen = Menu;
				}
			}
		}
		window.draw(winBackground);
		window.draw(settingsS);
		window.draw(closeS);
		window.draw(resetS);
		window.draw(menuS);
	}

	if (screen == Lost)
	{
		menuS.setPosition(192 , 714);
		closeS.setPosition(760 , 714);
		closeS.setScale(2, 2);
		continueS.setPosition(1328, 714);
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
						previousScreen = screen;
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
					{
						previousScreen = screen;
						screen = Playing;
					}
				}
			}
			if (event.type == Event::MouseButtonPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window);

				if (event.mouseButton.button == Mouse::Left && continueS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					switch (state)
					{
					case niveauEDIT:
						isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						previousScreen = screen;
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
					if (state != niveauEDIT)
					{
						previousScreen = screen;
						screen = Playing;
					}
				}

				if (event.mouseButton.button == Mouse::Left && menuS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					switch (state)
					{
					case niveauEDIT:
						isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						previousScreen = screen;
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
					player.HP = player.maxHP;
					lose.stop();
					confirmSound.play();
					previousScreen = screen;
					screen = Menu;
					counter = 1;
					currentID = 0;
				}
				if (event.mouseButton.button == Mouse::Left && closeS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					window.close();
				}
			}
		}
		window.draw(lostScreen);
		window.draw(continueS);
		window.draw(closeS);
		window.draw(menuS);
	}

	if (screen == NextLevel)
	{
		editorM.stop();
		if (player.difficulty != Hardcore)
			player.HP = player.maxHP;
		else
			player.shield = 0;
		continueS.setPosition(764, 872);
		settingsS.setScale(2, 2);
		settingsS.setPosition(192, 872);
		closeS.setScale(2, 2);
		closeS.setPosition(1328 , 872);
		menuS.setScale(2, 2);
		menuS.setPosition(1329, 642);
		
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
		coin.setPosition(750, 670);
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
				saveData(player, *this);
				switch (state)
				{
				case niveauEDIT:
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
						saveData(player, *this);
						openData(player, *this);
						loadLevel = true;
						doLoadBackground = true;
						isFightingBoss = false;
						counter = 1;
						state = niveauEDIT;
						previousScreen = screen;
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
					player.currentScore = 0;
					coin.setPosition(0, 50);
					coin.setScale(0.2, 0.2);
					if(state != niveauEDIT)
					{
						previousScreen = screen;
						screen = Playing;
						nextLevelM.stop();
					}

				}
			}
			if (event.type == Event::MouseButtonPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window);

				if (event.mouseButton.button == Mouse::Left && continueS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					switch (state)
					{
					case niveauEDIT:
						loadLevel = true;
						doLoadBackground = true;
						isFightingBoss = false;
						counter = 1;
						state = niveauEDIT;
						previousScreen = screen;
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
					saveData(player, *this);
					player.currentScore = 0;
					coin.setPosition(0, 50);
					coin.setScale(0.2, 0.2);
					if (state != niveauEDIT)
					{
						previousScreen = screen;
						screen = Playing;
						nextLevelM.stop();
					}

				}

				if (event.mouseButton.button == Mouse::Left && settingsS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					previousScreen = screen;
					screen = Settings;
				}
				if (event.mouseButton.button == Mouse::Left && closeS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					switch (state)
					{
					case niveauEDIT:
						loadLevel = true;
						doLoadBackground = true;
						isFightingBoss = false;
						counter = 1;
						state = niveauEDIT;
						previousScreen = screen;
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
					saveData(player, *this);
					window.close();
				}
				if (event.mouseButton.button == Mouse::Left && menuS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					switch (state)
					{
					case niveauEDIT:
						loadLevel = true;
						doLoadBackground = true;
						isFightingBoss = false;
						counter = 1;
						state = niveauEDIT;
						previousScreen = screen;
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
					saveData(player, *this);
					coin.setPosition(0, 50);
					coin.setScale(0.2, 0.2);
					previousScreen = screen;
					nextLevelM.stop();
					screen = Menu;
				}
			}
		}
		window.draw(nextLevelBackground);
		window.draw(totalScoreText);
		window.draw(coin);
		window.draw(settingsS);
		window.draw(closeS);
		window.draw(continueS);
		window.draw(menuS);
	}

	if (screen == Editor)
	{
		player.shield = 0;
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
		if (!upT.loadFromFile("button/up.png")) throw runtime_error("Impossible de charger le bouton haut");
		if (!downT.loadFromFile("button/down.png")) throw runtime_error("Impossible de charger le bouton bas");
		up.setTexture(upT);
		down.setTexture(downT);
		up.setPosition(500, 400);
		down.setPosition(500, 600);
		Sprite enemySprite;
		Texture enemyTexture;
		enemySprite.setPosition(900, 500);
		settingsS.setScale(1.5, 1.5);
		settingsS.setPosition(1480, 835);
		confirmS.setScale(1.5, 1.5);
		confirmS.setPosition(140, 290);
		backS.setScale(1.5, 1.5);
		backS.setPosition(140, 835);
		cancelS.setScale(1.5, 1.5);
		cancelS.setPosition(140, 480);
		yesS.setPosition(1480, 359);
		yes2S.setPosition(1480, 655);
		if (EloadObstacle == true)
			yesS.setTexture(yesT);
		else
			yesS.setTexture(noT);
		if (EloadPowerups == true)
			yes2S.setTexture(yesT);
		else
			yes2S.setTexture(noT);
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
					else
						impossibleAction.play();
				}
				if (event.mouseButton.button == Mouse::Left && yesS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) || event.key.code == Keyboard::Down)
				{
					confirmSound.play();
					if (EloadObstacle == false)
						EloadObstacle = true;
					else
						EloadObstacle = false;
				}
				if (event.mouseButton.button == Mouse::Left && yes2S.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) || event.key.code == Keyboard::Down)
				{
					confirmSound.play();
					if (EloadPowerups == false)
						EloadPowerups = true;
					else
						EloadPowerups = false;
				}
				if (event.mouseButton.button == Mouse::Left && down.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) || event.key.code == Keyboard::Down)
				{
					
					if (currentID != 0)
					{
						currentID--;
						clickSound.play();
					}
					else
						impossibleAction.play();
				}
				if (event.mouseButton.button == Mouse::Left && backS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) || event.key.code == Keyboard::Down)
				{
					confirmSound.play();
					screen = previousScreen;
					previousScreen = Editor;
					counter = 1;
					currentID = 0;
					
				}
				if (event.mouseButton.button == Mouse::Left && cancelS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) || event.key.code == Keyboard::Down)
				{
					confirmSound.play();
					counter--;
					if (counter < 1)
						counter = 1;
					

				}
				if (event.mouseButton.button == Mouse::Left && settingsS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) || event.key.code == Keyboard::Down)
				{
					confirmSound.play();
					counter--;
					screen = previousScreen;
					screen = Settings;


				}
				if (event.mouseButton.button == Mouse::Left && confirmS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) || event.key.code == Keyboard::Down)
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
						previousScreen = screen;
						screen = Playing;
						editorM.stop();
						break;
					}
					counter++;
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
						previousScreen = screen;
						screen = Playing;
						editorM.stop();
						break;
					}
					counter++;
				}
			}
		}
		window.draw(editorBackground);
		window.draw(confirmS);
		window.draw(settingsS);
		window.draw(backS);
		window.draw(cancelS);
		window.draw(numerotation);
		window.draw(enemySprite);
		window.draw(up);
		window.draw(down);
		window.draw(yesS);
		window.draw(yes2S);
	}

	/////////////////////////////////////////////////////////////////////

	if (screen == Playing)
	{
		coin.setScale(0.2, 0.2);
		coin.setPosition(0, 45);
		if (state != niveauEDIT)
		{
			if(state == niveau1A && Univeau1A == true)
				level1A(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);
			else if(state == niveau1B && Univeau1B == true)
				level1B(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);
			else if (state == niveau1C && Univeau1C == true)
				level1C(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);
			else if (state == niveau2A && Univeau2A == true)
				level2A(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);
			else if (state == niveau2B && Univeau2B == true)
				level2B(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);
			else if (state == niveau2C && Univeau2C == true)
				level2C(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);
			else if (state == niveau3A && Univeau3A == true)
				level3A(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);
			else if (state == niveau3B && Univeau3B == true)
				level3B(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);
			else if (state == niveau3C && Univeau3C == true)
				level3C(player, eManager, oManager, pManager, uManager, exManager, playing, boss, finalBossM, background);
			else if (state == finalBoss && UfinalBoss == true)
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
				previousScreen = screen;
				screen = Lost;
				player.shield = 0;
			}
		}

		window.draw(scoreText);
		window.draw(coin);
		window.draw(currentLevelText);
		window.draw(healthbar.psprite);
		if (player.shield > 0)
			window.draw(healthbar.pShield);

		if(isFightingBoss == true)
		{
			for (int i = 0; i < eManager.getEnemies().size(); i++)
			{
				if (eManager.getEnemies()[i]->id == ENNEMI1 || eManager.getEnemies()[i]->id == ENNEMI2 || eManager.getEnemies()[i]->id == ENNEMI3 || eManager.getEnemies()[i]->id == BOSS1 || eManager.getEnemies()[i]->id == BOSS2 || eManager.getEnemies()[i]->id == BOSS3 || eManager.getEnemies()[i]->id == BOSS4)
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