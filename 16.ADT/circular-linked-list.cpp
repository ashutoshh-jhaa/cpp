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

class CircularLinkedList {
 private:
  Node* head;
  int count;

 public:
  CircularLinkedList() {
    head = nullptr;
    count = 0;
  }

  // append at the end
  void append(int data) {
    Node* node = new Node(data);
    if (!head) {
      head = node;
      head->next = head;
      head->previous = head;
    } else {
      node->next = head;
      node->previous = head->previous;
      head->previous->next = node;
      head->previous = node;
    }
    count++;
  }

  // prepend element
  void prepend(int data) {
    if (!head) {
      append(data);
      return;
    } else {
      Node* node = new Node(data);

      node->next = head;
      node->previous = head->previous;
      head->previous->next = node;
      head->previous = node;
      head = node;
    }
    count++;
  }

  // insert at a specific position
  void insert_at(int position, int data) {
    if (position < 1 || position > count + 1) {
      cout << "Invalid Position" << endl;
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

  // remove last element
  void remove_last() {
    if (!head) {
      cout << "List is Empty" << endl;
      return;
    }

    if (head->next == head) {
      delete head;
      head = nullptr;
    } else {
      Node* last = head->previous;
      head->previous->previous->next = head;
      head->previous = head->previous->previous;
      delete last;
    }
    count--;
  }

  // remove first element
  void remove_first() {
    if (!head) {
      cout << "List is Empty" << endl;
      return;
    }

    if (head->next == head) {
      delete head;
      head = nullptr;
    } else {
      Node* temp = head;

      head->next->previous = head->previous;
      head->previous->next = head->next;
      head = head->next;

      delete temp;
    }
    count--;
  }

  // remove from specific position
  void remove_at(int position) {
    if (position < 1 || position > count) {
      cout << "Invalid Position" << endl;
      return;
    }

    if (position == 1) {
      remove_first();
      return;
    }

    int k = 1;
    Node* current = head;
    while (k < position) {
      current = current->next;
      k++;
    }

    current->previous->next = current->next;
    current->next->previous = current->previous;

    delete current;
    count--;
  }

  void display() {
    if (!head) {
      cout << "List is Empty" << endl;
      return;
    }
    Node* current = head;
    do {
      cout << current->data << " ";
      current = current->next;
    } while (current != head);
  }
};

int main() {
  CircularLinkedList c;

  // Append elements
  c.append(23);
  c.append(2);
  c.append(99);
  cout << "After appending: \n";
  c.display();

  cout << endl << endl;

  // Prepend elements
  c.prepend(1);
  cout << "After prepending 1: \n";
  c.display();

  cout << endl << endl;

  // Insert at position
  c.insert_at(3, 50);
  cout << "After inserting 50 at position 3: \n";
  c.display();

  cout << endl << endl;

  // Remove last element
  c.remove_last();
  cout << "After removing last element: \n";
  c.display();

  cout << endl << endl;

  // Remove first element
  c.remove_first();
  cout << "After removing first element: \n";
  c.display();
  cout << endl << endl;

  // Remove element at position 2
  c.remove_at(2);
  cout << "After removing element at position 2: \n";
  c.display();

  return 0;
}
