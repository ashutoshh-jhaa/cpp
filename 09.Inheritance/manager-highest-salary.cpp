/*
  write a cpp program to design a base class Person(name,address, phoneNumber)
  derive a class employee (eno,ename) from person,
  derive a class manager(designation, departmentName, basicSalary) from Employee
  write a menu driven program to
    a. accept all details of 'n' managers
    b. display manager having highest salary

*/

#include <iostream>
using namespace std;

class Person {
 protected:
  string name, address, phoneNumber;

 public:
  void setPersonDetails() {
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Phone Number: ";
    getline(cin, phoneNumber);
  }
};

class Employee : public Person {
 protected:
  unsigned int employeeId;

 public:
  void setEmployeeDetails() {
    cout << "Enter Employee ID: ";
    cin >> employeeId;
    cin.ignore();
    setPersonDetails();
  }

  string getEmployeeName() { return name; }
};

class Manager : public Employee {
 private:
  unsigned int salary;
  string designation, departmentName;

 public:
  void setDetails() {
    setEmployeeDetails();

    cout << "Enter Designation: ";
    getline(cin, designation);
    cout << "Enter Department Name: ";
    getline(cin, departmentName);
    cout << "Enter Salary: ";
    cin >> salary;
    cin.ignore();
  }

  int getSalary() { return salary; }
};

int main() {
  int n;
  cout << "How many managers do you want to enter? ";
  cin >> n;
  cin.ignore();

  Manager* m = new Manager[n];

  for (int i = 0; i < n; i++) {
    cout << "\nEnter details of Manager " << i + 1 << ":\n";
    cout << "-------------------------" << endl;
    m[i].setDetails();
  }

  int maxIndex = 0;
  for (int i = 1; i < n; i++) {
    if (m[i].getSalary() > m[maxIndex].getSalary()) {
      maxIndex = i;
    }
  }

  cout << "\nManager with the highest salary:\n";
  cout << "Name: " << m[maxIndex].getEmployeeName() << endl;
  cout << "Highest Salary: " << m[maxIndex].getSalary() << endl;

  delete[] m;
  return 0;
}