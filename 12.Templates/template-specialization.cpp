#include "iostream"
using namespace std;

/*
 * Example: Template Specialization in C++
 * ---------------------------------------
 * Template specialization lets us define custom behavior for specific data
 * types while still using the same generic template interface.
 *
 * This example demonstrates full specializations of a Traits template
 * for two enum classes: `Color` and `Fruit`.
 *
 * Reference:
 * https://www.hackerrank.com/challenges/cpp-class-template-specialization/problem
 */

enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

// primary template (declaration only)
template <typename T> struct Traits;

// specialized template for `Color`
template <> struct Traits<Color> {

  // static function allows usage without creating an object
  static string name(int choice) {
    switch (choice) {
    case 0:
      return "red";
    case 1:
      return "green";
    case 2:
      return "orange";
    default:
      return "unknown";
    }
  }
};

// specialized template for `Fruit`
template <> struct Traits<Fruit> {
  static string name(int choice) {
    switch (choice) {
    case 0:
      return "apple";
    case 1:
      return "orange";
    case 2:
      return "pear";
    default:
      return "unknown";
    }
  }
};

int main() {
  // t counts the number of test cases
  int t = 0;
  cin >> t;

  for (auto i = 0; i < t; i++) {
    int index1;
    cin >> index1;
    int index2;
    cin >> index2;
    cout << Traits<Color>::name(index1) << endl;
    cout << Traits<Fruit>::name(index2) << endl;
  }
}
