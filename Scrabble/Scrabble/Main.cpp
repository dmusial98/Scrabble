#include "Game.h"
#pragma warning(disable:4996)

int main() {

	setlocale(LC_ALL, "polish");

	std::cout << "Za��� g�l� ja��\n\n";

	Game game;
	game.control();

	return 0;
}