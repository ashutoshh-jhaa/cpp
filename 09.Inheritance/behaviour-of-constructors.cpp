// Demonstrate the behaviour of constructors in inheritance
#include <iostream>

class A {
 private:
  void funA1() { std::cout << "private of A\n"; }

 protected:
  void funA2() { std::cout << "protected of A\n"; }

 public:
  void funA3() { std::cout << "public of A\n"; }

  // If we uncomment the following constructor, the code won't compile
  // unless we explicitly call it in B, since A won't have a default
  // constructor.
  A(int a) {
    std::cout << "A's parameterized constructor called with value: " << a
              << "\n";
  }
};

class B : public A {
 private:
  void funB1() { std::cout << "private of B\n"; }

 protected:
  void funB2() { std::cout << "protected of B\n"; }

 public:
  void funB3() {
    std::cout << "public of B\n";
    // funA2(); // Not accessible outside the derived class
    // funA3(); // Accessible but commented for demonstration
  }

  // By default, the compiler tries to call A() (which does not exist).
  // We must explicitly call A's constructor like this:
  B() : A(23) { std::cout << "B's constructor called\n"; }
};

int main() {
  std::cout << "Creating object of B...\n";
  B b;
  b.funB3();

  // When an object of B is created, the compiler first looks for B's
  // constructor. Then it tries to call A’s constructor before executing B's
  // constructor body. If A does not have a default constructor, B must
  // explicitly call A(int).
}
