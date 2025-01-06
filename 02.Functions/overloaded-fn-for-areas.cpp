// create overloaded functions to find areas of triangle,circle,rectangle
#include <iostream>
using namespace std;

// for circle
float area(float radius) {
  return 3.14 * radius * radius;
}

// for rectangle
float area(float length, float breadth) {
  return length * breadth;
}

// for triangle
float area(float base, float height, char type) {
  return 0.5 * base * height;
}

int main() {
  float radius, length, breadth, base, height;

  cout << "Enter radius of the circle: ";
  cin >> radius;
  cout << "Area of Circle: " << area(radius) << endl;

  cout << "Enter length and breadth of the rectangle: ";
  cin >> length >> breadth;
  cout << "Area of Rectangle: " << area(length, breadth) << endl;

  cout << "Enter base and height of the triangle: ";
  cin >> base >> height;
  cout << "Area of Triangle: " << area(base, height, 't') << endl;

  return 0;
}