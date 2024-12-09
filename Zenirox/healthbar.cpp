#include "healthbar.hpp"


using namespace std;
using namespace sf;



void Healthbar::setHealthbar(Player player)
{
	sprite.setScale(0.4, 0.4);
	sprite.setPosition(1600, 0);
	
	if (player.HP <= 10)
		sprite.setTexture(textureList[0]);

	else if (player.HP <= 20)
		sprite.setTexture(textureList[1]);

	else if (player.HP <= 30)
		sprite.setTexture(textureList[2]);

	else if (player.HP <= 40)
		sprite.setTexture(textureList[3]);

	else if (player.HP <= 50)
		sprite.setTexture(textureList[4]);

	else if (player.HP <= 60)
		sprite.setTexture(textureList[5]);

	else if (player.HP <= 70)
		sprite.setTexture(textureList[6]);

	else if (player.HP <= 80)
		sprite.setTexture(textureList[7]);

	else if (player.HP <= 90)
		sprite.setTexture(textureList[8]);

	else if (player.HP <= 100)
		sprite.setTexture(textureList[9]);

}
int Healthbar::setTextureList()
{
	for(int i = 0; i < textureList.size(); i++)
		if (!textureList[i].loadFromFile("health/" + to_string(i+1) + ".png")) { cout << "Erreur de chargement texture barre de vie " + to_string(i+1) << endl; return -1; }
	return 0;
}