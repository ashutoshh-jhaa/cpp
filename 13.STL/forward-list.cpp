// singly linked lists
#include <forward_list>
#include <iostream>
using namespace std;

int main() {
  forward_list<int> fl;

  // Method one to initialize
  fl.assign({1, 2, 3, 5, 6, 7});

  forward_list<int>::iterator fli;

  for (fli = fl.begin(); fli != fl.end(); fli++) {
    cout << *fli << "\t";
  }

  // Method two
  fl.assign(3, 7);

  cout << "\n";
  for (fli = fl.begin(); fli != fl.end(); fli++) {
    cout << *fli << "\t";
  }
  cout << endl;

  forward_list<int> l1;

  // Assigning elements from fl to l1
  l1.assign(fl.begin(), fl.end());

  for (fli = l1.begin(); fli != l1.end(); fli++) {
    // Commented-out print statement remains
    // cout << *fli << "\t";
  }

  // Insert elements at the beginning
  l1.insert_after(l1.before_begin(), {1, 2, 3, 4, 5});

  auto it = l1.before_begin();
  for (fli = l1.begin(); fli != l1.end(); fli++) {
    it = fli;  // Track last valid position
  }

  // Insert 99 after the last element
  l1.insert_after(it, {99});

  for (fli = l1.begin(); fli != l1.end(); fli++) {
    cout << *fli << "\t";
  }
  cout << endl;

  return 0;
}