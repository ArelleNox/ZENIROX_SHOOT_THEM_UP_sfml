#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "globalvar.hpp"
using namespace sf;

enum Difficulty { Easy, Normal, Hardcore };
enum Ship {Default, Red, Green, Turquoise, Rose, Orange, Jaune};

class Player
{
public:
	int HP = 1000;
	int maxHP = 1000;
	int shield = 0;
	int maxShield = 500;
	int currentScore = 0;
	int totalScore = 0;
	int attack = 100;
	float up = -5;
	float down = 5;
	Ship color = Default;
	Difficulty difficulty = Easy;
	Sprite sprite;
	Texture texture;
	Sound impact;
	SoundBuffer impactB;
	Sound bonus;
	Sound malus;
	SoundBuffer bonusB;
	SoundBuffer malusB;
	Clock attackClock;
	Clock boostClock;
	Time boostDuration;
	Time attackCooldown;
	ID id = PLAYER;
	bool canBeBoosted = false;
	bool isAlive = true;
	int setSprite();
	Player();
	void checkOutOfScreen();
	void increaseScore(int toIncrease);
	void decreaseScore(Text &scoreText, int toDecrease);
};


#endif 
