// wap to overload greater than operator
#include <iostream>
using namespace std;

class Time {
 private:
  int hour, minutes;

 public:
  Time() {}

  Time(int h, int m) {
    hour = h;
    minutes = m;
  }

  bool operator>(const Time& p) const {
    return (hour * 60 + minutes) > (p.hour * 60 + p.minutes);
  }

  friend ostream& operator<<(ostream& o, const Time& p);
};

ostream& operator<<(ostream& o, const Time& p) {
  o << "{ hour: " << p.hour << ", minutes: " << p.minutes << " }";
  return o;
}

int main() {
  Time t1(3, 1), t2(5, 53);

  cout << "t1 " << t1 << endl;
  cout << "t2 " << t2 << endl;

  if (t1 > t2)
    cout << "t1 is greater: " << t1 << endl;
  else
    cout << "t2 is greater: " << t2 << endl;

  return 0;
}
