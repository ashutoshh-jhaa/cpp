// Define a class Person with instance members name and age. Also, define the
// member functions setName(), setAge(), getName(), and getAge(). Now, define a
// class Employee that inherits from Person. In the Employee class, add empId
// and salary as instance members, along with the member functions setEmpId(),
// setSalary(), getEmpId(), and getSalary().

#include <iostream>
using namespace std;

class Person {
 private:
  string name;
  int age;

 public:
  // Constructor
  Person(string n = "", int a = 0) : name(n), age(a) {}

  // Setters
  void setName(string n) { name = n; }
  void setAge(int a) { age = a; }

  // Getters
  string getName() const { return name; }
  int getAge() const { return age; }
};

class Employee : public Person {
 private:
  int employeeId;
  int employeeSalary;

 public:
  // Constructor
  Employee(string n, int a, int id, int salary)
      : Person(n, a), employeeId(id), employeeSalary(salary) {}

  // Setters
  void setEmployeeId(int i) { employeeId = i; }
  void setEmployeeSalary(int s) { employeeSalary = s; }

  // Getters
  int getEmployeeId() const { return employeeId; }
  int getEmployeeSalary() const { return employeeSalary; }

  // Display function
  void display() const {
    cout << "Name : " << getName() << "\n"
         << "Age : " << getAge() << "\n"
         << "Employee Id : " << employeeId << "\n"
         << "Employee Salary : " << employeeSalary << "\n";
  }
};

int main() {
  Employee e("Ashutosh Ranjan Jha", 20, 1, 20000);
  e.display();
}