// implement deep copy
#include <iostream>
using namespace std;

class Person {
 public:
  int* value;

  Person(int v) {
    value = (int*)malloc(sizeof(int));
    *value = v;
  }

  // Destructor: Frees the allocated memory
  ~Person() { free(value); }

  // Copy Constructor: Implements deep copy
  Person(Person& p) {
    value =
        (int*)malloc(sizeof(int));  // Allocate new memory for the copied object
    *value = *(p.value);
  }

  void display() {
    cout << "Value: " << *value << endl;
    cout << "Memory Address: " << value << endl;
  }
};

int main() {
  Person p1(12);
  Person p2 = p1;

  cout << "Initial values:" << endl;
  p1.display();
  p2.display();

  // Modify 'p2's value without affecting 'p1'
  *p2.value = 32;

  cout << "\nAfter modifying p2's value:" << endl;
  p1.display();
  p2.display();

  return 0;
}
