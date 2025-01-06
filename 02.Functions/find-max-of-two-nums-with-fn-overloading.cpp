// Program to find the maximum of two numbers using function overloading
// Supports both integers and real numbers (float)
// Function overloading is based on function signatures, not return types

#include <iostream>
using namespace std;

int findMax(int a, int b) {
  return (a > b) ? a : b;
}

float findMax(float a, float b) {
  return (a > b) ? a : b;
}

int main() {
  char choice;
  cout << "Choose data type (i: integer, f: float): ";
  cin >> choice;

  if (choice == 'i') {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "Max: " << findMax(a, b) << endl;
  } else if (choice == 'f') {
    float a, b;
    cout << "Enter two real numbers: ";
    cin >> a >> b;
    cout << "Max: " << findMax(a, b) << endl;
  } else {
    cout << "Invalid choice!" << endl;
  }

  return 0;
}
