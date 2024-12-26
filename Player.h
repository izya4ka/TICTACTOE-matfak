#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "board.h"

using namespace std;

class Player {
private:
    string name;
    Board* board;

    short level;
    char playerSymbol;
    char opponentSymbol;

public:
    Player();

    // Конструктор для игрока
    Player(string name, char symbol, Board* _board);

    // Конструктор для игрока-компьютера
    Player(short difficulty, char symbol, Board* _board);

    // Деструктор
    ~Player();

    char getSym();
    bool isBot();

    // Метод для совершения хода настоящим игроком
    void doMove(int move);

    // Метод для выбора хода
    int chooseMove();

private:

    // Выбор случайного хода (для начинающего игрока)
    int chooseRandomMove();

    // Выбор оптимального хода (для продвинутого игрока)
    int chooseOptimalMove();

    // Алгоритм Минимакс
    int minimax(Board _board, bool isMaximizing);
};