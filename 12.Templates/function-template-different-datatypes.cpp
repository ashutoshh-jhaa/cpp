#include <iostream>
using namespace std;

// Function template for addition that supports different return and parameter
// types. The default return type is `int`, and the second parameter type is
// also defaulted to `int`.
template <typename R = int, typename P1, typename P2 = int>
R add(P1 a, P2 b) {
  return a + b;
};

// Function template for addition where the return type is always `int`.
// It takes two parameters of different types.
template <typename P1, typename P2>
int fun(P1 p1, P2 p2) {
  return p1 + p2;
}

int main() {
  cout << "Sum : " << add<float, float, int>(23.4, 8) << endl;
  cout << "Sum : " << add<int, int, int>(4, 8) << endl;

  // If only one type is specified, it is treated as the return type,
  // and the parameters default to int.
  cout << "Sum : " << add<int>(4, 8) << endl;

  // Return type is specified as float, parameters default to int.
  cout << "Sum : " << add<float>(3, 8) << endl;

  // Implicit template deduction: return type is int (default), parameter types
  // are deduced.
  cout << "Sum : " << add(23, 53) << endl;

  // Calls fun() with int arguments, return type is always int.
  cout << fun(12, 423);
}