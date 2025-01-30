/*
wap to convert complex type to primitive type
  example =>
    int main(){
      Complex c1;
      int x=c1;
      return 0;
    }
*/

#include <iostream>
using namespace std;

class Complex {
 private:
  int real, img;

 public:
  // Default constructor
  Complex() { cout << "Default constructor called\n"; }

  // Parameterized constructor (int, int -> Complex)
  Complex(int r, int i) : real(r), img(i) {
    cout << "Parameterized constructor (2 parameters) called\n";
  }

  // Display the Complex number
  void display() const {
    cout << "Real: " << real << endl;
    cout << "Imaginary: " << img << endl;
  }

  // converts Complex to int
  operator int() {
    cout << "int() called\n";
    return real + img;
  }
};

int main() {
  Complex c1(4, 5);
  int x = (int)c1;
  cout << x << endl;
}