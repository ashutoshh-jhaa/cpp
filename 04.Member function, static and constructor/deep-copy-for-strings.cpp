#include <cstring>
#include <iostream>
using namespace std;

class Person {
 public:
  char* name;
  int size;

  // Default Constructor
  Person() {
    name = (char*)malloc(sizeof(char));
    size = 1;
  }

  // Parameterized Constructor
  Person(const char* n) {
    size = strlen(n);
    name = (char*)malloc(size * sizeof(char) + 1);
    strcpy(name, n);
  }

  // Copy Constructor (Deep Copy)
  Person(const Person& p) {
    size = p.size;
    name = (char*)malloc(size * sizeof(char) + 1);
    strcpy(name, p.name);
  }

  // Update Function
  void updateName(const char* n) {
    free(name);
    size = strlen(n);
    name = (char*)malloc(size * sizeof(char) + 1);
    strcpy(name, n);
  }

  // Overloaded << Operator
  friend void operator<<(ostream& o, const Person& p) {
    o << "Name: " << p.name << endl;
    o << "Size: " << p.size << endl;
    o << "Location of name pointer: " << &p.name << endl;
  }

  // Destructor
  ~Person() { free(name); }
};

int main() {
  Person p1("ashutosh");  // Parameterized constructor
  Person p2 = p1;         // Copy constructor
  p2.updateName("ash");

  cout << p1;
  cout << p2;

  return 0;
}