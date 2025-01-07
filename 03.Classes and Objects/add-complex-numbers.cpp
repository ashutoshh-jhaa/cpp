// wap to add complex numbers
#include <iostream>
using namespace std;

class Complex {
 private:
  int real, img;

 public:
  void setData(int r, int i) {
    real = r;
    img = i;
  }

  void showData() { cout << real << " + " << img << "i" << endl; }

  // Add two complex numbers
  Complex addComplex(Complex c) {
    Complex result;
    result.real = real + c.real;
    result.img = img + c.img;
    return result;
  }
};

int main() {
  Complex c1, c2, c3;

  c1.setData(12, 20);
  c2.setData(3, 88);

  // Add the two complex numbers and store the result in c3
  c3 = c1.addComplex(c2);

  // Display the result
  c3.showData();

  return 0;
}
