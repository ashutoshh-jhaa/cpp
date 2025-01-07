// wap to find largest of three numbers using class
#include <iostream>
using namespace std;

class LargestNumber {
 private:
  int num1, num2, num3, largest;

 public:
  // Setter
  void setNum(int n1, int n2, int n3) {
    num1 = n1;
    num2 = n2;
    num3 = n3;
  }

  // Getters
  int getNum1() { return num1; }
  int getNum2() { return num2; }
  int getNum3() { return num3; }
  int getLargest() { return largest; }

  // Find Largest
  void findLargest() {
    largest = (num1 > num2) ? ((num1 > num3) ? num1 : num3)
                            : ((num2 > num3) ? num2 : num3);
  }
};

int main() {
  LargestNumber l1;

  // Set Numbers
  l1.setNum(1, 2, 4);

  // Find Largest
  l1.findLargest();

  // Output Result
  cout << "Largest of " << l1.getNum1() << ", " << l1.getNum2() << ", "
       << l1.getNum3() << " is: " << l1.getLargest() << endl;

  return 0;
}
