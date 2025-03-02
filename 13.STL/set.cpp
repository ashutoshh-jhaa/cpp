#include <iostream>
#include <set>
using namespace std;

int main() {
  // for ascending order
  set<int> s;
  // for descending order
  // set<int, greater<int>> s;

  s.insert(23);
  s.insert(1);
  s.insert(2);
  s.insert(3);
  // this won't be added as set contains only unique elements
  s.insert(3);

  set<int>::iterator sitr;

  // prints in ascending order
  for (sitr = s.begin(); sitr != s.end(); sitr++) {
    cout << *sitr << endl;
  }

  set<int> s1(s.begin(), s.end());
  for (sitr = s1.begin(); sitr != s1.end(); sitr++) {
    cout << *sitr << endl;
  }

  multiset<int> s2;
  s2.insert(23);
  s2.insert(1);
  s2.insert(2);
  s2.insert(3);
  // multiset allows duplicate entries
  s2.insert(3);

  multiset<int>::iterator x;

  for (x = s2.begin(); x != s2.end(); x++) {
    cout << *x << endl;
  }
}