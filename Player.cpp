
#include "Player.h"
using namespace std;

ComputerPlayer::ComputerPlayer() : level(1), playerSymbol('X'), opponentSymbol('O') {
    srand(static_cast<unsigned>(time(nullptr)));
}

ComputerPlayer::ComputerPlayer(short difficulty, char symbol) : level(difficulty), playerSymbol(symbol), opponentSymbol(symbol == 'X' ? 'O' : 'X') {
    srand(static_cast<unsigned>(time(nullptr)));
}

ComputerPlayer::~ComputerPlayer() {
    cout << "ComputerPlayer object destroyed." << endl;
}

int ComputerPlayer::chooseMove(const vector<char>& board) {
    vector<int> availableMoves = getAvailableMoves(board);
    if (availableMoves.empty()) {
        throw runtime_error("No available moves.");
    }

    switch (level) {
    case 1:
        return chooseRandomMove(availableMoves);
    case 2:
        return chooseOptimalMove(board, availableMoves);
    default:
        throw logic_error("Invalid difficulty level.");
    }
}

vector<int> ComputerPlayer::getAvailableMoves(const vector<char>& board) {
    vector<int> moves;
    for (size_t i = 0; i < board.size(); ++i) {
        if (board[i] == ' ') {
            moves.push_back(i);
        }
    }
    return moves;
}

int ComputerPlayer::chooseRandomMove(const vector<int>& availableMoves) {
    int randomIndex = rand() % availableMoves.size();
    return availableMoves[randomIndex];
}

int ComputerPlayer::chooseOptimalMove(const vector<char>& board, const vector<int>& availableMoves) {
    int bestScore = numeric_limits<int>::min();
    int bestMove = -1;

    for (int move : availableMoves) {
        vector<char> boardCopy = board;
        boardCopy[move] = playerSymbol;
        int score = minimax(boardCopy, false);
        if (score > bestScore) {
            bestScore = score;
            bestMove = move;
        }
    }

    return bestMove;
}

int ComputerPlayer::minimax(vector<char> board, bool isMaximizing) {
    if (isWinningState(board, playerSymbol)) return 10;
    if (isWinningState(board, opponentSymbol)) return -10;
    if (getAvailableMoves(board).empty()) return 0;

    if (isMaximizing) {
        int bestScore = numeric_limits<int>::min();
        for (int move : getAvailableMoves(board)) {
            board[move] = playerSymbol;
            int score = minimax(board, false);
            board[move] = ' ';
            bestScore = max(bestScore, score);
        }
        return bestScore;
    }
    else {
        int bestScore = numeric_limits<int>::max();
        for (int move : getAvailableMoves(board)) {
            board[move] = opponentSymbol;
            int score = minimax(board, true);
            board[move] = ' ';
            bestScore = min(bestScore, score);
        }
        return bestScore;
    }
}

bool ComputerPlayer::isWinningState(const vector<char>& board, char symbol) {
    return (board[0] == symbol && board[1] == symbol && board[2] == symbol) ||
        (board[3] == symbol && board[4] == symbol && board[5] == symbol) ||
        (board[6] == symbol && board[7] == symbol && board[8] == symbol) ||
        (board[0] == symbol && board[3] == symbol && board[6] == symbol) ||
        (board[1] == symbol && board[4] == symbol && board[7] == symbol) ||
        (board[2] == symbol && board[5] == symbol && board[8] == symbol) ||
        (board[0] == symbol && board[4] == symbol && board[8] == symbol) ||
        (board[2] == symbol && board[4] == symbol && board[6] == symbol);
}