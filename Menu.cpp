#include "Menu.h"
#include <conio.h>
#include <iostream>
#include "game.h"
using namespace std;

Menu::Menu() {}

// DOWN - 80
// UP - 72	
// LEFT - 75
// RIGHT - 77

void Menu::startScreen()
{
	int player_select = 1;
	while (true) {
		cout << "Выберите кто будет играть:" << endl;
		if (player_select == 1) cout << ">> ";cout << "1. Игрок против игрока" << endl;
		if (player_select == 2) cout << ">> ";cout << "2. Игрок против компьютера (начинающий)" << endl;
		if (player_select == 3) cout << ">> ";cout << "3. Игрок против компьютера (продвинутый)" << endl;
		char ch = _getch();
		if (ch == 80) player_select++;
		else if (ch == 72) player_select--;
		if (player_select > 3) player_select = 1;
		if (player_select < 1) player_select = 3;
		system("cls");
		if (ch == ' ') break;
	}
	string first_player;
	string second_player = "Компьютер";
	cout << "Введите имя первого игрока: ";
	cin >> first_player;
	if (player_select == 2) second_player += " (начинающий)";
	if (player_select == 3) second_player += " (продвинутый)";
	if (player_select == 1) {
		cout << "Введите имя второго игрока: ";
		cin >> second_player;
	}
	system("cls");

	int choice = 1;
	while (true) {
		cout << "Выберите кто ходит первым:" << endl;
		if (choice == 1) cout << ">> ";cout << "1. Первый игрок" << endl;
		if (choice == 2) cout << ">> ";cout << "2. Второй игрок" << (player_select > 1 ? " (компьютер)" : "") << endl;
		char ch = _getch();
		if (ch == 80) choice++;
		else if (ch == 72) choice--;
		if (choice > 2) choice = 1;
		if (choice < 1) choice = 2;
		system("cls");
		if (ch == ' ') break;
	}

	char symbol = (choice == 1) ? 'O' : 'X';

	if (player_select > 1) { 
		player_select--;
		Game game(first_player, symbol, player_select);
		game.run();
	}
	else {
		Game game(first_player, symbol, second_player);
		game.run();
	}

}

Menu::~Menu() {
	cout << "Объект [Menu] удалён!" << endl;
	system("cls");
}
