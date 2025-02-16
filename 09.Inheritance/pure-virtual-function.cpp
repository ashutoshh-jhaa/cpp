// Demonstrate the use of pure virtual functions
// Pure virtual functions are also called "do-nothing" functions.

#include <iostream>
using namespace std;

class Shape {
 public:
  // A pure virtual function is declared using "= 0"
  // This makes the class abstract, meaning we cannot create its object.
  virtual void search() = 0;
};

class Rectangle : public Shape {
  // The pure virtual functions are inherited in the derived class.
  // A derived class must provide definitions for all pure virtual functions,
  // otherwise, it also remains abstract and cannot be instantiated.
 public:
  void search() { cout << "Rectangle area called"; }
};

int main() {
  // Cannot create an object of an abstract class
  // Shape s; // This will cause a compilation error

  // Rectangle r; // This will also cause an error because `search()` is not
  // implemented in Rectangle.
}
