#include <iostream>
using namespace std;

// Forward declaration of Dollar
class Dollar;

// Rupee class to represent and convert rupee values
class Rupee {
 private:
  float rupee;

 public:
  Rupee() { cout << "Rupee Default Constructor (DC) called\n"; }

  // Constructor to initialize rupee value
  Rupee(float r) {
    cout << "Rupee Parameterized Constructor (PC) called\n";
    rupee = r;
  }

  // Conversion operator: Rupee to float
  operator float() {
    cout << "Rupee to float conversion called\n";
    return rupee;
  }

  // Getter for rupee value
  int getRupee() { return rupee; }
};

class Dollar {
 private:
  float dollar;

 public:
  Dollar() { cout << "Dollar Default Constructor (DC) called\n"; }

  // Constructor to initialize dollar value
  Dollar(float d) {
    cout << "Dollar Parameterized Constructor (PC) called\n";
    dollar = d;
  }

  // Constructor to convert Rupee to Dollar
  Dollar(Rupee p) {
    cout << "Rupee to Dollar conversion called\n";
    dollar = p.getRupee() / 83;
  }

  // Display dollar value
  void getDollar() { cout << dollar << endl; }

  // Conversion operator: Dollar to float
  operator float() {
    cout << "Dollar to float conversion called\n";
    return dollar;
  }

  // Conversion operator: Dollar to Rupee
  operator Rupee() {
    cout << "Dollar to Rupee conversion called\n";
    return dollar * 83;  // Same as calling Rupee(dollar * 83)
  }
};

int main() {
  // Step 1: Initialize Dollar with float
  float dlr = 42;
  Dollar d = dlr;  // Calls Dollar(float) constructor
  d.getDollar();

  // Step 2: Convert Dollar to float
  float newdlr = d;  // Calls Dollar's conversion to float
  cout << newdlr << endl;

  // Step 3: Initialize Rupee with float
  float rup = 88;
  Rupee r = rup;  // Calls Rupee(float) constructor
  r.getRupee();

  // Step 4: Convert Rupee to float
  float newRup = r;  // Calls Rupee's conversion to float
  cout << newRup << endl;

  // Step 5: Convert Dollar to Rupee
  Dollar d1 = 77;  // Calls Dollar(float) constructor
  Rupee r1 = 64;   // Calls Rupee(float) constructor
  cout << endl;
  r1 = (Rupee)d1;  // Calls Dollar's conversion to Rupee, then Rupee(float)
  cout << r1 << endl;

  // Step 6: Convert Rupee to Dollar
  cout << endl;
  d1 = (Dollar)r1;  // Calls Dollar(Rupee) constructor
  cout << d1 << endl;

  return 0;
}
