// wap to validate email without using regex

#include <cstring>
#include <iostream>
using namespace std;

bool validateEmail(const char* e);

int main() {
  char email[100];
  cout << "Enter your Email: ";

  cin.getline(email, 100);

  try {
    if (validateEmail(email)) {
      cout << "Valid Email!" << endl;
    } else {
      throw "Invalid Email!";
    }
  } catch (const char* e) {
    cout << e << endl;
  }
}

bool validateEmail(const char* e) {
  int atOffset = -1;
  int dotOffset = -1;
  int length = 0;

  for (int i = 0; e[i] != '\0'; i++) {
    if (e[i] == '@') {
      atOffset = i;
    } else if (e[i] == '.') {
      dotOffset = i;
    }
    length++;
  }

  if (atOffset == -1 || dotOffset == -1 || atOffset > dotOffset) {
    return false;
  }

  return (dotOffset < (length - 2));
}
