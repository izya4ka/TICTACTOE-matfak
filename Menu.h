#pragma once
#include <string>
#include <vector>
using namespace std;

class Menu {
public:
	Menu();

	void startScreen(); // ������� ����� ����
	int getChoice(string welcome, vector<string> options); // ����� ����������� ������������

	~Menu();
};