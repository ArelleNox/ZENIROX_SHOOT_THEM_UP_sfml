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
enum screen{Menu, Start, Settings, Exit, Playing, Editor, NextLevel};

enum gameState {
	titleScreen, paused, gameOver, shop, deleteData, niveauEDIT, niveau1A, niveau1B, niveau1C, niveau2A, niveau2B, niveau2C, niveau3A, niveau3B, niveau3C, finalBoss
};


class Game {
private:
	sf::Texture backgroundTexture;        
	sf::Sprite backgroundSprite;          
	std::vector<sf::Text> menuOptions;    // Text objects for menu options
	int hoveredOption;                    // Index of the hovered option
	sf::Text title;                       

public:
	Game();
	sf::Font font;
	gameState state = niveau1A;
	screen screen = Playing;
	bool doLoadBackground = true;
	bool Univeau1A, loadLevel = true;
	bool Univeau2A, Univeau3A, Univeau1B, Univeau2B, Univeau3B, Univeau1C, Univeau2C, Univeau3C, UfinalBoss, isFightingBoss = false;
	int toKill = 0;
	int counter = 1;
	int currentID = 0;
	ID* alias = &nb1;
	Clock gameClock;
	Time gameDuration;
	Music lose;
	Music finalhours;
	ID  nb1, nb2, nb3, nb4, nb5, nb6, nb7, nb8, nb9, nb10, bossID = ENNEMI1;


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
	void level4(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background);
	void levelP(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background);
	void run(RenderWindow& window, Player& player, Sprite& coin, Background& background, Starparallaxe& star, fastStarparallaxe& faststar, Healthbar& healthbar, EnemyManager& eManager, ProjectileManager& pManager, ObstacleManager& oManager, UtilitaryManager& uManager, ExplosionManager& exManager, Clock& clock, Text& scoreText, Font& scoreFont, RectangleShape& interface, Music& playing, Music& boss, Music& finalBossM, vector<Sound>& playerShot, SoundBuffer& shot, Text& totalScoreText);
};

#endif
