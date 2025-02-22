// demonstrate scalar product using classes
#include <iostream>
using namespace std;

class Scalar {
 private:
  int* v;
  int size;

 public:
  Scalar(int m) { v = new int[size = m]; }

  // Incorrect Constructor (Issue: `size` is uninitialized)
  // This constructor is supposed to initialize `v` with an array `a`,
  // but `size` is uninitialized here, leading to garbage values or crash
  // Scalar(int* a) {
  //   for (int i = 0; i < size; i++) {
  //     v[i] = a[i];
  //   }
  // }

  ~Scalar() { delete[] v; }

  // Overloaded assignment operator to copy values from an array to `v`
  void operator=(int* a) {
    delete[] v;
    v = new int[size];
    for (int i = 0; i < size; i++) {
      v[i] = a[i];
    }
  }

  // scalar product
  int operator*(Scalar& s) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
      sum += this->v[i] * s.v[i];
    }
    return sum;
  }

  // Function to display the vector elements
  void display() {
    for (int i = 0; i < size; i++) {
      cout << "value : " << v[i] << endl;
    }
  }
};

int main() {
  int a1[3] = {1, 2, 3};
  int a2[3] = {4, 5, 6};

  Scalar s1(3);
  Scalar s2(3);

  s1 = a1;
  s2 = a2;

  s1.display();
  s2.display();

  int result = s1 * s2;
  cout << "Scalar Product: " << result << endl;

  return 0;
}
