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
    // ����������� �� ���������
    ComputerPlayer();

    // ����������� � �������������� ������ ���������
    ComputerPlayer(short difficulty, char symbol);

    // ����������
    ~ComputerPlayer();

    // ����� ��� ������ ����
    int chooseMove(const vector<char>& board);

private:
    // ��������� ������ ��������� �����
    vector<int> getAvailableMoves(const vector<char>& board);

    // ����� ���������� ���� (��� ����������� ������)
    int chooseRandomMove(const vector<int>& availableMoves);

    // ����� ������������ ���� (��� ������������ ������)
    int chooseOptimalMove(const vector<char>& board, const std::vector<int>& availableMoves);

    // �������� ��������
    int minimax(vector<char> board, bool isMaximizing);

    // ��������, �������� �� ������� ��������� ����������
    bool isWinningState(const vector<char>& board, char symbol);
};