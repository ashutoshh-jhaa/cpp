#include <iostream>
using namespace std;

void swap(int& a, int& b) {
  a = a + b;
  b = a - b;
  a = a - b;
}

int main() {
  int num1, num2;
  cout << "Enter a Two Numbers : ";
  cin >> num1 >> num2;

  swap(num1, num2);

  cout << num1 << endl << num2 << endl;
}