// wap that takes a number from the user and tests if the number is a single
// digit number

#include <iostream>
using namespace std;

void testNum() {
  int num;
  cout << "Enter a Number : \n";
  cin >> num;

  try {
    if (num >= 0 && num < 10) {
      throw num;

    } else if (num < 0) {
      throw "Negative Number";

    } else {
      throw "It is not a single Number";
    }
  } catch (const int x) {
    cout << "It is a single Number" << x << endl;
  } catch (const char* str) {
    cout << "Error : " << str;
  }
}

int main() {
  testNum();
}
