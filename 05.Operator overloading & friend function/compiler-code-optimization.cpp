#include <iostream>
using namespace std;

class Person {
 private:
  int age, rank;

 public:
  // Default constructor
  Person() { cout << "Default constructor \n"; }

  // Parameterized constructor
  Person(int a, int r) {
    cout << "Parameterized constructor \n";
    age = a;
    rank = r;
  }

  // Copy constructor
  Person(Person& p) {
    cout << "Copy constructor \n";
    age = p.age;
    rank = p.rank;
  }

  // Operator+ implementation
  // In this version, the return depends on the runtime condition (`age > 0`).
  // Because of this, the compiler cannot guarantee which object will be
  // returned
  // (`temp` or `t`). As a result, **copy elision** is not guaranteed, and the
  // copy constructor is invoked when returning the selected object.
  Person operator+(Person& p) {
    Person temp, t;  // Create temporary objects
    temp.age = age + p.age;
    temp.rank = rank + p.rank;
    return (age > 0) ? temp : t;  // Return based on runtime condition
  }

  // Alternate implementation demonstrating RVO (Return Value Optimization):
  // If the compiler can determine at compile-time that a specific object (like
  // `temp`) will always be returned, **copy elision** applies. The compiler
  // optimizes the code by directly constructing `temp` in the location where
  // the caller needs it (e.g., `p4`). This avoids calling the copy constructor
  // entirely, improving performance.
  /*
  Person operator+(Person& p) {
    Person temp; // Temporary object
    temp.age = age + p.age;
    temp.rank = rank + p.rank;
    return temp; // Guaranteed RVO (Return Value Optimization)
  }
  */
};

int main() {
  Person p1(23, 4), p5(85, 2);  // Parameterized constructor called
  Person p2;                    // Default constructor called
  Person p3 = p1;               // Copy constructor called
  Person p4 = p1 + p5;  // Operator+ called, copy constructor used due to lack
                        // of guaranteed elision
}
