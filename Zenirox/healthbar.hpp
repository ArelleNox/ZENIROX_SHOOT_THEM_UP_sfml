#ifndef HEALTHBAR_HPP
#define HEALTHBAR_HPP
#include <iostream>
#include "player.hpp"
#include "enemy.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class Healthbar
{
public:
	Sprite psprite;
	Sprite pShield;
	Sprite esprite;
	Sprite eShield;
	vector <Texture> PtextureList{ 20 };
	vector <Texture> EtextureList{ 20 };
	void setHealthbar(Player player);
	void setHealthbar(Enemy* enemy);
	int setTextureList();
};



#endif
