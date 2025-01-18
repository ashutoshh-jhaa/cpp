// wap to overload == (equality operator)
#include <iostream>
using namespace std;

class Time {
 private:
  int hour, minute, second;

 public:
  Time() {}

  Time(int h, int m, int s) {
    hour = h;
    minute = m;
    second = s;
  }

  // Overload == operator to compare two Time objects
  bool operator==(Time t) {
    return ((minute * 60 + hour * 3600 + second) ==
            (t.minute * 60 + t.hour * 3600 + t.second));
  }

  friend ostream& operator<<(ostream& o, Time t);
};

ostream& operator<<(ostream& o, Time t) {
  o << t.hour << ":" << t.minute << ":" << t.second << endl;
  return o;
}

int main() {
  Time t1(2, 42, 15), t2(8, 55, 32), t3(8, 55, 32);

  // Enable boolalpha to display true/false instead of 1/0 for boolean values
  // Disable with cout << noboolalpha; if needed
  cout << boolalpha;

  // Display Time objects
  cout << t1 << t2;

  // Compare times and display the result
  cout << "t1 == t2: " << (t1 == t2) << endl;  // false
  cout << "t2 == t3: " << (t2 == t3) << endl;  // true

  return 0;
}
