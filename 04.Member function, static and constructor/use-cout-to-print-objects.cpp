#include <iostream>
using namespace std;

class Person {
 private:
  int age, teeth;

 public:
  Person() {};
  Person(int a, int t) {
    age = a;
    teeth = t;
  }

  // Friend function declaration to allow access to private members
  friend ostream& operator<<(ostream&, Person);
};

// Overload << operator to print details of a Person object
// Returning ostream& is necessary for chaining << operations
ostream& operator<<(ostream& o, Person p) {
  o << "age : " << p.age << "\nteeth : " << p.teeth;
  return o;  // Return the ostream object to enable chaining
}

int main() {
  Person p1(333, 23);

  cout << p1 << endl;  // Use overloaded << to print Person details

  // Alternative usage (unconventional and not recommended):
  // p1 << cout;

  return 0;
}
