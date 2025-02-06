#include <fstream>
#include <iostream>
using namespace std;

int main() {
  string line;

  // Open file in append mode to write
  ofstream fout("./newfile.txt", ios::app);
  if (!fout) {
    cout << "Something went wrong\n";
    return 1;
  }

  cout << "File opened successfully. Enter text: ";
  getline(cin, line);
  fout << line << "\n";  // Ensuring newline after writing
  fout.close();          // Close file after writing

  cout << "\nReading from file:\n";

  // Now open file for reading
  ifstream fin("./newfile.txt");
  if (!fin) {
    cout << "Can't read file\n";
    return 1;
  }

  string newstr;
  while (getline(fin, newstr)) {
    cout << newstr << "\n";  // Read line by line
  }

  fin.close();  // Close file after reading
  return 0;
}
