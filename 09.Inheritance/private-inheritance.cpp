// demostrate private access modifier in inheritance
#include <iostream>
using namespace std;

class Base {
 public:
  void fun1() { cout << "fun1 from base \n"; }

 protected:
  void fun2() { cout << "fun2 from base \n"; }

 private:
  void fun3() { cout << "fun3 from base \n"; }
};

class Derived : private Base {
 public:
  void fun4() { cout << "fun4 from derived \n"; }

  void checkPublic() {
    fun1();  // Accessible: public in Base becomes private in Derived
    fun2();  // Accessible: protected in Base becomes private in Derived

    // fun3();  // Not accessible: private members are never inherited
  }

 protected:
  void fun5() { cout << "fun5 from derived \n"; }

 private:
  void fun6() { cout << "fun6 from derived \n"; }
};

int main() {
  Derived d;
  d.checkPublic();  // Allowed, since checkPublic() is public in Derived

  // d.fun1();  // Error: fun1() is now private in Derived, so it can't be
  // accessed outside
}