// Demonstrate unordered_multimap
#include <bits/stdc++.h>
using namespace std;

int main() {
  // Initialize an unordered_multimap with duplicate keys
  unordered_multimap<string, int> m{
      {"ashutosh", 100},
      {"ash", 200},
      {"john", 300},
      {"john", 400},
  };

  // Iterate and display elements
  cout << "Unordered Multimap Contents:\n";
  for (const auto& entry : m) {
    cout << "Key: " << entry.first << ", Value: " << entry.second << endl;
  }

  return 0;
}