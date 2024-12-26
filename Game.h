#pragma once
#include "Player.h"
#include "Board.h"
#include <string>

class Game
{
private:
	Player firstPlayer;
	Player secondPlayer;
	bool isBot; // Поле определяющее, ведётся ли игра с компьюетером
	Board board;
public:
	Game(string firstName, char symbol, short difficulty); // Конструктор для игры с компьютером
	Game(string firstName, char symbol, string secondName); // Конструктор для игры с игроком

	void run(); // Метод запуска игры 
	void printBoard(); // Метод вывода поля

	~Game();
};

