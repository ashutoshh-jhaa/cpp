/*
create a class distance having instance variable member variables feet and
inches create default constructor and parameterized constructor for them also
overload () to take 3 arguments a,b,c and set feet = a+b+5 and inches = a+b+15;
*/
#include <iostream>
using namespace std;

class Distance {
 private:
  int feet, inch;

 public:
  Distance() {}

  Distance(int f, int i) {
    feet = f;
    inch = i;
  }

  // Overloaded function call operator to set feet and inch based on input
  void operator()(int a, int b, int c) {
    feet = a + b + 5;
    inch = a + c + 15;
  }

  // Function to display the current values of feet and inches
  void display() {
    cout << feet << " feet" << endl;
    cout << inch << " inches" << endl;
  }

  //() operator must a member function thus this won't work
  // friend void operator()(Distance d, int a, int b, int c);
};
// void operator()(Distance d, int a, int b, int c) {
//   d.feet = a + b + 5;
//   d.inch = a + c + 15;
// }

int main() {
  Distance d1(23, 4);

  d1(1, 2, 3);

  d1.display();

  // operator()(d1, 2, 3, 4);  // thus this won't work

  return 0;
}
