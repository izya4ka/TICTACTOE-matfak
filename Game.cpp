#include "Game.h"
#include <conio.h>

Game::Game(string firstName, char symbol, short difficulty) {
	isBot = true;
	board = Board();
	firstPlayer = Player(firstName, symbol, &board);
	secondPlayer = Player(difficulty, (symbol == 'X') ? 'O' : 'X', &board);
}

Game::Game(string firstName, char symbol, string secondName)
{
	isBot = false;
	board = Board();
	firstPlayer = Player(firstName, symbol, &board);
	secondPlayer = Player(secondName, (symbol == 'X') ? 'O' : 'X', &board);
}

void Game::run()
{
	char current_symbol = 'O';
	Player& current_player = (firstPlayer.getSym() == current_symbol) ? firstPlayer : secondPlayer;
	while (true) {
		if (current_player.isBot()) {
			current_player.doMove(current_player.chooseMove());
			current_player = (firstPlayer.getSym() == current_symbol) ? firstPlayer : secondPlayer;
			current_symbol = (current_symbol == 'O') ? 'X' : 'O';
			continue;
		};
		system("cls");
		cout << "Текущий игрок:";
		printBoard();
		cout << "Введите номер клетки: ";
		int x;
		cin >> x;
		current_player.doMove(x);
		current_symbol = (current_symbol == 'O') ? 'X' : 'O';
		current_player = (firstPlayer.getSym() == current_symbol) ? firstPlayer : secondPlayer;
		system("pause");
	}
}

void Game::printBoard()
{
	cout << "Поле:" << endl;
	vector<char> board_vec = board.getBoardVec();
	for (int i = 0; i < 9; i++) {
		cout << "[ " << board_vec[i] << " ]" << ' ';
		if (!((i + 1) % 3)) cout << endl << endl;
	}
}

Game::~Game()
{
	cout << "Объект [game] удалён!" << endl;
}
