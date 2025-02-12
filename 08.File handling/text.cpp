#include <fstream>
#include <iostream>
using namespace std;
int main() {
  ifstream fin;
  fin.open("./text.txt");

  int s;

  while (!fin.eof()) {
    fin >> s;
    cout << s << "\n";
  }

  fin.close();
}