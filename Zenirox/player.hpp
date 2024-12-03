#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
using namespace sf;
class Player
{
public:
	int HP = 100;
	float up = -5;
	float down = 5;
	Sprite sprite;
	Texture texture;
	int setSprite();
};


#endif 
