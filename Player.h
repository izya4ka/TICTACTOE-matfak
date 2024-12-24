#pragma once
class Player
{
protected:
	std::string name;
	int difficulty;
public:
	Player();
	void doMove();
	~Player();
};