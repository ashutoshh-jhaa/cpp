#include <iostream>
int main() {
  int num1, num2;
  std::cout << "Enter two Numbers : ";
  std::cin >> num1 >> num2;

  int gr8 = (num1 > num2) ? num1 : num2;
  std::cout << "Greatest : " << gr8;
}