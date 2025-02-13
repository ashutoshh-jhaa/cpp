// demostrate single inheritance in cpp

#include <iostream>

class A {
 private:
  void functionA1() { std::cout << "private of A\n"; }

 protected:
  void functionA2() { std::cout << "protected of A\n"; }

 public:
  void functionA3() { std::cout << "public of A\n"; }
};

class B : public A {
 private:
  void functionB1() { std::cout << "private of B\n"; }

 protected:
  void functionB2() { std::cout << "protected of B\n"; }

 public:
  void functionB3() { std::cout << "public of B\n"; }

  void accessParent() {
    // Can access both protected and public members of base class
    functionA2();
    functionA3();

    // Cannot access private member of base class
    // functionA1(); // Error
  }

  void test() {
    std::cout << "Calling accessParent() from B:\n";
    accessParent();
  }
};

int main() {
  A a;

  // Cannot access private and protected members of A
  // a.functionA1();
  // a.functionA2();
  a.functionA3();

  B b;

  // Cannot access protected/private members of B or inherited protected/private
  // members of A b.functionA2(); // Error b.functionB1(); // Error
  // b.functionB2(); // Error

  b.functionB3();
  b.functionA3();

  // Demonstrating access to base class from derived class
  b.test();

  return 0;
}
