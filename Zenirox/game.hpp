#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Audio.hpp>
#include <ctime>
#include <stdexcept>
#include <string>
#include "projectile.hpp"
#include "background.hpp"
#include "parallaxe.hpp"
#include "parallaxe2.hpp"
#include "score.hpp"
#include "healthbar.hpp"
#include "obstacle.hpp"
#include "powerups.hpp"

using namespace std;
using namespace sf;

class Starparallaxe;
class fastStarparallaxe;

enum Screen{Menu, Settings, Playing, Editor, NextLevel, Lost, Win, EreaseData, SetDifficulty, Shop, Paused};
enum gameState {
	niveauEDIT, niveau1A, niveau1B, niveau1C, niveau2A, niveau2B, niveau2C, niveau3A, niveau3B, niveau3C, finalBoss
};


class Game {
private:
	

	std::vector<Text> menuOptions;    // Text objects for menu options
	int hoveredOption;                    // Index of the hovered option
	Text title;                       

public:
	Game();

	Texture backgroundTexture;
	Texture closeT;
	Texture confirmT;
	Texture editorT;
	Texture cancelT;
	Texture dataT;
	Texture easyT;
	Texture hardcoreT;
	Texture menuT;
	Texture normalT;
	Texture questT;
	Texture resumeT;
	Texture settingsT;
	Texture buyT;
	Texture yesT;
	Texture noT;
	Texture backT;
	Texture shopT;
	Texture continueT;
	Texture resetT;
	Texture buyShip1T;
	Texture buyShip2T;
	Texture buyShip3T;
	Texture inventoryShipT;
	Texture inventoryShip1T;
	Texture inventoryShip2T;
	Texture inventoryShip3T;
	Texture pauseT;


	Sprite backgroundSprite;
	Sprite closeS;
	Sprite confirmS;
	Sprite editorS;
	Sprite cancelS;
	Sprite dataS;
	Sprite easyS;
	Sprite hardcoreS;
	Sprite menuS;
	Sprite normalS;
	Sprite questS;
	Sprite resumeS;
	Sprite settingsS;
	Sprite buyS;
	Sprite yesS;
	Sprite yes2S;
	Sprite noS;
	Sprite no2S;
	Sprite backS;
	Sprite shopS;
	Sprite continueS;
	Sprite resetS;
	Sprite buyShip1S;
	Sprite buyShip2S;
	Sprite buyShip3S;
	Sprite inventoryShipS;
	Sprite inventoryShip1S;
	Sprite inventoryShip2S;
	Sprite inventoryShip3S;
	Sprite pauseS;

	Font font;

	Music nextLevelM;
	Music victoryM;
	Music editorM;
	Music titleScreenM;
	Music lose;
	Music finalhours;

	Sound confirmSound;
	Sound clickSound;
	Sound impossibleAction;

	SoundBuffer confirmSoundBuffer;
	SoundBuffer clickSoundBuffer;
	SoundBuffer impossibleActionSoundBuffer;

	gameState state = niveau1A;
	Screen screen = Menu;
	Screen previousScreen;
	ID* alias = &nb1;
	Clock gameClock;
	Clock settingsClock;
	Time settingsCooldown = seconds(0.05);
	Time gameDuration;
	ID  nb1, nb2, nb3, nb4, nb5, nb6, nb7, nb8, nb9, nb10, bossID = ENNEMI1;
	Text currentLevelText;
	Font currentLevelFont;

	bool doLoadBackground = true;
	bool Univeau1A, loadLevel = true;
	bool loadCampain, loadEdited, hasWon = false;
	bool Univeau2A = false, Univeau3A = false, Univeau1B = false, Univeau2B = false, Univeau3B = false, Univeau1C = false, Univeau2C = false, Univeau3C = false, UfinalBoss = false, isFightingBoss = false;
	int toKill = 0;
	int counter = 1;
	int currentID = 0;
	bool EloadObstacle, EloadPowerups = false;


	void setGameDuration(float duration);
	void level1A(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background);
	void level1B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background);
	void level1C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background);
	void level2A(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background);
	void level2B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background);
	void level2C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background);
	void level3A(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background);
	void level3B(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background);
	void level3C(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background);
	void level4(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background, Starparallaxe& star, fastStarparallaxe& faststar);
	void levelP(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background);
	void run(RenderWindow& window, Player& player, Sprite& coin, Background& background, Starparallaxe& star, fastStarparallaxe& faststar, Healthbar& healthbar, EnemyManager& eManager, ProjectileManager& pManager, ObstacleManager& oManager, UtilitaryManager& uManager, ExplosionManager& exManager, Clock& clock, Text& scoreText, Font& scoreFont, RectangleShape& interface, Music& playing, Music& boss, Music& finalBossM, vector<Sound>& playerShot, SoundBuffer& shot, Text& totalScoreText);
};

#endif
