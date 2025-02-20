// add two numbers using single inheritance. Accept these two numbers from user
// and display the sum of both numbers in derived class

#include <iostream>
using namespace std;

class Base {
 protected:
  int a, b;

 public:
  Base(int x, int y) : a(x), b(y) {}
};

class Derived : public Base {
 private:
  int sum;

 public:
  Derived(int x, int y) : Base(x, y) { sum = a + b; }

  void display() { cout << "Sum : " << sum << endl; }
};

int main() {
  int num1, num2;
  cout << "Enter two numbers: ";
  cin >> num1 >> num2;

  Derived d(num1, num2);
  d.display();

  return 0;
}