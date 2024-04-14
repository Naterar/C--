#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

string chooseWord(const string& fileName) {
  vector<string> words;
  ifstream file(fileName);
  string word;

  while (file >>  word) {
    words.push_back(word);
  }
  file.close();

  srand(time(nullptr));
  if (!words.empty()) {
    return words[rand() % words.size()];
  }
  return "";
}

void printGameState(const string& guessedWord, int triesLeft) {
  cout << "Current word: " << guessedWord << endl;
  cout << "Tries left: " << triesLeft << endl;
}

int main() {
  string secretWord = chooseWord("words.txt");
  string guessedWord(secretWord.length(), '_');
  int tries = 6;
  vector<char> incorrectGuesses;

  while (tries > 0 && guessedWord != secretWord) {
    printGameState(guessedWord, tries);
    char guess;
    cout << "Enter you guess: ";
    cin >> guess;

    if (secretWord.find(guess) != string::npos) {
      for (size_t i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] == guess) {
          guessedWord[i] = guess;
        }
      }
    } else {
      tries--;
      incorrectGuesses.push_back(guess);
    }
  }
  if (guessedWord == secretWord) {
    cout << "Congratulations! You've guessed the word: " << secretWord << endl;
  } else {
    cout << "Out of tries! The correct word was: " << secretWord << endl;
  }
  return 0;
}
