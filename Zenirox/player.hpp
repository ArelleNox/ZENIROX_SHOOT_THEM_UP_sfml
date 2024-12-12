#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
#include "globalvar.hpp"
using namespace sf;



class Player
{
public:
	int HP = 1000;
	int maxHP = 1000;
	int shield = 0;
	int maxShield = 50;
	int score = 0;
	int attack = 10;
	float up = -5;
	float down = 5;
	Sprite sprite;
	Texture texture;
	Clock attackClock;
	Time attackCooldown;
	ID id = PLAYER;
	int setSprite();
	Player();
	void checkOutOfScreen();
	void increaseScore(int toIncrease);
	void decreaseScore(Text &scoreText, int toDecrease);
};


#endif 
