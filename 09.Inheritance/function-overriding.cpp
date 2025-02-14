// demonstrate function overriding
#include <iostream>
using namespace std;

class A {
 public:
  void fun() { cout << "fun from Base class\n"; }
};

class B : public A {
 public:
  // This function `fun()` is inherited from A but redefined in B.
  // This is called function overriding, where the derived class provides
  // its own implementation of a function that exists in the base class.
  void fun() { cout << "fun from Derived class\n"; }
};

int main() {
  B b;
  b.fun();  // Calls the overridden `fun()` from class B, not A.
}
