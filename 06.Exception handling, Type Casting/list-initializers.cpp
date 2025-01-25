/*
  feature of list intializer
  - for initializers of non-static const data member
  - for initialization of reference variables
  - for initialization of objects, whose class don't have default constructor
  - for initialization of base class members
  - when constructor's parameter name is same data members
  - for performance reasons
*/
#include <iostream>
using namespace std;

class Abc {
 private:
  int number;

 public:
  Abc(int x) { number = x; }

  int display() { return number; }
};

class Complex {
 private:
  int real, img;
  const int noChange;
  int& ref;
  Abc a1;  // Abc does not have default constructor

 public:
  Complex(int r, int i, int c, int& n, int a)
      : real(r), img(i), noChange(c), ref(n), a1(a) {}

  void display() {
    cout << "real : " << real << endl;
    cout << "img : " << img << endl;
    cout << "const : " << noChange << endl;
    cout << "reference : " << ref << endl;
    cout << "a1 : " << a1.display() << endl;
  }
};

int main() {
  int num = 8484;
  Complex c1(2, 4, 6, num, 9);
  c1.display();
}
