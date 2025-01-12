// wap to overload post-increment operator
#include <iostream>
using namespace std;

class Item {
 private:
  int number;

 public:
  Item() {}
  Item(int a) { number = a; }
  Item(const Item& i) { number = i.number; }

  // pre-increment
  Item operator++() {
    Item temp;
    temp.number = ++number;
    return temp;
  }
  // post-increment
  Item operator++(int dummy) {
    Item temp;
    temp.number = number;
    ++number;
    return temp;
  }

  int getValue() { return number; }
  void display() { cout << number; }
};

int main() {
  Item i1, i2(23);
  // pre-increment operator
  i1 = ++i2;
  cout << i2.getValue();

  // post-increment operator
  (i1++).display();
  cout << i1.getValue();
}