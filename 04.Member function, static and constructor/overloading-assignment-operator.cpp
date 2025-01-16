#include <cstring>
#include <iostream>
using namespace std;

class Person {
 private:
  char* name;
  int size;

 public:
  // Default constructor
  Person() {
    size = 1;
    name = (char*)malloc(sizeof(char));
    name[0] = '\0';
  }

  // Parameterized constructor
  Person(const char* n) {
    size = strlen(n);
    name = (char*)malloc(sizeof(char) * size + 1);
    strcpy(name, n);
  }

  // Copy constructor - deep copy
  Person(const Person& p) {
    size = p.size;
    name = (char*)malloc(sizeof(char) * size + 1);
    strcpy(name, p.name);
  }

  // Assignment operator overloading
  Person& operator=(const Person& p) {
    if (this == &p) {
      return *this;
    }
    free(name);
    size = p.size;
    name = (char*)malloc(sizeof(char) * size + 1);
    strcpy(name, p.name);
    return *this;
  }

  // Update name
  void updateName(const char* n) {
    free(name);
    size = strlen(n);
    name = (char*)malloc(sizeof(char) * size + 1);
    strcpy(name, n);
  }

  // Friend function for output
  friend void operator<<(ostream& o, const Person& p) {
    o << "Name : " << p.name << endl;
    o << "Size : " << p.size << endl;
    o << "Location of name: " << &(p.name) << endl;  // Memory address of string
  }

  // Destructor
  ~Person() {
    if (name)
      free(name);
  }
};

int main() {
  cout << "p1\n";
  Person p1("ashutosh");
  cout << p1;

  cout << "p2\n";
  Person p2 = p1;
  cout << p2;

  cout << "\nAFTER UPDATING\n";
  p1.updateName("newname");

  cout << "p1\n";
  cout << p1;
  cout << "p2\n";
  cout << p2;

  cout << "\nOVERLOADING OF '='\n";

  Person p3, p5("jagriti");
  p3 = p2;

  p5 = p5;  // Self-assignment test
  cout << p3;
  cout << p5;

  p3 = p1 = p2;  // Chaining assignment
  cout << p3;
  cout << p1;
  cout << p2;

  return 0;
}
