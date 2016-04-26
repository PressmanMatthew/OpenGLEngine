#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

bool Game::Run()
{
	if (!engine.Init()) return false;
	if (!engine.GameLoop()) return false;

	return true;
}
