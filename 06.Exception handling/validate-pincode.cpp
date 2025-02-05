// wap to validate pin-code using try and catch

#include <cstring>
#include <iostream>
using namespace std;

bool validatePin(const char* pin) {
  for (int i = 0; i < 6; i++) {
    if (pin[i] < '0' || pin[i] > '9') {
      cout << pin[i] << endl;
      return false;
    }
  }
  return true;
}

int main() {
  char pinCode[8];
  cout << "Enter You Pincode : \n";

  try {
    cin.getline(pinCode, 8);
    if (strlen(pinCode) != 6) {
      throw "Pin must contain 6 digits";
    }
    if (!validatePin(pinCode)) {
      throw "Invalid input. Enter only numeric digits.";
    }
    cout << "Pin code validated !";
  } catch (const char* e) {
    cout << "Error : " << e;
  }
}