#include <iostream>
#include <queue>
using namespace std;

int main() {
  priority_queue<int> q;
  q.push(23);
  q.push(88);
  q.push(28);
  q.push(1);

  // also called max priority queue as max is priorotized
  while (!q.empty()) {
    cout << q.top() << "\n";
    q.pop();
  }

  q.push(99);
  cout << "size : " << q.size() << endl;

  // min priority queue prioritizes min value
  priority_queue<int, vector<int>, greater<int>> qq;
  qq.push(23);
  qq.push(88);
  qq.push(28);
  qq.push(1);

  while (!qq.empty()) {
    cout << qq.top() << "\n";
    qq.pop();
  }
}
