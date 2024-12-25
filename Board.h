#pragma once
#include <vector>

class Board{
private:
	int state[3][3];  // 1 - X , 2 - O
	bool changeable;
	char winner;

	void rearm();
	void doStep(int x, char c);
	char checkWin() const;
public:
	Board();
	Board(const Board& board);
	Board(const Board* board);

	bool check(int x) const;

	std::vector<int> getAvailableMoves() const;
	bool theraAreSteps() const;
	bool tryToDoStep(int x, char c);


	char getWinner() const;
	bool isWinningState(int x, char c) const;

	std::vector<char> getBoardVec() const;

	void refreshBoard();
};
