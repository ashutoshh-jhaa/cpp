#include <iostream>
using namespace std;

template <class F = float, class I = int, class C = char>
class Multi {
 private:
  F f;
  I i;
  C c;

 public:
  Multi(F f_val, I i_val, C c_val) : f(f_val), i(i_val), c(c_val) {}

  void display() {
    cout << "Float: " << f << ", Int: " << i << ", Char: " << c << endl;
  }
};

int main() {
  int x = 32;
  float y = 23.4;
  char z = 'a';

  // Creating an object with explicit type specification
  Multi<float, int, char> m(y, x, z);
  m.display();

  // Using default template parameters
  Multi<> m2(10.5, 20, 'b');
  m2.display();

  return 0;
}