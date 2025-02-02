// overloading of -> operator to directly access members

#include <iostream>
using namespace std;
class Complex {
 private:
  int real, img;

 public:
  Complex() {}

  Complex(int r, int m) : real(r), img(m) {}

  void display() {
    cout << "real : " << real << endl;
    cout << "img : " << img << endl;
  }

  // overloading of -> operator
  Complex* operator->() { return this; }
};
int main() {
  Complex c1(23, 88);

  c1->display();

  // Complex* c2 = &c1;
  // (*c2).display();
}