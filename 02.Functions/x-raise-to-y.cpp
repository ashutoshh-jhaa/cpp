// function to calculate x raise to y
#include <iostream>
using namespace std;

float findPower(float num, int pow) {
  float res = 1;

  if (num == 0)
    return 0;
  if (pow == 0)
    return 1;
  if (pow == 1)
    return num;

  if (pow < 0) {
    num = 1 / num;
    pow = -pow;
  }
  for (int i = 0; i < pow; i++)
    res *= num;
  return res;
}

int main() {
  int num, pow;
  cout << "Enter a Number : ";
  cin >> num;

  cout << "Enter pow : ";
  cin >> pow;

  cout << "Answer : " << findPower(num, pow);
}