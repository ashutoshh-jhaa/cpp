// Demonstrate the behaviour of destructor in inheritance
#include <iostream>

class A {
 public:
  A(int a) { std::cout << "Constructor of Parent called\n"; }
  ~A() { std::cout << "Destructor of Parent called\n"; }
};

class B : public A {
 public:
  int val;
  // Member initializer list calls A's parameterized constructor first.
  // This ensures the base class (A) is fully constructed before B's body runs.
  B(int x) : A(23), val(x) { std::cout << "Constructor of Child called\n"; }

  // Destructor of B runs first, then A's destructor (reverse order of
  // construction).
  ~B() { std::cout << "Destructor of Child called\n"; }
};

int main() {
  std::cout << "Creating object of B...\n";
  B b(23);  // Calls A(23) first, then B(int x).

  // Output:
  // 1. Base class (A) constructor runs first.
  // 2. Derived class (B) constructor runs next.
  // 3. Upon exiting main(), B's destructor runs first.
  // 4. Finally, A's destructor runs.

  return 0;
}