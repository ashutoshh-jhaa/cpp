// check if given number is a term of fibonacci series or not
#include <iostream>
using namespace std;

bool isFiboTerm(int num) {
  int prevTerm = 0, currTerm = 1, nextTerm = 1;

  if (num == 0 || num == 1)
    return true;

  while (nextTerm <= num) {
    nextTerm = prevTerm + currTerm;
    prevTerm = currTerm;
    currTerm = nextTerm;

    if (num == nextTerm)
      return true;
  }
  return false;
}

int main() {
  int num;
  cout << "Enter any Number: ";
  cin >> num;

  if (isFiboTerm(num))
    cout << num << " is a term in the Fibonacci series." << endl;
  else
    cout << num << " is NOT a term in the Fibonacci series." << endl;

  return 0;
}
