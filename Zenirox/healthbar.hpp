#ifndef HEALTHBAR_HPP
#define HEALTHBAR_HPP
#include <iostream>
#include "player.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class Healthbar
{
public:
	Sprite sprite;
	Texture texture;
	vector <Texture> textureList{ 10 };
	void setHealthbar(Player player);
	int setTextureList();
};



#endif
