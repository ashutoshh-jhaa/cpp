#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

class LinkedList {
 private:
  Node* head;
  int size_;

 public:
  LinkedList() {
    head = nullptr;
    size_ = 0;
  }

  // Append to the end
  void append(int data) {
    Node* newNode = new Node(data);

    if (!head) {
      head = newNode;
    } else {
      Node* temp = head;
      while (temp->next) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
    size_++;
  }

  // Prepend to the beginning
  void prepend(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    size_++;
  }

  // Insert at a specific position
  void insert_at(int position, int data) {
    if (position < 1 || position > size_ + 1) {
      cout << "Invalid Position" << endl;
      return;
    }

    if (position == 1) {
      prepend(data);
      return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;

    for (int i = 1; i < position - 1; i++) {
      temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    size_++;
  }

  // Remove the last element
  void remove_last() {
    if (!head) {
      cout << "List is Empty, cannot remove_last()" << endl;
      return;
    }

    if (!head->next) {
      delete head;
      head = nullptr;
      size_--;
      return;
    }

    Node* temp = head;
    while (temp->next->next) {
      temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    size_--;
  }

  // Remove the first element
  void remove_first() {
    if (!head) {
      cout << "List is Empty, cannot remove_first()" << endl;
      return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    size_--;
  }

  // Remove element at a specific position
  void remove_at(int position) {
    if (position < 1 || position > size_) {
      cout << "Invalid Position" << endl;
      return;
    }

    if (position == 1) {
      remove_first();
      return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
      temp = temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    size_--;
  }

  // Display elements
  void display() {
    if (!head) {
      cout << "List is Empty" << endl;
      return;
    }

    Node* temp = head;
    cout << "Head -> ";
    while (temp) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "Tail" << endl;
  }

  // Display size
  void size() { cout << "Size: " << size_ << endl; }
};

int main() {
  LinkedList list;

  cout << "Appending 10, 20, 30 to the list..." << endl;
  list.append(10);
  list.append(20);
  list.append(30);
  list.display();
  list.size();

  cout << "\nPrepending 5 to the list..." << endl;
  list.prepend(5);
  list.display();
  list.size();

  cout << "\nInserting 15 at position 3..." << endl;
  list.insert_at(3, 15);
  list.display();
  list.size();

  cout << "\nRemoving first element..." << endl;
  list.remove_first();
  list.display();
  list.size();

  cout << "\nRemoving last element..." << endl;
  list.remove_last();
  list.display();
  list.size();

  cout << "\nRemoving element at position 2..." << endl;
  list.remove_at(2);
  list.display();
  list.size();

  return 0;
}
