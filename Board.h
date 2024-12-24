#pragma once
class Board
{
private:

	int state[3][3] = { { 0, 0, 0 }, // 1 - X , 2 - O
					   { 0, 0, 0 },
					   { 0, 0, 0 } };
public:
	Board();

	// x,y - координата
	// i - ход
	bool check(int x, int y, int i);
	void refreshBoard();
	int checkWin();

	~Board();
}

