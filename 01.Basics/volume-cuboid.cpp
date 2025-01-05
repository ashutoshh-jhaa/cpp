#include <iostream>
using namespace std;
int main() {
  float len, breadth, height;
  cout << "Enter Length : ";
  cin >> len;

  cout << "Enter Breadth : ";
  cin >> breadth;

  cout << "Enter height : ";
  cin >> height;

  float vol = len * breadth * height;

  cout << "Volume of Cuboid : " << vol;
}