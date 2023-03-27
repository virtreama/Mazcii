#include "pch.h"

int main()
{
	Game& game = Game::Get();

	game.Start();

	while (game.IsRunning())
		game.Run();

	return 0;
}