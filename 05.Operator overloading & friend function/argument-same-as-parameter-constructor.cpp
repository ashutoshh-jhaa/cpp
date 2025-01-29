// create a class, make constructor in which the name of the argument should be
// same as parameter
#include <iostream>
using namespace std;

class Complex {
 private:
  float real, img;

 public:
  Complex() { cout << "Default Constructor\n"; }

  // using direct initializers
  Complex(float real, float img) : real(real), img(img) {
    cout << "direct initializer called\n";
  }

  // other way around using this
  // Complex(float real, float img) {
  //   this->real = real;
  //   this->img = img;
  // }

  // this won't work as the name of the parameter is same as argument
  // Complex(float real, float img) {
  //   real = real;
  //   img = img;
  // }
  void display() {
    cout << "real : " << real << endl;
    cout << "img : " << img << endl;
  }
  friend void operator<<(ostream& o, Complex& c);
};

void operator<<(ostream& o, Complex& c) {
  o << c.img;
  o << c.real;
}

int main() {
  Complex c1(23, 5);
  c1.display();
}