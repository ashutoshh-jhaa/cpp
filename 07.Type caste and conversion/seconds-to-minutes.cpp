/*
create a class Time which takes duration in seconds and then take duration(int)
in minutes and convert the duration to Time
int main(){
    int duration;
    cout<<"enter duration in minutes";
    cin>>duration;
    Time t1=duration;
    t1.display();
    return 0;
  }
*/
#include <iostream>
using namespace std;

class Time {
 private:
  int seconds;

 public:
  Time(int m) : seconds(m * 60) {}
  void display() { cout << "seconds : " << seconds << endl; }
};

int main() {
  int duration;
  cout << "Enter duration in minutes :\n";
  cin >> duration;

  Time t1 = duration;
  t1.display();
  return 0;
}