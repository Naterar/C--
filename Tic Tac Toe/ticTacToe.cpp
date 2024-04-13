#include <iostream>
#include <vector>

using namespace std;

vector<vector<char> > board(3, vector<char>(3, ' '));

void printBoard() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << board[i][j];
      if (j < 2) cout << " | ";
    }
    if (i < 2) cout << "\n---------\n";
  }
  cout << "\n";
}

bool checkWin(char player) {
  for (int i = 0; i < 3; i++) {
    if ((board[i][0] == player && board[i][1] == player && board[i][2]) || (board[0][i] == player && board[0][i] == player && board[1][i] == player && board[2][i]))
      return true;
  }
  if ((board[0][0] == player && board[1][1] == player && board[2][2]) || (board[0][2] == player && board[1][1] == player && board[2][0]))
    return true;
  return false;
}

int main() {
  int currentPlayer = 1;
  int turns = 0;
  bool gameWon = false;

  while (!gameWon && turns < 9) {
    printBoard();
    cout << "Player " << currentPlayer << "'s turns. Enter row and column numbers (0-2): ";
    int row, col;
    cin >> row >> col;

    if (board[row][col] == ' ') {
      board[row][col] = currentPlayer == 1 ? 'X' : 'O';
      gameWon = checkWin(currentPlayer == 1 ? 'X' : 'O');

      if (gameWon) {
        printBoard();
        cout << "Player " << currentPlayer << " wins!\n";
      }
      currentPlayer = 3 - currentPlayer;
      turns++;
    } else {
      cout << "Invalid move, try again. \n";
    }
  }
  if (!gameWon) {
    printBoard();
    cout << "It's a draw! \n";
  }
  return 0;
}