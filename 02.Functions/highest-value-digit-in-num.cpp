// find the highest value digit in a given number
#include <iostream>
using namespace std;
int findHighestDigit(int num) {
  int max = 0;
  while (num != 0) {
    if (num % 10 > max)
      max = num % 10;
    num /= 10;
  }
  return max;
}
int main() {
  int num;
  cout << "Enter any Number : ";
  cin >> num;

  cout << "Highest Value digit : " << findHighestDigit(num);
}