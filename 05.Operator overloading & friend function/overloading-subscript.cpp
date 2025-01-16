#include <iostream>
using namespace std;
class Array {
 private:
  int a[100];
  const int size = 100;

 public:
  Array() {}
  Array(int value, int idx) {
    if (idx > size) {
      cout << "Array index out of bound exception";
      exit(0);
    };
    a[idx] = value;
  }
  int operator[](int idx) {
    if (idx > size) {
      cout << "Array index out of bound exception";
      exit(0);
    };
    return a[idx];
  }
  void operator()(int value, int idx) {
    if (idx > size) {
      cout << "Array index out of bound exception";
      exit(0);
    }
    a[idx] = value;
  }
};
int main() {
  Array a(23, 3);
  cout << a[3] << endl;
  Array b;
  b(92, 9);
  cout << b[9] << endl;
}