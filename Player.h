#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

class ComputerPlayer {
private:
    short level;
    char playerSymbol;
    char opponentSymbol;

public:
    // Конструктор по умолчанию
    ComputerPlayer();

    // Конструктор с инициализацией уровня сложности
    ComputerPlayer(short difficulty, char symbol);

    // Деструктор
    ~ComputerPlayer();

    // Метод для выбора хода
    int chooseMove(const vector<char>& board);

private:
    // Получение списка доступных ходов
    vector<int> getAvailableMoves(const vector<char>& board);

    // Выбор случайного хода (для начинающего игрока)
    int chooseRandomMove(const vector<int>& availableMoves);

    // Выбор оптимального хода (для продвинутого игрока)
    int chooseOptimalMove(const vector<char>& board, const std::vector<int>& availableMoves);

    // Алгоритм Минимакс
    int minimax(vector<char> board, bool isMaximizing);

    // Проверка, является ли текущее состояние выигрышным
    bool isWinningState(const vector<char>& board, char symbol);
};