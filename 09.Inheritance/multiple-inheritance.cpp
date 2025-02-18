#include <iostream>
using namespace std;

class A {
  // Base class
 public:
  A() { cout << "default constructor from A\n"; }
};

class B {
 public:
  B() { cout << "default constructor from B\n"; }
};

class C : public A, public B {
  // Derived from A and B
 public:
  C() { cout << "default constructor from C\n"; }
};

int main() {
  C c;
}