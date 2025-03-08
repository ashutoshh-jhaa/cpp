// Demostrate unordered set
#include <bits/stdc++.h>
using namespace std;

int main() {
  unordered_set<string> us = {"ashutosh", "john", "wick"};

  // Display elements (unordered, no duplicates)
  cout << "Unordered Set Contents:\n";
  for (const auto& elem : us) {
    cout << elem << endl;
  }

  // Check for key existence
  string key = "gustavo";
  if (us.find(key) == us.end()) {
    cout << "Key not found\n";
  } else {
    cout << "Key found\n";
  }

  return 0;
}