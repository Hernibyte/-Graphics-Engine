#include"gamebase.h"

int main(void) {
	gamebase* game;
	game = new gamebase();

	game->startEngine();

	delete game;
}