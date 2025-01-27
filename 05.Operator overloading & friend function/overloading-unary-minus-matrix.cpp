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

  void update(int r) { matrix[0][3] = r; }

  Matrix operator-() {
    cout << "operator-" << endl;
    Matrix m;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        m.matrix[i][j] = -matrix[i][j];
      }
    }
    return m;
  }
};
int main() {
  Matrix m1, m2;
  m1.setter();

  cout << "M1" << endl;
  m1.display();

  m2 = m1;

  cout << "M2" << endl;
  m2.display();

  m2.update(99);

  cout << "after update" << endl;

  cout << "M1" << endl;
  m1.display();

  cout << "M2" << endl;
  m2.display();

  m2 = -m1;
  m2.display();
}