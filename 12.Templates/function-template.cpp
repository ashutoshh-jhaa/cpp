// demonstrate use of function templates(generic functions)
#include <iostream>
using namespace std;

// Define a function template to perform addition
// 'T' is a placeholder for any data type (int, float, etc.)
template <typename T>
T add(T a, T b) {
  return a + b;
}

// Invalid: A template must be declared right before a function definition
// T newfun(T a, T b) {
//   return a + b;
// }

//  Correct: Function template declaration (template must be specified)
template <typename T>
T newfun1(T a, T b);

int main() {
  // Call the template function with integers
  cout << "Sum : " << add<int>(23, 49) << endl;

  // Call the template function with floating-point numbers
  cout << "Sum : " << add<float>(2.3, 4.9) << endl;

  // Calling newfun1 function template
  cout << "Sum using newfun1: " << newfun1<double>(5.1, 4.2) << endl;

  return 0;
}

// Function template definition (must have 'template <typename T>')
template <typename T>
T newfun1(T a, T b) {
  return a + b;
}