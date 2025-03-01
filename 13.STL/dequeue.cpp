#include <deque>
#include <iostream>
using namespace std;

int main() {
  deque<int> dq;

  dq.push_back(1);
  dq.push_back(2);
  dq.push_front(0);

  // Print elements
  for (auto dit = dq.begin(); dit != dq.end(); ++dit) {
    cout << *dit << "\t";
  }
  cout << "\n";

  cout << "Size: " << dq.size() << endl;
  cout << "Max size: " << dq.max_size() << endl;

  // Ensure safe access before using at()
  if (dq.size() > 2) {
    cout << "Value at index 2: " << dq.at(2) << endl;
  } else {
    cout << "Index 2 is out of range!" << endl;
  }

  // Remove elements
  dq.pop_back();
  dq.pop_front();

  cout << "Size after pop: " << dq.size() << endl;

  // Ensure deque is not empty before accessing back()
  if (!dq.empty()) {
    cout << "Last element: " << dq.back() << endl;
  } else {
    cout << "Deque is empty!" << endl;
  }

  return 0;
}