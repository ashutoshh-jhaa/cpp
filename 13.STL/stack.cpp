#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<int> s;

  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);

  // Print and pop all elements
  while (!s.empty()) {
    cout << s.top() << "\n";
    s.pop();
  }

  // Push a new element
  s.push(823);

  // Print size and top element safely
  cout << s.size() << "\n";
  if (!s.empty()) {
    cout << s.top() << "\n";
  }

  return 0;
}