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
	vector<string> options_start = { "����� ������ ������", "����� ������ ���������� (����������)", "����� ������ ���������� (�����������)" };
	int player_select = getChoice("�������� �����: ", options_start);

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

	vector<string> options_start_move = {
		"������ �����",
		string("������ �����") + string(player_select > 1 ? " (���������)" : "")
	};
	int choice = getChoice("��� ����� ������: ", options_start_move);
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

int Menu::getChoice(string welcome, vector<string> options)
{
	int choice = 1;
	while (true) {
		cout << welcome << endl;
		for (int i = 0; i < options.size(); i++) {
			if (choice == i + 1) cout << ">> ";
			cout << i+1 << ". " << options[i] << endl;
		}
		char ch = _getch();
		if (ch == 80) choice++;
		else if (ch == 72) choice--;
		if (choice > options.size()) choice = 1;
		if (choice < 1) choice = options.size();
		system("cls");
		if (ch == ' ') break;
	}
	return choice;
}

Menu::~Menu() {
	cout << "������ [Menu] �����!" << endl;
	system("cls");
}
