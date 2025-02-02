// wap to demonstrate try catch and throw in a program
#include <iostream>
using namespace std;

int main() {
  cout << "Enter two Numbers: ";
  int a{}, b{};
  cin >> a >> b;

  int result;

  // Using try-catch block to handle potential errors during division
  try {
    if (b == 0) {
      throw "Error: Division by zero is not allowed";  // Throw an exception if
                                                       // b is zero
    }

    if (b < 0) {
      throw "Error: 'b' cannot be negative";  // Throw an exception if b is
                                              // negative
    }

    if (b == 1) {
      throw 0;  // Throw a specific exception (integer in this case) for b == 1
    }

    // If no exceptions are thrown, perform the division
    result = a / b;

  } catch (const char* str) {
    // Catch the exception if it's a string (for division by zero or negative
    // 'b')
    cout << str << endl;
    return 0;

  } catch (int e) {
    // Catch the exception if it's an integer (for b == 1)
    cout << "Special case: b cannot be 1, error code: " << e << endl;
    return 0;

  } catch (...) {
    // Catch any other types of exceptions (catch-all)
    // The catch(...) block cannot access the exception itself
    // because it doesn't have a reference or variable for the exception
    cout << "An unexpected error occurred." << endl;
    return 0;
  }

  // If no exceptions were thrown, print the result of the division
  cout << "Result: " << result << endl;

  return 0;
}
