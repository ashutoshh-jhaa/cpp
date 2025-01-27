// wap to sum two matrices m1= m2+m3 using overloading of + operator
#include <iostream>
using namespace std;

class Matrix {
 private:
  int matrix[3][3];

 public:
  Matrix() {}

  void setter() {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cout << "Matrix[" << i << "][" << j << "] : ";
        cin >> matrix[i][j];
      }
    }
  }

  void display() {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
  }

  Matrix operator+(const Matrix& m) {
    Matrix temp;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        temp.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
      }
    }
    return temp;
  }
};

int main() {
  Matrix m1;
  m1.setter();

  Matrix m2 = m1;

  Matrix m3 = m1 + m2;
  m3.display();
}