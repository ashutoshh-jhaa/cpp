// wap to reverse a number using the concepts of oop
#include <iostream>
using namespace std;

class ReverseNum {
 private:
  int num, reversed;

 public:
  // Setters and getters
  void setNum(int n) { num = n; }
  int getNum() const { return num; }
  int getReversed() const { return reversed; }

  // Method to find the reverse of the number
  void findReverse() {
    int temp = num;
    reversed = 0;
    while (temp != 0) {
      int remainder = temp % 10;
      reversed = reversed * 10 + remainder;
      temp /= 10;
    }
  }
};

int main() {
  ReverseNum r1;
  r1.setNum(2324);
  r1.findReverse();
  cout << "Number: " << r1.getNum() << endl;
  cout << "Reversed Number: " << r1.getReversed();
  return 0;
}
