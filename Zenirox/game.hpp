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

class Starparallaxe;
class fastStarparallaxe;

using namespace std;
using namespace sf;
enum Screen{Menu, Start, Settings, Exit, Playing, Editor, NextLevel, Lost, Win, EreaseData};

enum gameState {
	niveauEDIT, niveau1A, niveau1B, niveau1C, niveau2A, niveau2B, niveau2C, niveau3A, niveau3B, niveau3C, finalBoss
};


class Game {
private:
	

	std::vector<sf::Text> menuOptions;    // Text objects for menu options
	int hoveredOption;                    // Index of the hovered option
	sf::Text title;                       

public:
	Game();

	sf::Texture backgroundTexture;
	sf::Texture closeT;
	sf::Texture confirmT;
	sf::Texture editorT;
	sf::Texture cancelT;
	sf::Texture dataT;
	sf::Texture easyT;
	sf::Texture hardcoreT;
	sf::Texture menuT;
	sf::Texture normalT;
	sf::Texture questT;
	sf::Texture resumeT;
	sf::Texture settingsT;
	sf::Texture buyT;
	sf::Texture yesT;
	sf::Texture noT;

	sf::Sprite backgroundSprite;
	sf::Sprite closeS;
	sf::Sprite confirmS;
	sf::Sprite editorS;
	sf::Sprite cancelS;
	sf::Sprite dataS;
	sf::Sprite easyS;
	sf::Sprite hardcoreS;
	sf::Sprite menuS;
	sf::Sprite normalS;
	sf::Sprite questS;
	sf::Sprite resumeS;
	sf::Sprite settingsS;
	sf::Sprite buyS;
	sf::Sprite yesS;
	sf::Sprite noS;

	sf::Font font;

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
	Screen screen = Playing;
	Screen previousScreen;
	ID* alias = &nb1;
	Clock gameClock;
	Time gameDuration;
	ID  nb1, nb2, nb3, nb4, nb5, nb6, nb7, nb8, nb9, nb10, bossID = ENNEMI1;
	Text currentLevelText;
	Font currentLevelFont;

	bool doLoadBackground = true;
	bool Univeau1A, loadLevel = true;
	bool Univeau2A, Univeau3A, Univeau1B, Univeau2B, Univeau3B, Univeau1C, Univeau2C, Univeau3C, UfinalBoss, isFightingBoss = false;
	int toKill = 0;
	int counter = 1;
	int currentID = 0;


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
