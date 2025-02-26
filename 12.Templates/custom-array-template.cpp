// implement a dynamic Array class
#include <iostream>
using namespace std;

// copy elements of two arrays
template <typename T1>
void copyArray(T1* source, T1* destination, int size) {
  if (size <= 0) {
    return;
  }

  for (int i = 0; i < size; i++) {
    destination[i] = source[i];
  }
}

template <typename T>
class Array {
 private:
  // tracks the size of an array
  int size = 1;

  // tracks the number of elements in an array
  int elements = 0;

  T* array = new T[size];

 public:
  // push elements
  void push(T val) {
    if (elements == size) {
      size = size * 2;

      T* tempArray = new T[size];
      copyArray(array, tempArray, elements);

      delete[] array;
      array = tempArray;
    }

    *(array + elements) = val;
    elements++;
  }

  // pop elements
  T pop() {
    if (elements == 0) {
      cout << "Array is Empty !" << endl;
    }

    // return last index element and decrease elements size
    return array[--elements];
  }

  // insert at an index
  void insert(T value, int index) {
    if (index < 0 || index > elements) {
      cout << "index out of bound" << endl;
      return;
    }

    // increase size if (size == elements)
    if (size == elements) {
      size = size * 2;

      T* tempArray = new T[size];
      copyArray(array, tempArray, elements);

      delete[] array;
      array = tempArray;
    }

    // shift elements
    for (int i = elements; i > index; i--) {
      array[i] = array[i - 1];
    }

    array[index] = value;
    elements++;
  }

  void display() {
    if (elements == 0) {
      cout << "Array is Empty!" << endl;
      return;
    }

    for (int i = 0; i < elements; i++) {
      cout << "Array [" << i << "] : " << array[i] << endl << endl;
    }
  }

  ~Array() { delete[] array; }
};

int main() {
  Array<int> a;
  a.push(23);
  a.push(2);
  a.push(4);
  a.push(2);
  a.push(8);

  cout << "array after pushing 5 elements" << endl;
  a.display();

  cout << "array after poping element" << endl;
  a.pop();
  a.display();

  cout << "array after inserting element at an index" << endl;
  a.insert(99, 2);
  a.display();
}
