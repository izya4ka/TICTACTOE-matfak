#pragma once
#include "Player.h"
#include "Board.h"
#include <string>

class Game
{
private:
	Player firstPlayer;
	Player secondPlayer;
	bool isBot;
	Board board;
public:
	Game(string firstName, char symbol, short difficulty);
	Game(string firstName, char symbol, string secondName);
	void run();

	~Game();
};

