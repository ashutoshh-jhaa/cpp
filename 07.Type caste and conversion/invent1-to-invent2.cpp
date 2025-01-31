/*
  create two classes Invent1 and Invent2 and also add necessary costructors in
  it now add functions to support Invent1 to float and Invent1 to Invent2 type
  example:-
    int main(){
      Invent1 x(3,4);
      Invent2 y;
      float z;
      z=x;  //Invent1 to float
      y=x;  //Invent1 to Invent2
      return 0;
    }
*/

#include <iostream>
using namespace std;

class Invent1 {
 private:
  int a, b;

 public:
  Invent1() { cout << "dc Invent1\n"; }

  Invent1(float i) {
    cout << "pc (1-p)\n";
    a = b = i;
  }

  Invent1(int x, int y) : a(x), b(y) { cout << "pc Invent1\n"; }

  operator float() {
    cout << "float Invent1\n";
    return a;
  }

  void display() {
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;
  }

  float getValue() {
    cout << "getValue Invent1\n";
    return a;
  }
};

class Invent2 {
 private:
  int c;

 public:
  Invent2() { cout << "dc Invent2\n"; }

  Invent2(int a) : c(a) { cout << "pc Invent2\n"; }

  Invent2(Invent1 i) {
    cout << "conversion constructor Invent2\n";
    c = i.getValue();
  }

  void display() { cout << "c : " << c << endl; }
};

int main() {
  Invent1 i1(2, 3);
  Invent2 i2;

  float x;
  x = i1;  // non-primitive to primitive
  cout << x << endl;

  i2 = i1;
  i2.display();
  return 0;
}
