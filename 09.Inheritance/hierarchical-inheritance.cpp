#include <iostream>
using namespace std;

class A {
  // Base class
 public:
  A() { cout << "default constructor from A\n"; }
};

class B : public A {
  // Derived from A
 public:
  B() { cout << "default constructor from B\n"; }
};

class C : public A {
  // Derived from A
 public:
  C() { cout << "default constructor from C\n"; }
};

int main() {
  B b;
  C c;
}