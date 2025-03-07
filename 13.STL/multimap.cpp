// demostrate multimap
#include <iostream>
#include <map>

using namespace std;

int main() {
  // Declare a multimap with integer keys and values
  multimap<int, int> m;

  // Inserting elements using insert()
  m.insert({1, 10});
  m.insert({8, 0});
  m.insert({2, 20});

  // Another way to insert elements
  m.insert(pair<int, int>(89, 90));

  // Duplicate keys are allowed in multimap
  m.insert({2, 25});

  // Inserting elements using emplace() (more efficient than insert)
  m.emplace(3, 50);
  m.emplace(4, 100);

  // Updating a value requires erasing and reinserting
  m.erase(2);
  m.insert({2, 29});

  multimap<int, int>::iterator mi;

  // Display the multimap contents (keys are always sorted in ascending order)
  cout << "Multimap contents:\n";
  for (mi = m.begin(); mi != m.end(); mi++) {
    cout << mi->first << " : " << mi->second << endl;
  }

  return 0;
}