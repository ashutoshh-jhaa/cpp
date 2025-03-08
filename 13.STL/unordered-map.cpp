// Demostrate unordered map
#include <bits/stdc++.h>
using namespace std;

int main() {
  unordered_map<string, int> m;

  // Insert key-value pairs
  m["ashutosh"] = 100;
  m["john"] = 200;
  m["faiz"] = 300;

  // Updates the value of "john" (unordered_map allows value modification)
  m["john"] = 400;

  // Iterate and display elements
  cout << "Unordered Map Contents:\n";
  for (const auto& entry : m) {
    cout << "Key: " << entry.first << ", Value: " << entry.second << endl;
  }

  return 0;
}