// demonstrating late binding and runtime polymorphism using virtual functions
#include <iostream>
using namespace std;

class Flight {
 public:
  void search() { cout << "Flight search \n"; }

  // Declaring book() as virtual enables late binding (runtime polymorphism).
  virtual void book() { cout << "Book Flight\n"; }
};

class AirIndia : public Flight {
 public:
  // Overrides Flight::book(). Since book() is virtual in the base class,
  // this overridden method will be called when using a Flight* pointing to an
  // AirIndia object.
  void book() { cout << "Book AirIndia Flight \n"; }
};

class SpiceJet : public Flight {
 public:
  // Overrides Flight::book(), ensuring the correct method is called at runtime.
  void book() { cout << "Book SpiceJet Flight \n"; }
};

int main() {
  Flight *f1, *f2;

  AirIndia a1;
  SpiceJet s1;

  f1 = &a1;
  f2 = &s1;

  // Late binding occurs here because book() is virtual.
  // The appropriate overridden method is called based on the actual object
  // type.
  f1->book();  // Calls AirIndia::book()
  f2->book();  // Calls SpiceJet::book()

  // Early binding occurs here because search() is NOT virtual.
  // It is resolved at compile time based on the pointer type (Flight*).
  f1->search();  // Calls Flight::search()
  f2->search();  // Calls Flight::search()

  return 0;
}
