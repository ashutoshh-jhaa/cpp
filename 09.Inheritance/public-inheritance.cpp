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

// The public flag determines the access level of inherited members.
// Public members remain public, protected remain protected, and private members
// are inherited but inaccessible.
class Derived : public Base {
 public:
  void fun4() { cout << "fun4 from derived \n"; }

  void checkPublic() {
    fun1();  // Accessible (public in Base remains public in Derived)
    fun2();  // Accessible (protected in Base remains protected in Derived)

    // fun3();  // Not accessible (private members are inherited but
    // inaccessible)
  }

 protected:
  void fun5() { cout << "fun5 from derived \n"; }

 private:
  void fun6() { cout << "fun6 from derived \n"; }
};

int main() {
  Derived d;
  d.checkPublic();

  d.fun1();  // Accessible since it's inherited as public

  // d.fun2();  // Not accessible outside the class (protected)

  // d.fun3();  // Not accessible (private in Base)
}
