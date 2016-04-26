#include "Game.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <FreeImage.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>

using std::vector;


int main()
{
	Game game = Game();

	if (!game.Run()) return false;

	return 0;
}