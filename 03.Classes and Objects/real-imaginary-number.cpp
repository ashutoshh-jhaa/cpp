// wap to implement complex numbers using classes and objects
#include <iostream>
using namespace std;

class Complex {
 private:
  float real, img;

 public:
  // Set real and imaginary parts
  void set(float a, float b) {
    real = a;
    img = b;
  }

  // Get real and imaginary parts
  float getReal() { return real; }
  float getImg() { return img; }

  // Display complex number
  void displayComplex() { cout << img << " + " << real << "i" << endl; }
};

int main() {
  Complex c1, c2;

  // Initialize c1 and c2
  c1.set(23, 32);
  c2.set(1, 2);

  // Print real and imaginary parts
  cout << c1.getReal() << endl;
  cout << c1.getImg() << "i" << endl;
  cout << c2.getReal() << endl;
  cout << c2.getImg() << "i" << endl;

  // Display complex numbers
  c1.displayComplex();
  c2.displayComplex();

  return 0;
}
