/*
wap to convert primitive type to Complex type
  example =>
    int main(){
      Complex c1;
      int x=5;    // int is primitive type
      c1=x;       // c1 is non-primitive type
      return 0
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

  // Conversion constructor (int -> Complex)
  Complex(int r) : real(r), img(r) {
    cout << "Conversion constructor (1 parameter) called\n";
  }

  // Parameterized constructor (int, int -> Complex)
  Complex(int r, int i) : real(r), img(i) {
    cout << "Parameterized constructor (2 parameters) called\n";
  }

  // Overloaded assignment operator to convert int to Complex
  void operator=(int x) {
    real = img = x;
    cout << "operator= (int) called\n";
  }

  // Display the Complex number
  void display() const {
    cout << "Real: " << real << endl;
    cout << "Imaginary: " << img << endl;
  }
};

int main() {
  int value = 23;
  Complex c1;

  // Using operator= to convert int to Complex
  c1 = value;

  // Display the result
  c1.display();

  return 0;
}
