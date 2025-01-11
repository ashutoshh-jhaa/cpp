// Wap to demonstrate use of operator as friend
#include <iostream>
using namespace std;
class Complex {
 private:
  int x, y;

 public:
  Complex() {
    x = 0;
    y = 0;
  }
  Complex(int a, int b) {
    x = a;
    y = b;
  }
  void displayValues() {
    cout << "x : " << x << endl;
    cout << "y : " << y << endl;
  }
  // Friend function declaration
  friend Complex operator+(Complex, Complex);
};
// Friend function definition
Complex operator+(Complex c1, Complex c2) {
  Complex c3;
  c3.x = c1.x + c2.x;
  c3.y = c1.y + c2.y;
  return c3;
}

int main() {
  Complex c1(88, 22), c2(10, 10), c3, c4;
  c3 = c1 + c2;  //+ Operator was called and c1 and c2 was passed as arguments
  c4 = operator+(
      c2, c3);  // Same as calling + operator and passing c2,c3 as arguments

  c3.displayValues();
  c4.displayValues();
}
