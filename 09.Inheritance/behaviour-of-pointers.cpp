// demonstrate the behaviour of pointers in inheritance
#include <iostream>
using namespace std;

class Base {
 public:
  Base() { cout << "Base class constructor\n"; }
  void printBase() { cout << "Base\n"; }
};

class Derived : public Base {
 public:
  Derived() { cout << "Derived class constructor\n"; }
  void printDerived() { cout << "Derived\n"; }
};

int main() {
  Base* b;     // Base class pointer
  Derived* d;  // Derived class pointer

  Base obj1;     // Base class object
  Derived obj2;  // Derived class object

  //  Valid: A base class pointer can point to a base class object.
  b = &obj1;

  //  Valid: A derived class pointer can point to a derived class object.
  d = &obj2;

  //  Valid: A base class pointer can point to a derived class object
  // (UPCASTING). Reason: Since Derived inherits Base, a Derived object
  // contains Base's properties. A base class pointer can access only the
  // Base part of the Derived object.
  b = &obj2;

  // Invalid: A derived class pointer cannot point to a base class object
  // (DOWNCASTING). Reason: The base class object does not contain the
  // additional members of Derived. If this were allowed, `d` would expect
  // Derived-specific members that don't exist in obj1. d = &obj1;
  // Uncommenting this will cause a compilation error.

  // Valid: Even though `b` points to a `Derived` object (`obj2`), it is of type
  // `Base*`. A base class pointer can only access base class methods, even if
  // it points to a derived object.
  b->printBase();

  // access derived-specific methods. The compiler will throw an error because
  // `printDerived()` is not part of `Base`.
  // b->printDerived();  // Invalid: `b` is a base class pointer and cannot

  // The derived class has both `printBase()` (inherited) and `printDerived()`.
  d->printBase();
  d->printDerived();

  return 0;
}