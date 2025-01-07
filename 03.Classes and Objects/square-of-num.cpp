// define a class square to find the square of number and also count the number
// of times that function is called
#include <iostream>
using namespace std;

class NumSquare {
 private:
  int num, numSquare;

 public:
  static int count;  // Static variable to count function calls

  // Setters and getters
  void setNum(int n) { num = n; }
  int getNum() const { return num; }
  int getNumSquare() const { return numSquare; }

  // Calculate square and increment count
  void calSquare() {
    numSquare = num * num;
    count++;
  }
};

// Initialize static variable
int NumSquare::count = 0;

int main() {
  NumSquare n1, n2;

  // Set numbers and calculate squares
  n1.setNum(91);
  n2.setNum(23);

  n1.calSquare();
  n2.calSquare();

  // Display results
  cout << "Number 1: " << n1.getNum() << ", Square: " << n1.getNumSquare()
       << endl;
  cout << "Number 2: " << n2.getNum() << ", Square: " << n2.getNumSquare()
       << endl;

  // Display the count of function calls
  cout << "Function called " << NumSquare::count << " times." << endl;

  return 0;
}
