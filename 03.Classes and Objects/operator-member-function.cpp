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

  void display() { cout << x << endl << y << endl; }

  Complex operator+(Complex c) {
    Complex c1;
    c1.x = x + c.x;
    c1.y = y + c.y;
    return c1;
  }
};
int main() {
  Complex c1(9, 10), c2(2, 3), c3, c4;

  c3 = c1.operator+(c2);  // c1 called it's + operator and passed c2 as argument
  c4 = c3 + c2;  // same as c3 calling it's + operator and passing c2 as
                 // argument
  c3.display();
  c4.display();
}