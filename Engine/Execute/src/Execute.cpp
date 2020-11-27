#include "Game.h"

int main()
{
	Game* game = new Game();

	game->initialize();
	game->update();
	game->terminate();
	
	delete game;
}