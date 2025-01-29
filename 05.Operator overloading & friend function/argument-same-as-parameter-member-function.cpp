// make a class Complex and a member function with the name of parameters same
// as arguments
#include <iostream>
using namespace std;
class Complex {
 public:
  int real, img;

  void setData(int real, int img) {
    this->real = real;
    this->img = img;
  }
  void display() {
    cout << "real : " << real << endl;
    cout << "img : " << img << endl;
  }
};
int main() {
  Complex c1;
  c1.setData(24, 1);
  c1.display();
}