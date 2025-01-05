#include <iostream>
using namespace std;
int main() {
  int num1, num2;
  cout << "Enter Two Numbers : ";
  cin >> num1 >> num2;
  num1 = num1 * num2;
  num2 = num1 / num2;
  num1 = num1 / num2;

  cout << "Num1 : " << num1 << endl << "Num2 : " << num2;
}