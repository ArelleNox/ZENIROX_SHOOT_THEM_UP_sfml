#include "healthbar.hpp"


using namespace std;
using namespace sf;



void Healthbar::setHealthbar(Player player)
{
	psprite.setScale(0.4, 0.4);
	psprite.setPosition(0, 0);
	pShield.setScale(0.4, 0.4);
	pShield.setPosition(0, 0);
	
		if (player.HP <= player.maxHP * 0.1)
			psprite.setTexture(PtextureList[0]);

		else if (player.HP <= player.maxHP * 0.2)
			psprite.setTexture(PtextureList[1]);

		else if (player.HP <= player.maxHP * 0.3)
			psprite.setTexture(PtextureList[2]);

		else if (player.HP <= player.maxHP * 0.4)
			psprite.setTexture(PtextureList[3]);

		else if (player.HP <= player.maxHP * 0.5)
			psprite.setTexture(PtextureList[4]);

		else if (player.HP <= player.maxHP * 0.6)
			psprite.setTexture(PtextureList[5]);

		else if (player.HP <= player.maxHP * 0.7)
			psprite.setTexture(PtextureList[6]);

		else if (player.HP <= player.maxHP * 0.8)
			psprite.setTexture(PtextureList[7]);

		else if (player.HP <= player.maxHP * 0.9)
			psprite.setTexture(PtextureList[8]);

		else if (player.HP <= player.maxHP)
			psprite.setTexture(PtextureList[9]);

		if (player.shield <= player.maxShield * 0.1)
			pShield.setTexture(PtextureList[10]);

		else if (player.shield <= player.maxShield * 0.2)
			pShield.setTexture(PtextureList[11]);

		else if (player.shield <= player.maxShield * 0.3)
			pShield.setTexture(PtextureList[12]);

		else if (player.shield <= player.maxShield * 0.4)
			pShield.setTexture(PtextureList[13]);

		else if (player.shield <= player.maxShield * 0.5)
			pShield.setTexture(PtextureList[14]);

		else if (player.shield <= player.maxShield * 0.6)
			pShield.setTexture(PtextureList[15]);

		else if (player.shield <= player.maxShield * 0.7)
			pShield.setTexture(PtextureList[16]);

		else if (player.shield <= player.maxShield * 0.8)
			pShield.setTexture(PtextureList[17]);

		else if (player.shield <= player.maxShield * 0.9)
			pShield.setTexture(PtextureList[18]);

		else if (player.shield <= player.maxShield)
			pShield.setTexture(PtextureList[19]);
	}


void Healthbar::setHealthbar(Enemy* enemy)
{
	esprite.setScale(0.4, 0.4);
	esprite.setPosition(1600, 0);
	eShield.setScale(0.4, 0.4);
	eShield.setPosition(1600, 0);

		if (enemy->HP <= enemy->maxHP * 0.1)
			esprite.setTexture(EtextureList[0]);

		else if (enemy->HP <= enemy->maxHP * 0.2)
			esprite.setTexture(EtextureList[1]);

		else if (enemy->HP <= enemy->maxHP * 0.3)
			esprite.setTexture(EtextureList[2]);

		else if (enemy->HP <= enemy->maxHP * 0.4)
			esprite.setTexture(EtextureList[3]);

		else if (enemy->HP <= enemy->maxHP * 0.5)
			esprite.setTexture(EtextureList[4]);

		else if (enemy->HP <= enemy->maxHP * 0.6)
			esprite.setTexture(EtextureList[5]);

		else if (enemy->HP <= enemy->maxHP * 0.7)
			esprite.setTexture(EtextureList[6]);

		else if (enemy->HP <= enemy->maxHP * 0.8)
			esprite.setTexture(EtextureList[7]);

		else if (enemy->HP <= enemy->maxHP * 0.9)
			esprite.setTexture(EtextureList[8]);

		else if (enemy->HP <= enemy->maxHP)
			esprite.setTexture(EtextureList[9]);
		if (enemy->shield <= enemy->maxShield * 0.1)
			eShield.setTexture(EtextureList[10]);

		else if (enemy->shield <= enemy->maxShield * 0.2)
			eShield.setTexture(EtextureList[11]);

		else if (enemy->shield <= enemy->maxShield * 0.3)
			eShield.setTexture(EtextureList[12]);

		else if (enemy->shield <= enemy->maxShield * 0.4)
			eShield.setTexture(EtextureList[13]);

		else if (enemy->shield <= enemy->maxShield * 0.5)
			eShield.setTexture(EtextureList[14]);

		else if (enemy->shield <= enemy->maxShield * 0.6)
			eShield.setTexture(EtextureList[15]);

		else if (enemy->shield <= enemy->maxShield * 0.7)
			eShield.setTexture(EtextureList[16]);

		else if (enemy->shield <= enemy->maxShield * 0.8)
			eShield.setTexture(EtextureList[17]);

		else if (enemy->shield <= enemy->maxShield * 0.9)
			eShield.setTexture(EtextureList[18]);

		else if (enemy->shield <= enemy->maxShield)
			eShield.setTexture(EtextureList[19]);
	}


int Healthbar::setTextureList()
{
	for(int i = 0; i < PtextureList.size(); i++)
		if (!PtextureList[i].loadFromFile("phealth/" + to_string(i+1) + ".png")) { cout << "Erreur de chargement texture barre de vie " + to_string(i+1) << endl; return -1; }
	for (int i = 0; i < EtextureList.size(); i++)
		if (!EtextureList[i].loadFromFile("ehealth/" + to_string(i + 1) + ".png")) { cout << "Erreur de chargement texture barre de vie " + to_string(i + 1) << endl; return -1; }
}