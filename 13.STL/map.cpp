// demostrate map
#include <iostream>
#include <map>

using namespace std;

int main() {
  // Declare a map with integer keys and values
  map<int, int> m;

  // Inserting elements using insert()
  m.insert({1, 10});
  m.insert({8, 0});
  m.insert({2, 20});

  // other way around
  m.insert(pair<int, int>(89, 90));

  // Duplicate keys are ignored
  m.insert({2, 25});  // No effect

  // Inserting elements using emplace() (more efficient than insert)
  m.emplace(3, 50);
  m.emplace(4, 100);

  // Alternative way to insert or update values using []
  m[9] = 200;
  m[9] = 300;  // Updates the value of key 9

  // Updating a value using erase + insert
  m.erase(2);
  m.insert({2, 29});

  map<int, int>::iterator mi;

  // Display the map contents (keys are always sorted in ascending order)
  cout << "Map contents:\n";
  for (mi = m.begin(); mi != m.end(); mi++) {
    cout << mi->first << " : " << mi->second << endl;
  }

  return 0;
}