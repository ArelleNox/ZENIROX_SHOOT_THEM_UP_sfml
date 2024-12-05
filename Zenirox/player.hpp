#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
#include "globalvar.hpp"
using namespace sf;



class Player
{
public:
	int HP = 100;
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
	bool checkOutOfScreen();
};


#endif 
