#pragma once
#include "Player.h"
#include "Board.h"
#include <string>

class Game
{
private:
	Player firstPlayer;
	Player secondPlayer;
	Board board;
public:
	Game(bool playWithBot);



	~Game();
};

