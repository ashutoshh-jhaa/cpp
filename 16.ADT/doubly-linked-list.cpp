#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node* previous;

  Node(int data) {
    this->data = data;
    next = nullptr;
    previous = nullptr;
  }
};

class DoublyLinkedList {
 private:
  Node* head;
  int count;

 public:
  DoublyLinkedList() {
    head = nullptr;
    count = 0;
  }

  // append to the end
  void append(int data) {
    Node* node = new Node(data);

    if (!head) {
      head = node;
    } else {
      Node* current = head;
      while (current->next) {
        current = current->next;
      }

      current->next = node;
      node->previous = current;
    }
    count++;
  }

  // prepend to the beginning
  void prepend(int data) {
    Node* node = new Node(data);

    if (!head) {
      head = node;
    } else {
      node->next = head;
      head->previous = node;
      head = node;
    }
    count++;
  }

  // insert at a specific position
  void insert_at(int position, int data) {
    if (position < 1 || position > count + 1) {
      cout << "Invalid Position, cannot perform insert_at()" << endl;
      return;
    }

    if (position == 1) {
      prepend(data);
      return;
    }

    Node* node = new Node(data);

    int k = 1;
    Node* current = head;

    while (k < position) {
      current = current->next;
      k++;
    }

    node->previous = current->previous;
    node->next = current;
    current->previous->next = node;
    current->previous = node;
    count++;
  }

  // remove last
  void remove_last() {
    if (!head) {
      cout << "List is Empty" << endl;
      return;
    }

    if (!head->next) {
      delete head;
      head = nullptr;
      count--;
      return;
    }

    Node* current = head;
    while (current->next) {
      current = current->next;
    }
    Node* temp = current;
    current->previous->next = nullptr;
    delete temp;
    count--;
  }

  // remove the first element
  void remove_first() {
    if (!head) {
      cout << "List is Empty" << endl;
      return;
    }

    if (!head->next) {
      delete head;
      head = nullptr;
      count--;
      return;
    }

    Node* temp = head;
    head = head->next;
    head->previous = nullptr;
    delete temp;
    count--;
  }

  // remove element at a specific position
  void remove_at(int position) {
    if (position < 1 || position > count) {
      cout << "Invalid Position" << endl;
      return;
    }

    Node* temp = head;

    if (position == 1) {
      head = head->next;
      if (head)
        head->previous = nullptr;
      delete temp;
      count--;
      return;
    }

    Node* current = head;
    for (int k = 1; k < position; k++) {
      current = current->next;
    }

    current->previous->next = current->next;
    if (current->next) {
      current->next->previous = current->previous;
    }

    delete current;
    count--;
  }

  // display elements
  void display() {
    if (!head) {
      cout << "List is Empty" << endl;
      return;
    }
    Node* current = head;

    cout << "Head -> ";
    while (current) {
      cout << current->data << " <-> ";
      current = current->next;
    }
    cout << "Tail" << endl;
  }
};

int main() {
  DoublyLinkedList dl;

  cout << "Appending 5, 10, 15 to the list..." << endl;
  dl.append(5);
  dl.append(10);
  dl.append(15);
  dl.display();

  cout << "\nPrepending 1 to the list..." << endl;
  dl.prepend(1);
  dl.display();

  cout << "\nInserting 7 at position 3..." << endl;
  dl.insert_at(3, 7);
  dl.display();

  cout << "\nRemoving first element..." << endl;
  dl.remove_first();
  dl.display();

  cout << "\nRemoving last element..." << endl;
  dl.remove_last();
  dl.display();

  cout << "\nRemoving element at position 2..." << endl;
  dl.remove_at(2);
  dl.display();

  return 0;
}