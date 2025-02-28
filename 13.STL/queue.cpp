#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue<int> q;

  q.push(23);
  q.push(88);
  q.push(28);
  q.push(1);

  // Print front element before processing
  cout << "Front: " << q.front() << endl;

  // Print and remove all elements
  while (!q.empty()) {
    cout << q.front() << "\n";
    q.pop();
  }

  // Push a new element after clearing the queue
  q.push(99);

  // Print size safely
  cout << "Size: " << q.size() << endl;

  // Ensure the queue is not empty before accessing front
  if (!q.empty()) {
    cout << "Front: " << q.front() << endl;
  }

  return 0;
}