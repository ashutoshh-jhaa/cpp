#include <array>
#include <iostream>
#include <tuple>
using namespace std;

int main() {
  array<int, 5> arr = {1, 2, 3, 4, 5};
  array<int, 5> newarr = {0, 0, 0, 0, 0};
  array<int, 5> arr1;

  // Accessing elements
  cout << "arr.at(3) : " << arr.at(3)
       << endl;  // Safe access with bounds checking
  cout << "arr[0] : " << arr[0]
       << endl;  // Direct access without bounds checking
  cout << "arr.front() : " << arr.front() << endl;
  cout << "arr.back() : " << arr.back() << endl;

  // Getting iterators (not directly useful when printing)
  cout << "arr.begin() : " << arr.begin() << endl;
  cout << "arr.end() : " << arr.end() << endl;

  // Size-related methods
  cout << "arr.size() : " << arr.size() << endl;
  cout << "arr.max_size() : " << arr.max_size() << endl;
  cout << "arr1.empty() : " << arr1.empty() << endl;

  // Filling the array with a single value
  arr.fill(23);

  // Swapping contents of two arrays (must have the same size)
  arr.swap(newarr);

  // Accessing elements using std::get (requires <tuple>)
  cout << get<0>(arr) << endl;
}
