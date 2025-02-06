// wap to validate a username which has 6 letters with special characters
#include <cstring>
#include <iostream>
#include <regex>
using namespace std;

bool validateUsername(char* str) {
  regex pattern(R"([a-zA-Z0-9]{4}[@#$%!]{2})");
  if (regex_match(str, pattern)) {
    return true;
  } else {
    return false;
  }
}

int main() {
  char username[8];
  cout << "Enter your Name :  \n";
  try {
    cin.getline(username, 8);
    if (strlen(username) != 6) {
      throw "Username must be 6 character long";
    }
    if (!validateUsername(username)) {
      throw "Not valid Username";
    }
    cout << "Username validated!";
  } catch (const char* e) {
    cout << "Erro : " << e;
  }
}