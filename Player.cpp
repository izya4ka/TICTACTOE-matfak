
#include "Player.h"
using namespace std;

Player::Player()
{
}

Player::Player(string name, char symbol, Board* _board) : playerSymbol(symbol), opponentSymbol(symbol == 'X' ? 'O' : 'X'), board(_board), level(0) {}

Player::Player(short difficulty, char symbol, Board* _board) : level(difficulty), playerSymbol(symbol), opponentSymbol(symbol == 'X' ? 'O' : 'X'), board(_board) {
    srand(static_cast<unsigned>(time(nullptr)));
}

Player::~Player() {
    cout << "Объект игрока " << "[" << name << "]" << " уничтожен!" << endl;
}

char Player::getSym()
{
    return playerSymbol;
}

bool Player::isBot()
{
    return (level != 0) ? true : false;
}

void Player::doMove(int move)
{
    board->tryToDoStep(move, playerSymbol);
}

int Player::chooseMove() {
    vector<int> availableMoves = board->getAvailableMoves();
    if (availableMoves.empty()) {
        return -1;
    }

    switch (level) {
    case 1:
        return chooseRandomMove();
    case 2:
        return chooseOptimalMove();
    default:
        throw logic_error("Неверный уровень сложности!");
    }
}

int Player::chooseRandomMove() {
    const vector<int>& availableMoves = board->getAvailableMoves();
    int randomIndex = rand() % availableMoves.size();
    return availableMoves[randomIndex];
}

int Player::chooseOptimalMove() {
    int bestScore = numeric_limits<int>::min();
    int bestMove = -1;

    for (int move : board->getAvailableMoves()) {
        Board boardCopy(board);
        boardCopy.tryToDoStep(move, playerSymbol);
        int score = minimax(boardCopy, false);
        if (score > bestScore) {
            bestScore = score;
            bestMove = move;
        }
    }

    return bestMove;
}

int Player::minimax(Board _board, bool isMaximizing) {
    if (_board.getWinner() == playerSymbol) return 10;
    if (_board.getWinner() == opponentSymbol) return -10;
    if (!_board.getAvailableMoves().empty()) return 0;

    if (isMaximizing) {
        int bestScore = numeric_limits<int>::min();
        for (int move : _board.getAvailableMoves()) {
            _board.tryToDoStep(move, playerSymbol);
            int score = minimax(board, false);
            _board.tryToDoStep(move, ' ');
            bestScore = max(bestScore, score);
        }
        return bestScore;
    }
    else {
        int bestScore = numeric_limits<int>::max();
        for (int move : _board.getAvailableMoves()) {
            _board.tryToDoStep(move, opponentSymbol);
            int score = minimax(board, true);
            _board.tryToDoStep(move, ' ');
            bestScore = min(bestScore, score);
        }
        return bestScore;
    }
}