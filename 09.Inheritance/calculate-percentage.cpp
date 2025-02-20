/*
write a cpp program to calculate percentage of students using multi-level
inheritance. Accept the marks of three subjects in base class. A class will be
derived from the base class above which will include a function to calculate the
total marks, followed by another class which will find the percentage from the
given marks
*/
#include <iostream>
using namespace std;

class Marks {
 protected:
  float subject[3];

 public:
  void setMarks() {
    cout << "Enter Marks : " << endl;

    cout << "Maths : ";
    cin >> subject[0];

    cout << "Physics : ";
    cin >> subject[1];

    cout << "Chemistry : ";
    cin >> subject[2];
  }
};

class TotalMarks : public Marks {
 protected:
  float total;

 public:
  void totalMarks() { total = subject[0] + subject[1] + subject[2]; }
};

class Percentage : public TotalMarks {
 protected:
  float percentage;

 public:
  void calculatePercentage() { percentage = (total / 300) * 100; }

  void displayResult() {
    cout << "\nTotal Marks : " << total << "\n"
         << "Percentage : " << percentage << endl;
  }
};

int main() {
  Percentage p;

  p.setMarks();
  p.totalMarks();
  p.calculatePercentage();
  p.displayResult();
}