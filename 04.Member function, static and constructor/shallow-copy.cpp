// demostrate shallow copy
#include <iostream>
using namespace std;

class People {
 public:
  int* value;

  People(int v) {
    value = (int*)malloc(sizeof(int));
    *value = v;
  }

  // Shallow Copy Constructor: Copies the pointer, not the data
  People(People& p) {
    // Copies the address stored in the pointer from 'p' to the new object
    // Both objects now share the same memory for 'value'
    value = p.value;
  }

  // Destructor: Frees the allocated memory
  ~People() { free(value); }

  void display() {
    cout << "Value: " << *value << endl;
    cout << "Memory Address: " << value << endl;
  }
};

int main() {
  People p1(23);
  People p2 = p1;

  // Modify the value using 'p2'
  *p2.value = 2;  // Changes the shared memory, affecting both 'p1' and 'p2'

  cout << "p1:" << endl;
  p1.display();
  cout << "p2:" << endl;
  p2.display();

  return 0;
}
