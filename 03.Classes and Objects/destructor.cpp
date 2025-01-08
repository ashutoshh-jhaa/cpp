#include <cstdlib>
#include <iostream>

class Complex {
 private:
  int a;
  int* ptr;

 public:
  Complex(int x, int y) {
    a = x;
    ptr = (int*)malloc(4);
    *ptr = y;
  }

  // Destructor to free the dynamically allocated memory
  ~Complex() {
    std::cout << "End of Object" << std::endl;
    free(ptr);
  }
};

void fun() {
  Complex c1(2, 3);
}

int main() {
  fun();
  Complex c1(32, 4);
}
