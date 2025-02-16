// demostrate ambiguity in function calls
#include <iostream>
using namespace std;

class A {
 public:
  void fun() { cout << "fun from A\n"; }
};

class B {
 public:
  void fun() { cout << "fun from B\n"; }
};

class C : public A, public B {
 public:
  // void fun() {
  //   cout << "fun from C\n";
  // }  // Overriding (not actual function overwriting)
};

int main() {
  C c;

  // c.fun();     // Calls fun() from C (overridden function)
  c.A::fun();  // Calls fun() from A
  c.B::fun();  // Calls fun() from B

  C* ptrc = &c;
  // ptrc->fun();  // Calls fun() from C

  ptrc->A::fun();  // Calls fun() from A
  ptrc->B::fun();  // Calls fun() from B

  return 0;
}
