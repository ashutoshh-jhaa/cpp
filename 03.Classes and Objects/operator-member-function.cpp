// wap to demonstrate the use of operators as member functions
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

  void displayValues() { cout << x << endl << y << endl; }

  // binary operator member function
  Complex operator+(Complex c) {
    Complex temp;
    temp.x = x + c.x;
    temp.y = y + c.y;
    return temp;
  }

  // unary operator member function
  Complex operator-() {
    Complex temp;
    temp.x = -x;
    temp.y = -y;
    return temp;
  }
};
int main() {
  // Binary operator demonstration
  Complex c1(9, 10), c2(2, 3), c3, c4;

  c3 = c1 + c2;  // c1 calls its + operator, passing c2 as argument
  c4 = c3 + c2;  // c3 calls its + operator, passing c2 as argument
  c3.displayValues();
  c4.displayValues();

  // Unary operator demonstration
  Complex c5, c6;
  c5 = -c4;             // c4 calls its - operator
  c6 = c3.operator-();  // Explicit call to - operator
  c5.displayValues();
  c6.displayValues();

  return 0;
}