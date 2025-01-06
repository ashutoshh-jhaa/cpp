#include <iostream>
using namespace std;

int findFact(int num) {
  if (num == 0)
    return 1;
  return num * findFact(num - 1);
}

int combinations(int n, int r) {
  int res = findFact(n) / (findFact(r) * findFact(n - r));
  return res;
}

int main() {
  int lines;
  cout << "Enter the Number of lines : ";
  cin >> lines;

  for (int i = 0; i < lines; i++) {
    for (int j = 0; j <= i; j++) {
      cout << combinations(i, j);
    }
    cout << endl;
  }
}