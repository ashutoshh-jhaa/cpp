/*
create a file stduent-record.txt and store details like roll number, name, age
and stream
  - we should be able to add new student details
  - search student
  - print all records
  - update records
  - delete records
*/

#include <fstream>
#include <ios>
#include <iostream>
#include <string>
using namespace std;

void addNewStudent();
void displayAllStudents();

class Student {
 private:
  string name, stream;
  int age, roll;

 public:
  Student() {
    cin.ignore();
    cout << "Enter your Name : ";
    getline(cin, name);
    cout << "Enter your Stream : ";
    getline(cin, stream);

    cout << "Enter your Age : ";
    cin >> age;
    cout << "Enter your Roll-Number : ";
    cin >> roll;
  }

  string getName() { return name; }
  string getStream() { return stream; }
  int getAge() { return age; }
  int getRoll() { return roll; }
};
int main() {
  while (true) {
    cout << "1.Add new Student : \n";
    cout << "2.Update Student : \n";
    cout << "3.Delete Student : \n";
    cout << "4.Search Student : \n";
    cout << "5.Display all Student : \n";
    cout << "6.Exit : \n";

    int choice;
    cin >> choice;

    switch (choice) {
      case (1): {
        // add new student
        addNewStudent();
        break;
      }
      case (2): {
        break;
      }
      case (3): {
        break;
      }
      case (4): {
        break;
      }
      case (5): {
        // display all students
        displayAllStudents();
        break;
      }
      case (6): {
        return 0;
        break;
      }
      default: {
        break;
      }
    }
  }
}

// add new students
void addNewStudent() {
  ofstream fout("./student-record.txt", ios::app);

  if (!fout) {
    cout << "something went wrong ";
  } else {
    Student s1;
    fout << "Name : " << s1.getName() << endl
         << "Stream : " << s1.getStream() << endl
         << "Age : " << s1.getAge() << endl
         << "Roll-Number : " << s1.getRoll() << endl
         << endl;
  }
  fout.close();
}

// display all students
void displayAllStudents() {
  ifstream fin;
  fin.open("./student-record.txt");
  string line;
  while (fin) {
    getline(fin, line);
    cout << line << endl;
  }
  fin.close();
}
