#include <iostream>
using namespace std;

int isPrime(int num) {
  if (num <= 1)
    return 0;

  if (num == 2)
    return 1;

  if (num % 2 == 0)
    return 0;

  for (int i = 3; i * i <= num; i += 2) {
    if (num % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int num;
  cout << "Enter a Number to check if it's Prime: ";
  cin >> num;

  (isPrime(num)) ? cout << "The given Number " << num << " is Prime"
                 : cout << "The given Number " << num << " is NOT Prime";

  return 0;
}