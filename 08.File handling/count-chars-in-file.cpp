// Wap to count the number of chars in a file
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream fin("student-record.txt");

  if (!fin) {
    cout << "Error opening file!" << endl;
    return 1;
  }

  int numberOfChar = 0;
  char ch;
  string s;

  // This loop counts only non-whitespace characters (letters, digits, symbols),
  // since the `>>` operator skips spaces, newlines, and tabs.
  // while (fin >> ch) {
  //     numberOfChar++;
  // }

  // This loop counts the number of words instead of characters.
  // `>>` extracts words separated by spaces or newlines.
  // while (fin >> s) {
  //     cout << s << "\n";
  //     numberOfChar++;
  // }

  // This loop reads and prints every single character, including spaces and
  // newlines. It accurately counts the total number of characters in the file.
  while (fin.get(ch)) {
    cout << ch;
    numberOfChar++;
  }

  fin.close();
  cout << "\nNumber of Characters: " << numberOfChar << endl;
  return 0;
}
