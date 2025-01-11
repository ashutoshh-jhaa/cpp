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
  friend Complex operator-(Complex);
};
// Friend function definition for binary
Complex operator+(Complex c1, Complex c2) {
  Complex temp;
  temp.x = c1.x + c2.x;
  temp.y = c1.y + c2.y;
  return temp;
}

// Friend function definition for unary
Complex operator-(Complex c) {
  Complex temp;
  temp.x = -c.x;
  temp.y = -c.y;
  return temp;
}

int main() {
  // binary demonstration
  Complex c1(88, 22), c2(10, 10), c3, c4;
  c3 = c1 + c2;  //+ Operator was called and c1 and c2 was passed as arguments
  c4 = operator+(
      c2, c3);  // Same as calling + operator and passing c2,c3 as arguments

  c3.displayValues();
  c4.displayValues();

  // unary demonstration
  Complex c5, c6;
  c5 = -c4;            // - operator was called and c4 was passed as an argument
  c6 = operator-(c1);  // same as - being called passing of c1 as an arguments
  c5.displayValues();
  c6.displayValues();
}
