// when we create any one of parameterized or default constructor compiler does
// not create default constructor
#include <iostream>
using namespace std;

class Person {
 private:
  char age;

 public:
  // parameterized constructer
  Person(int a) { age = a; }

  // copy constructor - shallow copy
  Person(const Person& p) { age = p.age; }

  int getAge() { return age; }
};

int main() {
  Person p1(2), p2(23);
  Person p3(p2);
  Person p4 = p1;
  cout << p3.getAge() << endl;
  cout << p4.getAge() << endl;
}