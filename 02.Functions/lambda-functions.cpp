#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
 * Lambda functions in C++
 * -----------------------
 * - Also known as *anonymous functions* because they have no name.
 * - Useful for defining short, inline functions without needing to declare them
 * elsewhere.
 * - A lambda can optionally capture variables from its surrounding scope
 * (closure property).
 * - [ ]   → captures nothing (cannot access outer variables)
 * - [&]  → captures all outer variables by reference
 * - [=]  → captures all outer variables by value (read-only by default)
 * - [x]  → captures only variable x by value
 * - [&x] → captures only variable x by reference
 * - [=, &x] → capture all by value except x (by reference)
 * - [&, x]  → capture all by reference except x (by value)
 *
 * Technical notes:
 * - Each lambda is actually an *object* of a unique, compiler-generated class
 * type.
 * - The compiler determines this type at compile time — it’s unnamed and
 * unpredictable.
 * - You can control the return type explicitly using the `->` syntax, but if
 * omitted, the compiler automatically deduces it during compilation.
 */

class MyNumbers {
public:
  vector<int> my_vector;

  MyNumbers(int a, int b, int c, int d, int e) {
    my_vector.push_back(a);
    my_vector.push_back(b);
    my_vector.push_back(c);
    my_vector.push_back(d);
    my_vector.push_back(e);
  }
};

int main() {
  MyNumbers mn(12, 4, 38, 49, 29);

  cout << "----- BEFORE SORTING -----\n";
  for (int i : mn.my_vector)
    cout << i << " ";

  // Sorting in descending order using a lambda function.
  sort(mn.my_vector.begin(), mn.my_vector.end(),
       [](int a, int b) { return b < a; });

  cout << "\n----- AFTER SORTING -----\n";
  for (int i : mn.my_vector)
    cout << i << " ";

  return 0;
}
