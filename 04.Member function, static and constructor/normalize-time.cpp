// wap to diplay, add and normalize time
#include <iostream>
using namespace std;
class Time {
 private:
  int hours, minutes, seconds;

 public:
  Time() {};
  Time(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;
  }
  // Normalize time values
  void normalize() {
    minutes += seconds / 60;
    seconds %= 60;

    hours += minutes / 60;
    minutes %= 60;
  }

  // Overloaded + operator for adding two Time objects
  Time operator+(Time t) {
    Time temp;
    temp.hours = hours + t.hours;
    temp.minutes = minutes + t.minutes;
    temp.seconds = seconds + t.seconds;
    temp.normalize();  // Normalize the result
    return temp;
  }

  // Display time in hours, minutes, and seconds
  void display() const {
    cout << hours << " hours " << minutes << " minutes " << seconds
         << " seconds" << endl;
  }
};

int main() {
  Time t1(2, 50, 125), t2(5, 100, 500), t3;

  cout << "Time one: \n";
  t1.display();

  cout << "Time two: \n";
  t2.display();

  // Add times and display the result
  t3 = t1 + t2;
  cout << "Sum of time one and time two: \n";
  t3.display();

  return 0;
}