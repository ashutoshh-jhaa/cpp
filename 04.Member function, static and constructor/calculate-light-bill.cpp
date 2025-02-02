/*
wap to calculate electricity bill and define it's member function get() to take
details of the customer and calculateBill() to calculate electricity bill using
the following tariff
  - upto 100 units => rs 1.20 per unit
  - from 100 to 200 units => rs 2 per unit
  - above 200 unit => rs 3 per unit
*/
#include <iostream>
using namespace std;

class Bill {
 private:
  float units, billAmount;

 public:
  Bill() : units(0), billAmount(0) {}

  Bill(int u) : units(u), billAmount(0) {}

  // Function to take user input
  void get() {
    cout << "Enter electricity units consumed: ";
    cin >> units;
    if (units < 0) {
      cout << "Invalid input! Units cannot be negative.\n";
      units = 0;
    }
  }

  // Function to calculate bill based on tariff
  void calculateBill() {
    if (units <= 100) {
      billAmount = units * 1.20;
    } else if (units <= 200) {
      billAmount = 100 * 1.20 + (units - 100) * 2;
    } else {
      billAmount = 100 * 1.20 + 100 * 2 + (units - 200) * 3;
    }
  }

  // Function to display the bill
  void displayBill() {
    cout << "Units: " << units << endl;
    cout << "Bill Amount: Rs " << billAmount << endl;
  }
};

int main() {
  Bill b;
  b.get();
  b.calculateBill();
  b.displayBill();

  return 0;
}
