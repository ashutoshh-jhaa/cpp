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

  friend ostream& operator<<(ostream& o, const Time& t);
  friend bool operator>>(istream& i, Time& t);
};

ostream& operator<<(ostream& o, const Time& t) {
  o << t.hour << ":" << t.minute << ":" << t.second;
  return o;
}

bool operator>>(istream& i, Time& t) {
  cout << "Enter Hours (0-23): ";
  i >> t.hour;
  if (t.hour < 0 || t.hour >= 24) {
    return false;
  }
  cout << "Enter Minutes (0-59): ";
  i >> t.minute;
  if (t.minute < 0 || t.minute >= 60) {
    return false;
  }
  cout << "Enter Seconds (0-59): ";
  i >> t.second;
  if (t.second < 0 || t.second >= 60) {
    return false;
  }

  // Normalize time
  t.minute += t.second / 60;
  t.second %= 60;
  t.hour += t.minute / 60;
  t.minute %= 60;

  return true;
}

int main() {
  Time t1(2, 42, 15), t2(8, 55, 32), t3(8, 55, 32);
  Time t4, t5;

  cout << "Enter first Time:\n";
  if (!(cin >> t4)) {
    cout << "\nInvalid Time\n";
    return 0;
  }
  cout << "Normalized Time: " << t4 << endl;

  cout << "\nEnter second Time:\n";
  if (!(cin >> t5)) {
    cout << "\nInvalid Time\n";
    return 0;
  }
  cout << "Normalized Time: " << t5 << endl;

  // Compare times
  cout << ((t4 == t5) ? "Times are the same" : "Times are different") << endl;

  return 0;
}
