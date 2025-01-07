// define a class Time to represent time (like 3hr 45min 20sec)
#include <iostream>
using namespace std;

class Time {
 private:
  int hours, minutes, seconds;

 public:
  void set(int h, int m, int s) {
    if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
      hours = h;
      minutes = m;
      seconds = s;
    } else {
      cout << "Invalid time values provided!" << endl;
      hours = minutes = seconds = 0;
    }
  }

  // Getters
  int getHours() { return hours; }
  int getMinutes() { return minutes; }
  int getSeconds() { return seconds; }

  // Display time in a formatted way
  void displayTime() {
    cout << hours << " hr " << minutes << " min " << seconds << " sec " << endl;
  }
};

int main() {
  Time t1, t2, t3;

  // Set values
  t1.set(4, 29, 23);
  t2.set(2, 39, 53);
  t3.set(12, 2, 3);

  // Get and display values
  t1.displayTime();
  t2.displayTime();
  t3.displayTime();

  cout << "T2 Time: " << t2.getHours() << " hrs " << t2.getMinutes() << " mins "
       << t2.getSeconds() << " secs" << endl;

  return 0;
}
