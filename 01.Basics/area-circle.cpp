#include <iostream>
using namespace std;
int main() {
  float radius;
  cout << "Enter the value of Radius";
  cin >> radius;

  // area
  cout << "Area of circle with radius " << radius << " : "
       << 3.14 * radius * radius;
}