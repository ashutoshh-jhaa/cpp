#include <iostream>
using namespace std;

class Complex {
 private:
  int real, img;

 public:
  void set(int r, int i) {
    real = r;
    img = i;
  }

  int getReal() { return real; }
  int getImg() { return img; }

  void display() { cout << real << " + " << img << "i" << endl; }

  // Add two complex numbers and return the result
  Complex addComplex(Complex c) {
    Complex result;
    result.set(real + c.real, img + c.img);
    return result;
  }
};

int main() {
  Complex c1, c2, sum;
  c1.set(12, 34);
  c2.set(9, 43);

  cout << "Complex Numbers:" << endl;
  c1.display();
  c2.display();

  sum =
      c1.addComplex(c2);  // Explicitly passing c2 while c1 is passed implicitly
  cout << "Sum: ";
  sum.display();

  return 0;
}
