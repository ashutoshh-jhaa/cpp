// demonstrate diamond problem in inheritance
#include <iostream>
using namespace std;

// Base class A
class A {
 public:
  A() { cout << "A() called \n"; }
};

// Class B inherits from A virtually
class B : virtual public A {
 public:
  B() { cout << "B() called \n"; }
};

// Class C inherits from A virtually
class C : virtual public A {
 public:
  C() { cout << "C() called \n"; }
};

// Class D inherits from B and C virtually
class D : virtual public B, virtual public C {
 public:
  D() { cout << "D() called \n"; }
};

int main() {
  D d;  // Instantiate object of class D
  // Without 'virtual' inheritance, D would have two copies of A (one through B
  // and one through C) Using 'virtual' ensures that only one copy of A is
  // created

  return 0;
}
