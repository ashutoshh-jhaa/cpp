// count the number of times a function has been called
#include <iostream>
using namespace std;
void fun1() {
  static int count = 0;
  count++;
  cout << count << endl;
}
int main() {
  fun1();
  fun1();
  fun1();
  fun1();
  fun1();
}