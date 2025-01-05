// use default arguments to add 2 to 3 numbers
#include <iostream>
using namespace std;

int add(int num1, int num2, int num3 = 0) {
  return num1 + num2 + num3;
}

int main() {
  int num1, num2, num3;
  int choice;

  cout << "How many numbers would you like to add? (Enter 2 or 3): ";
  cin >> choice;

  if (choice == 2) {
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "Sum: " << add(num1, num2) << endl;
  } else if (choice == 3) {
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;
    cout << "Sum: " << add(num1, num2, num3) << endl;
  } else {
    cout << "Invalid choice! Please enter either 2 or 3." << endl;
  }

  return 0;
}
