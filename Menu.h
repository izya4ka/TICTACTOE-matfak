#pragma once
#include <string>
#include <vector>
using namespace std;

class Menu {
public:
	Menu();

	void startScreen(); // Главный метод меню
	int getChoice(string welcome, vector<string> options); // Метод опрашивания пользователя

	~Menu();
};