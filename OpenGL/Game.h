#pragma once
#include "Engine.h"

class Game
{
public:
	Game();
	~Game();

	bool Run();

private:
	Engine engine = Engine();
};

