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

class complex {
 private:
  int real, img;

 public:
  // default constructor
  complex() { cout << "default constructor called\n"; }

  // conversion constructor (int -> complex)
  complex(int r) : real(r), img(r) {
    cout << "conversion constructor (1 parameter) called\n";
  }

  // parameterized constructor (int, int -> complex)
  complex(int r, int i) : real(r), img(i) {
    cout << "parameterized constructor (2 parameters) called\n";
  }

  // overloaded assignment operator to convert int to complex
  void operator=(int x) {
    real = img = x;
    cout << "operator= (int) called\n";
  }

  // display the complex number
  void display() const {
    cout << "real: " << real << endl;
    cout << "imaginary: " << img << endl;
  }
};

int main() {
  int value = 23;
  complex c1;

  // using operator= to convert int to complex
  c1 = value;

  // display the result
  c1.display();

  return 0;
}
