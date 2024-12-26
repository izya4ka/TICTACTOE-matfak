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

    // ����������� ��� ������
    Player(string name, char symbol, Board* _board);

    // ����������� ��� ������-����������
    Player(short difficulty, char symbol, Board* _board);

    // ����������
    ~Player();

    char getSym();
    bool isBot();

    // ����� ��� ���������� ���� ��������� �������
    void doMove(int move);

    // ����� ��� ������ ����
    int chooseMove();

private:

    // ����� ���������� ���� (��� ����������� ������)
    int chooseRandomMove();

    // ����� ������������ ���� (��� ������������ ������)
    int chooseOptimalMove();

    // �������� ��������
    int minimax(Board _board, bool isMaximizing);
};