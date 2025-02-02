/*
create two classes Time and Minute and add required getter and setter including
constructor. Now you need to type cast Time object to Minute to fetch the minute
from Time and display it

int main(){
  Time t1(2,40);
  t1.display();
  Minute m1;
  m1.display();
  m1=t1;
  t1.display()
  m1.display();
  return 0;
}
*/

#include <iostream>
using namespace std;

class Time {
 private:
  int hours, minutes;

 public:
  Time() : hours(0), minutes(0) { cout << "time dc\n"; }

  Time(int h, int m) : hours(h), minutes(m) { cout << "time pc\n"; }

  void display() const {
    cout << "Hours: " << hours << ", Minutes: " << minutes << endl;
  }

  operator int() const {
    cout << "Time int()\n";
    return hours * 60 + minutes;
  }
};

class Minute {
 private:
  int minutes;

 public:
  Minute() : minutes(0) { cout << "minute dc\n"; }

  Minute(int m) : minutes(m) { cout << "minutes pc \n"; }

  void display() const { cout << "Minutes: " << minutes << endl; }
};

int main() {
  Time t1(2, 40);
  t1.display();

  Minute m1;
  m1.display();

  // Convert Time to int (total minutes) and assign to Minute
  // 1. `t1` is converted to an int using `operator int()` (prints conversion
  // message)
  // 2. The `Minute(int)` constructor is called to create a temporary object
  // 3. The default assignment operator assigns the value to `m1`
  m1 = (int)t1;

  // Display final values
  t1.display();
  m1.display();

  return 0;
}
