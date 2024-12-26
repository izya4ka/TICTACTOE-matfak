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
		cout << "�������� ��� ����� ������:" << endl;
		if (player_select == 1) cout << ">> ";cout << "1. ����� ������ ������" << endl;
		if (player_select == 2) cout << ">> ";cout << "2. ����� ������ ���������� (����������)" << endl;
		if (player_select == 3) cout << ">> ";cout << "3. ����� ������ ���������� (�����������)" << endl;
		char ch = _getch();
		if (ch == 80) player_select++;
		else if (ch == 72) player_select--;
		if (player_select > 3) player_select = 1;
		if (player_select < 1) player_select = 3;
		system("cls");
		if (ch == ' ') break;
	}
	string first_player;
	string second_player = "���������";
	cout << "������� ��� ������� ������: ";
	cin >> first_player;
	if (player_select == 2) second_player += " (����������)";
	if (player_select == 3) second_player += " (�����������)";
	if (player_select == 1) {
		cout << "������� ��� ������� ������: ";
		cin >> second_player;
	}
	system("cls");

	int choice = 1;
	while (true) {
		cout << "�������� ��� ����� ������:" << endl;
		if (choice == 1) cout << ">> ";cout << "1. ������ �����" << endl;
		if (choice == 2) cout << ">> ";cout << "2. ������ �����" << (player_select > 1 ? " (���������)" : "") << endl;
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
	cout << "������ [Menu] �����!" << endl;
	system("cls");
}
