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
  o << "\nage : " << p.age << "\nteeth : " << p.teeth;
  return o;  // Return the ostream object to enable chaining
}

int main() {
  Person p1(333, 23), p2(23, 9);

  /*
    If we do not return a reference to ostream from the overloaded << operator,
    the next call in the chain would look like this: void << p2.
    Since no function with a void parameter exists, the code will fail to
    compile. By returning a reference to ostream, the chaining works as follows:
    The first call (cout << p1) returns ostream&, which is then used in the
    second call (<< p2). This allows ostream to be passed along with p2 for the
    second operation, enabling chaining.
  */
  cout << p1 << p2
       << endl;  // Use overloaded << to print details of both Person objects

  // Alternative usage (unconventional and not recommended):
  // p1 << cout;

  return 0;
}
