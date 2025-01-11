// wap to count the number of times object is created
#include <iostream>
class Complex {
 private:
  // counts the number of times object is created
  static int count;
  int a;

 public:
  Complex() { count++; };
  Complex(int x) {
    a = x;
    count++;
  }
  static int getCount() { return count; }
};
// initializing static variable
int Complex::count = 0;

int main() {
  Complex c1, c2, c3(3), c4(532), c8;
  std::cout << "Number of Times Object was created  : " << Complex::getCount();
}