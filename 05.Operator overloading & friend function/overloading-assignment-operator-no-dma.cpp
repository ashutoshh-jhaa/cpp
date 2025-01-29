// wap to overload assignment operator for a class complex
#include <iostream>
using namespace std;
class Complex {
 private:
  int real, img;

 public:
  // Default constructor
  Complex() {}

  // Parameterized constructor
  Complex(int real, int img) : real(real), img(img) {}

  void display() {
    cout << "real : " << real << endl;
    cout << "img : " << img << endl;
  }

  // assignment operator
  Complex& operator=(Complex x) {
    real = x.real;
    img = x.img;
    return *this;
  }
};
int main() {
  Complex c1(34, 98), c2, c3(7, 9);
  c3 = c2 = c1;
  c1.display();
  c2.display();
  c3.display();
}