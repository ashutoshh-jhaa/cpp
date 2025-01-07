// wap to find Factorial using class
#include <iostream>
using namespace std;

class Factorial {
 private:
  int num;
  int factorial;

 public:
  // Setters and Getters
  void setNum(int n) { num = n; }
  int getNum() { return num; }
  int getFact() { return factorial; }

  // Calculate factorial
  void findFactorial() {
    int fact = 1;
    for (int i = 1; i <= num; i++) {
      fact *= i;
    }
    factorial = fact;
  }
};

int main() {
  Factorial f1;
  f1.setNum(5);

  cout << "Number: " << f1.getNum() << endl;

  f1.findFactorial();
  cout << "Factorial: " << f1.getFact() << endl;

  return 0;
}
