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

  // delete element for given index
  void deleteIndex(int index) {
    // check for index out of bound
    if (index < 0 || index >= elements) {
      cout << "index out of bound" << endl;
      return;
    }

    // shift elements to fill gap
    for (int i = index; i < elements - 1; i++) {
      array[i] = array[i + 1];
    }

    // reduce elements size
    elements--;
  }

  // overloading [] operator
  T operator[](int index) {
    // check for index out of bound
    if (index < 0 || index >= elements) {
      cout << "index out of bound" << endl;
      return 0;
    }

    // cout << "array[index]" << array[index];
    return array[index];
  }

  // get number of elements
  int length() { return elements; }

  // get capacity of array
  int capacity() { return size; }

  // search and delete (delete first occurrence)
  void searchDeleteElement(int value) {
    // will add binary search afterwards
    for (int i = 0; i < elements; i++) {
      if (array[i] == value) {
        deleteIndex(i);
        cout << "Element " << array[i] << " deleted from index " << i << endl;
        return;
      }
    }

    cout << "Element Not found !" << endl;
  }

  // displays array elements
  void display() {
    if (elements == 0) {
      cout << "Array is Empty!" << endl;
      return;
    }

    for (int i = 0; i < elements; i++) {
      cout << "Array [" << i << "] : " << array[i] << endl;
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

  cout << "array after pushing 5 an elements" << endl;
  a.display();

  cout << "array after poping an element" << endl;
  a.pop();
  a.display();

  cout << "array after inserting an element at an index" << endl;
  a.insert(99, 2);
  a.display();

  cout << "array after deleting an element from an index" << endl;
  a.deleteIndex(2);
  a.display();

  // overloading of [] operator
  cout << "Overloading of []" << endl;
  for (int i = 0; i < a.length(); i++) {
    cout << "Array [" << i << "] : " << a[i] << endl;
  }

  // length and capacity of the array;
  cout << "Lenght and capacity of the array" << endl;
  cout << "Capacity : " << a.capacity() << endl;
  cout << "Length : " << a.length() << endl;

  // search and delete element
  a.searchDeleteElement(45);
  a.searchDeleteElement(2);
  a.display();
}
