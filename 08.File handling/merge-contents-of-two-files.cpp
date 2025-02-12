// Wap to merge two files
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream ifone("./new.cpp");
  ifstream iftwo("./basics.cpp");
  ofstream fout("./merged-text.txt");

  if (!ifone) {
    cout << "Error opening new.cpp!" << endl;
    return 1;
  }
  if (!iftwo) {
    cout << "Error opening basics.cpp!" << endl;
    return 1;
  }

  if (!fout) {
    cout << "Error opening merged-text.txt!" << endl;
    return 1;
  }

  string s;

  while (getline(ifone, s)) {
    fout << s << "\n";
  }

  while (getline(iftwo, s)) {
    fout << s << "\n";
  }

  ifone.close();
  iftwo.close();
  fout.close();

  cout << "Files merged successfully into merged-text.txt" << endl;
  return 0;
}
