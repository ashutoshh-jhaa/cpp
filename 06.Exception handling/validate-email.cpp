// wap to validate email entered by the user
#include <iostream>
#include <regex>
using namespace std;

int main() {
  char* email = new char[100];
  cout << "Enter your E-mail address : \n";
  cin >> email;
  cout << email << endl;

  try {
    regex pattern(R"(^[a-zA-Z0-9.]+@[a-zA-Z0-9]+\.[a-zA-Z0-9]{2,}$)");

    if (regex_match(email, pattern)) {
      cout << "Valid email!" << endl;
    } else {
      throw "Invalid email!";
    }
  } catch (const char* e) {
    cout << "Error : " << e << endl;
  }

  delete[] email;
  return 0;
}