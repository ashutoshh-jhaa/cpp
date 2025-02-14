// demonstrate virtual function
#include <iostream>
using namespace std;

class Base {
 public:
  virtual void fun() { cout << "fun from Base class\n"; }
  void funA() { cout << "funA from Base class\n"; }
};

class Derived : public Base {
 public:
  void fun() { cout << "fun from Derived class\n"; }
  void funB() { cout << "funB from Derived class\n"; }
};

int main() {
  Base* b;
  Derived* d;

  Base obj1;
  Derived obj2;

  // Base class pointer pointing to a Derived class object
  b = &obj2;

  // Normally, function calls are resolved based on the pointer type.
  // Since 'b' is a Base class pointer, it would call Base::fun() (early
  // binding).

  // However, since fun() is virtual, late binding occurs.
  // The function call is resolved at runtime, calling Derived::fun().
  b->fun();  // Output: "fun from Derived class"

  return 0;
}
