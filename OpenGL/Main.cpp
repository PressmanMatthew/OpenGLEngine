#include "Game.h"

int main()
{
	Game game = Game();

	if (!game.Run()) return false;

	return 0;
}