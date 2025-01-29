// wap to create a class coordinate and overloading , such that writing
// c3=(c1,c2) assigns c2 to c3
#include <iostream>
using namespace std;

class Coordinate {
 private:
  int x, y, z;

 public:
  Coordinate() {}

  Coordinate(int x, int y, int z) : x(x), y(y), z(z) {}

  void display() {
    cout << "x : " << x << endl;
    cout << "y : " << y << endl;
    cout << "z : " << z << endl;
  }

  // overloading , operator
  Coordinate& operator,(Coordinate& c1) { return c1; }
};

int main() {
  Coordinate c1(23, 5, 8), c2(8, 83, 2), c3;
  c3 = (c1, c2);
  c3.display();
}