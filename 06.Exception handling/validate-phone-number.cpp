// wap to validate number entered by the user and use try catch
#include <cstring>
#include <iostream>
using namespace std;

bool validateNumber(const char* str);

int main() {
  char number[12];

  cout << "Enter your Number: ";
  cin.getline(number, 12);
  try {
    if (strlen(number) != 10) {
      throw "Number must be exactly 10 digits.";
    }
    if (!validateNumber(number)) {
      throw "Invalid input. Enter only numeric digits.";
    }
    cout << "Phone Number Validated!" << endl;
  } catch (const char* e) {
    cout << "Error: " << e << endl;
  }

  return 0;
}

bool validateNumber(const char* str) {
  for (int i = 0; i < 10; i++) {
    if (str[i] < '0' || str[i] > '9') {
      return false;
    }
  }
  return true;
}
