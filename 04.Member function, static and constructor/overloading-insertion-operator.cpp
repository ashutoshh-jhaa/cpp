#include <iostream>
using namespace std;

class Person {
 private:
  int age, teeth;

 public:
  void display() {
    cout << "Age: " << age << endl << "Teeth: " << teeth << endl;
  }

  // Friend function to overload the >> operator
  friend istream& operator>>(istream&, Person&);
};

// Overloading the >> operator for input of Person objects
istream& operator>>(istream& i, Person& p) {
  cout << "Please enter your age: ";
  i >> p.age;

  cout << "Please enter the number of your teeth: ";
  i >> p.teeth;

  // Return the input stream for chaining (so cin can be used with multiple
  // objects)
  return i;
}

int main() {
  Person p1, p2, p3;

  // We can also chain like cin>>p1>>p2;
  cout << "\nEnter details for Person 1:\n";
  cin >> p1;
  cout << "\nEnter details for Person 2:\n";
  cin >> p2;

  cout << "\nEnter details for Person 3:\n";
  cin >> p3;

  // Display the details of p1, p2, and p3 using the display() method
  cout << "\nDetails of Person 1:\n";
  p1.display();
  cout << "\nDetails of Person 2:\n";
  p2.display();
  cout << "\nDetails of Person 3:\n";
  p3.display();
}
