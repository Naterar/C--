#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> board(3, vector<char>(3, ' '));

void printBoard(const vector<vector<char>>& board) {
  cout << " 0 1 2\n";
  for (int i = 0; i < 3; ++i) {
    cout << i << ' ';
    for (int j = 0; j < 3; ++j) {
      cout << board[i][j]<< ' ';
    }
    cout << '\n';
  }
}
bool checkWin(const vector<vector<char>>& board, char player) {
  for (int i = 0; i < 3; ++i) {
    if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || (board[0][i] == player && board[1][i] == player && board[2][i] == player))
      return true;
  }
  if ((board[0][0] == player && board[1][1] == player && board [2][2] == player) || (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    return true;
  
  return false;
}

bool checkDraw(const vector<vector<char>>& board) {
  for (const auto& row : board) {
    for (char cell : row) {
      if (cell == ' ') return false;
    }
  }
  return true;
}