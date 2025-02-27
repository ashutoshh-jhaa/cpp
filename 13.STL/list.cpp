// Doubly linked list
#include <iostream>
#include <list>

using namespace std;

int main() {
  list<int> l;

  // Insert elements at the back
  for (int i = 0; i < 5; i++) {
    l.push_back(i * 100);
  }

  // Display the list
  cout << "Initial list:" << endl;
  for (list<int>::iterator li = l.begin(); li != l.end(); li++) {
    cout << *li << " ";
  }
  cout << endl;

  // Insert element at the front
  l.push_front(99);
  cout << "\nAfter push_front(99):" << endl;
  for (list<int>::iterator li = l.begin(); li != l.end(); li++) {
    cout << *li << " ";
  }
  cout << endl;

  // Reverse the list
  l.reverse();
  cout << "\nAfter reversing:" << endl;
  for (list<int>::iterator li = l.begin(); li != l.end(); li++) {
    cout << *li << " ";
  }
  cout << endl;

  // Sort the list
  l.sort();
  cout << "\nAfter sorting:" << endl;
  for (list<int>::iterator li = l.begin(); li != l.end(); li++) {
    cout << *li << " ";
  }
  cout << endl;

  // Pop last and first elements
  l.pop_back();
  l.pop_front();
  cout << "\nAfter pop_back() and pop_front():" << endl;
  for (list<int>::iterator li = l.begin(); li != l.end(); li++) {
    cout << *li << " ";
  }
  cout << endl;

  // Remove a specific element (400)
  l.remove(400);
  cout << "\nAfter removing 400 (if present):" << endl;
  for (list<int>::iterator li = l.begin(); li != l.end(); li++) {
    cout << *li << " ";
  }
  cout << endl;

  return 0;
}