#include <fstream>
#include <iostream>
using namespace std;
int main() {
  ofstream fout;
  fout.open("./log.txt");
  if (!fout) {
    cout << "Something went wrong can't create new file";
  } else {
    cout << "File created successfully";

    // this line will write into log.txt
    fout << "This was written by cpp using file handling ";
  }
  fout.close();

  ifstream fin;
  string line;

  fin.open("./log.txt");
  if (!fin) {
    cout << "can't open file ";
  } else {
    cout << "opened file successfully";
    while (!fin.eof()) {  // eof stands for end of file
      getline(fin, line);
      cout << line;
    }
  }
  fin.close();
}