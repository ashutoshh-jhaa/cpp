#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

int main() {
  vector<int> arr;

  // Check if the vector is initially empty
  if (arr.empty()) {
    cout << "Array is empty" << endl;
  }

  // Adding elements to the vector
  arr.push_back(4);
  arr.push_back(23);
  arr.push_back(99);

  // Display elements using at() for bounds checking
  cout << "Vector elements:" << endl;
  for (int i = 0; i < arr.size(); i++) {
    cout << "Value: " << arr.at(i) << endl;
  }

  // Remove the last element
  arr.pop_back();

  // Display size and capacity before shrink_to_fit()
  cout << "\nSize of the vector: " << arr.size() << endl;
  cout << "Capacity of the vector: " << arr.capacity() << endl;

  // Reduce capacity to fit current size
  cout << "\nAfter shrink_to_fit:" << endl;
  arr.shrink_to_fit();
  cout << "Size of the vector: " << arr.size() << endl;
  cout << "Capacity of the vector: " << arr.capacity() << endl;

  // Using an iterator to traverse the vector
  arr.push_back(99);
  arr.push_back(38);

  cout << "\nIterating using an iterator (Approach 1):" << endl;
  vector<int>::iterator itr;
  for (itr = arr.begin(); itr != arr.end(); itr++) {
    cout << "Value: " << *(itr) << endl;
  }

  cout << "\nIterating using an iterator with indexing (Approach 2):" << endl;
  itr = arr.begin();
  for (int i = 0; i < arr.size(); i++) {
    cout << "Value: " << *(itr + i) << endl;
  }

  // Swapping vectors
  vector<int> newArr = {1, 2, 3};

  cout << "\nNew Array before swapping:" << endl;
  itr = newArr.begin();
  for (int i = 0; i < newArr.size(); i++) {
    cout << "Value: " << *(itr + i) << endl;
  }

  cout << "\nSwapping arrays..." << endl;
  newArr.swap(arr);

  cout << "\nNew Array after swapping:" << endl;
  itr = newArr.begin();
  for (int i = 0; i < newArr.size(); i++) {
    cout << "Value: " << *(itr + i) << endl;
  }

  cout << "\nOriginal Array after swapping:" << endl;
  itr = arr.begin();
  for (int i = 0; i < arr.size(); i++) {
    cout << "Value: " << *(itr + i) << endl;
  }

  // Assigning a value to all elements of a vector
  vector<int> arr1;
  arr1.assign(5, 1);  // Fill arr1 with five elements, all set to 1

  cout << "\nAssigned values in arr1:" << endl;
  itr = arr1.begin();
  for (int i = 0; i < arr1.size(); i++) {
    cout << "Value: " << *(itr + i) << endl;
  }

  return 0;
}