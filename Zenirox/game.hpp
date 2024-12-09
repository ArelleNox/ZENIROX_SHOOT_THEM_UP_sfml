#ifndef GAME_HPP
#define GAME_HPP

enum gameState {
	titleScreen, paused, gameOver, shop, deleteData, editor, niveau1A, niveau1B, niveau1C, niveau2A, niveau2B, niveau2C, niveau3A, niveau3B, niveau3C, finalBoss
};

class Game {
public:
	gameState state = titleScreen;
	bool niveau1A, niveau2A, niveau3A, niveau1B, niveau2B, niveau3B, niveau1C, niveau2C, niveau3C, finalBoss = false;
};

#endif
