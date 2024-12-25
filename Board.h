#ifndef _BOARD
#define _BOARD

#include <vector>

class Board{
private:
	int state[3][3];  // 1 - X , 2 - O
	bool changeable;
	char winner;

	void rearm(){
		winner =  ' ',
		changeable = true,
		state[0][0] = state[0][1] = state[0][1] =
		state[1][0] = state[1][1] = state[1][1] =
		state[2][0] = state[2][1] = state[2][1] = 0;
	}

	void doStep(int x, char c){
		state[x / 3][x % 3] = ((c == '0' || c == 'o' || c == 'O')? 2: 1);
		winner = checkWin();
		if(winner != ' ')
			changeable = false;
	}

	char checkWin() const{
		for(int i = 0; i < 3; ++ i)
			if(state[i][0] == 1 && state[i][1] == 1 && state[i][2] == 1 || state[0][i] == 1 && state[1][i] == 1 && state[2][i] == 1)
				return 'X';
		for(int i = 0; i < 3; ++ i)
			if(state[i][0] == 2 && state[i][1] == 2 && state[i][2] == 2 || state[0][i] == 2 && state[1][i] == 2 && state[2][i] == 2)
				return 'O';

		if(state[0][0] == 1 && state[1][1] == 1 && state[2][2] == 1 || state[0][2] == 1 && state[1][1] == 1 && state[2][0] == 1)
			return 'X';
		if(state[0][0] == 2 && state[1][1] == 2 && state[2][2] == 2 || state[0][2] == 2 && state[1][1] == 2 && state[2][0] == 2)
			return 'O';

		if(theraAreSteps())
			return ' ';

		return '$';
	}

public:
	Board(){
		rearm();
	}

	Board(const Board & board){
		winner = board.winner,
		changeable = board.changeable,
		state[0][0] = board.state[0][0],
		state[0][1] = board.state[0][1],
		state[0][2] = board.state[0][2],

		state[1][0] = board.state[1][0],
		state[1][1] = board.state[1][1],
		state[1][2] = board.state[1][2],

		state[2][0] = board.state[2][0],
		state[2][1] = board.state[2][1],
		state[2][2] = board.state[2][2];
	}

	Board(const Board * board){
		winner = board->winner,
		changeable = board->changeable,
		state[0][0] = board->state[0][0],
		state[0][1] = board->state[0][1],
		state[0][2] = board->state[0][2],

		state[1][0] = board->state[1][0],
		state[1][1] = board->state[1][1],
		state[1][2] = board->state[1][2],

		state[2][0] = board->state[2][0],
		state[2][1] = board->state[2][1],
		state[2][2] = board->state[2][2];
	}

	// x,y - координата
	// i - ход
	bool check(int x) const{
		if(x < 0 || x > 8 || !changeable)
			return false;
		return state[x / 3][x % 3] == 0;
	}

	bool theraAreSteps() const{
		if(!changeable)
			return false;
		for(int i = 0; i < 9; ++ i)
			if(state[i / 3][i % 3] == 0)
				return true;
		return false;
	}

	std::vector<int> getAvailableMoves() const{
		std::vector<int> v;

		for(int i = 0; i < 9; ++ i)
			if(check(i))
				v.push_back(i);

		return v;
	}

	char getWinner() const{
		return winner;
	}

	bool isWinningState(int x, char c) const{
		if(x < 0 || x > 8 || !changeable)
			return false;
		if(state[x / 3][x % 3] != 0)
			return false;
		
		Board board_copy(this);

		if(board_copy.tryToDoStep(x, c)){
			char res = board_copy.getWinner();

			if(res == c)
				return true;
		}
		return false;
	}

	std::vector<char> getBoardVec() const{
		std::vector<char> boardVec;

		for(int i = 0; i < 9; ++ i)
			boardVec.push_back((state[i / 3][i % 3] == 1? 'X': (state[i / 3][i % 3] == 2? 'O': ' ')));
		return boardVec;
	}

	void refreshBoard(){
		rearm();
	}

	bool tryToDoStep(int x, char c){
		if(c != '0' && c != 'o' && c != 'O' && c != 'x' && c != 'X')
			return false;
		if(check(x)){
			doStep(x, c);
			return true;
		}
		else
			return false;
	}
};

#endif
