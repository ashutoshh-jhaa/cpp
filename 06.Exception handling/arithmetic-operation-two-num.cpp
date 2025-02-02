// wap to perform arithmetic operation on two numbers and throw an exception if
// divided is zero or doesn't contain a valid operator
#include <iostream>
using namespace std;

int main() {
  float num1, num2, ans;
  char optr;

  cout << "Perform Arithemetic Operations on Two Numbers \n";
  cout << "------------------------------\n";

  try {
    cout << "Enter two Numbers : \n";
    cin >> num1 >> num2;

    if (num1 == 0)
      throw num1;

    cout << "Enter the Operator : \n";
    cin >> optr;

    if (optr != '+' && optr != '-' && optr != '/' && optr != '*')
      throw optr;

    switch (optr) {
      case '+': {
        ans = num1 + num2;
        break;
      }
      case '-': {
        ans = num1 - num2;
        break;
      }
      case '/': {
        if (num2 == 0)
          throw num2;
        ans = num1 / num2;
        break;
      }
      case '*': {
        ans = num1 * num2;
        break;
      }
    }
    cout << "Answer = " << ans;

  } catch (int n) {
    cout << "Error : Bad Operation " << n;
  } catch (const char e) {
    cout << "Exception Caught : Bad Operator " << e;
  }
}