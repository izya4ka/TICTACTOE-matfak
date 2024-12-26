#include "Game.h"

Game::Game(string firstName, char symbol, short difficulty) {
	board = Board();
	firstPlayer = Player(firstName, symbol, &board);
	secondPlayer = Player(difficulty, (symbol == 'X') ? 'O' : 'X', &board);
}

Game::Game(string firstName, char symbol, string secondName)
{
	board = Board();
	firstPlayer = Player(firstName, symbol, &board);
	secondPlayer = Player(secondName, (symbol == 'X') ? 'O' : 'X', &board);
}

void Game::run()
{
	
}

Game::~Game()
{
	cout << "Объект [game] удалён!" << endl;
}
