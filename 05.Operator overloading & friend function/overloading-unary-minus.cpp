// wap to overload - operator to take three positive numbers from user and
// convert them into negative numbers
#include <iostream>
using namespace std;
class Numbers {
 private:
  int x, y, z;

 public:
  void setNumbers() {
    cout << "Enter First Number : ";
    cin >> x;
    cout << "Enter Second Number : ";
    cin >> y;
    cout << "Enter Third Number : ";
    cin >> z;
  }
  void operator-() {
    x = -x;
    y = -y;
    z = -z;
  }
  void display() {
    cout << "x : " << x << "\ny : " << y << "\nz : " << z << endl;
  }
};
int main() {
  Numbers n;
  n.setNumbers();
  n.display();
  -n;
  n.display();
}