#include <iostream>
using namespace std;

class Area {
 private:
  float side, length, breadth, base, height, radius;

 public:
  void setSide(float s) { side = s; }
  void setLengthBreadth(float l, float b) {
    length = l;
    breadth = b;
  }
  void setBaseHeight(float b, float h) {
    base = b;
    height = h;
  }
  void setRadius(float r) { radius = r; }

  float areaOfSquare() { return side * side; }
  float areaOfRectangle() { return length * breadth; }
  float areaOfTriangle() { return 0.5 * base * height; }
  float areaOfCircle() { return 3.14 * radius * radius; }
};

int main() {
  Area a;
  int choice;

  do {
    cout << "\n---Select for Area---\n";
    cout << "1. Square\n";
    cout << "2. Rectangle\n";
    cout << "3. Triangle\n";
    cout << "4. Circle\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1: {
        float side;
        cout << "Enter side of the square: ";
        cin >> side;
        if (side < 0) {
          cout << "Invalid input. Side must be non-negative.\n";
          break;
        }
        a.setSide(side);
        cout << "Area of Square: " << a.areaOfSquare() << endl;
        break;
      }
      case 2: {
        float length, breadth;
        cout << "Enter the length of the rectangle: ";
        cin >> length;
        cout << "Enter the breadth of the rectangle: ";
        cin >> breadth;
        if (length < 0 || breadth < 0) {
          cout << "Invalid input. Dimensions must be non-negative.\n";
          break;
        }
        a.setLengthBreadth(length, breadth);
        cout << "Area of Rectangle: " << a.areaOfRectangle() << endl;
        break;
      }
      case 3: {
        float base, height;
        cout << "Enter the base of the triangle: ";
        cin >> base;
        cout << "Enter the height of the triangle: ";
        cin >> height;
        if (base < 0 || height < 0) {
          cout << "Invalid input. Dimensions must be non-negative.\n";
          break;
        }
        a.setBaseHeight(base, height);
        cout << "Area of Triangle: " << a.areaOfTriangle() << endl;
        break;
      }
      case 4: {
        float radius;
        cout << "Enter the radius of the circle: ";
        cin >> radius;
        if (radius < 0) {
          cout << "Invalid input. Radius must be non-negative.\n";
          break;
        }
        a.setRadius(radius);
        cout << "Area of Circle: " << a.areaOfCircle() << endl;
        break;
      }
      case 5: {
        cout << "Exiting the program. Goodbye!\n";
        break;
      }
      default: {
        cout << "Invalid choice. Please try again.\n";
      }
    }
  } while (choice != 5);

  return 0;
}
