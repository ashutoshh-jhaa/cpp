// wap to overload ! to return negative of a number
#include <iostream>
using namespace std;

class Integer {
 private:
  int num;

 public:
  Integer() {}
  Integer(int n) : num(n) {}

  void display() { cout << "num : " << num << endl; }

  void operator!() { num = -num; }
};
int main() {
  Integer i1(484), i2(-23), i3(9);
  !i1;
  !i2;
  !i3;

  i1.display();
  i2.display();
  i3.display();
}