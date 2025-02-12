/*
create a file stduent-record.txt and store details like roll number, name, age
and stream
  - we should be able to add new student details
  - search student
  - print all records
  - update records
  - delete records
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int getLastStudentID() {
  ifstream fin("./student-id.txt");
  int id = 0;
  while (fin >> id) {
  }
  return id;
}

class Student {
 private:
  int id, age;
  string name, stream, gender;

 public:
  Student() {}
  Student(int i, string n, string s, int a, string g)
      : id(i), name(n), stream(s), age(a), gender(g) {}

  void addNewStudent() {
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Stream: ";
    getline(cin, stream);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Gender: ";
    getline(cin, gender);

    int newID = getLastStudentID() + 1;
    ofstream fout("./student-record.txt", ios::app);
    fout << newID << "\n"
         << name << "\n"
         << stream << "\n"
         << age << "\n"
         << gender << "\n\n";
    fout.close();

    fout.open("./student-id.txt", ios::trunc);
    fout << newID;
    fout.close();
  }

  void displayAllStudents() {
    ifstream fin("./student-record.txt");
    while (fin >> id) {
      fin.ignore();
      getline(fin, name);
      getline(fin, stream);
      fin >> age;
      fin.ignore();
      getline(fin, gender);
      printStudent();
    }
    fin.close();
  }

  bool searchStudent(int searchID) {
    ifstream fin("./student-record.txt");
    while (fin >> id) {
      fin.ignore();
      getline(fin, name);
      getline(fin, stream);
      fin >> age;
      fin.ignore();
      getline(fin, gender);
      if (id == searchID) {
        printStudent();
        return true;
      }
    }
    return false;
  }

  bool deleteStudent(int deleteID) {
    ifstream fin("./student-record.txt");
    ofstream fout("./temp-record.txt");
    bool found = false;

    while (fin >> id) {
      fin.ignore();
      getline(fin, name);
      getline(fin, stream);
      fin >> age;
      fin.ignore();
      getline(fin, gender);
      if (id == deleteID) {
        found = true;
      } else {
        fout << id << "\n"
             << name << "\n"
             << stream << "\n"
             << age << "\n"
             << gender << "\n\n";
      }
    }
    fin.close();
    fout.close();
    remove("./student-record.txt");
    rename("./temp-record.txt", "./student-record.txt");
    return found;
  }

  bool updateStudent(int updateID) {
    ifstream fin("./student-record.txt");
    ofstream fout("./temp-record.txt");
    bool found = false;

    while (fin >> id) {
      fin.ignore();
      getline(fin, name);
      getline(fin, stream);
      fin >> age;
      fin.ignore();
      getline(fin, gender);

      if (id == updateID) {
        found = true;
        cin.ignore();
        cout << "Enter New Name: ";
        getline(cin, name);
        cout << "Enter New Stream: ";
        getline(cin, stream);
        cout << "Enter New Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter New Gender: ";
        getline(cin, gender);
      }
      fout << id << "\n"
           << name << "\n"
           << stream << "\n"
           << age << "\n"
           << gender << "\n\n";
    }
    fin.close();
    fout.close();
    remove("./student-record.txt");
    rename("./temp-record.txt", "./student-record.txt");
    return found;
  }

  void printStudent() {
    cout << "ID: " << id << "\nName: " << name << "\nStream: " << stream
         << "\nAge: " << age << "\nGender: " << gender << "\n\n";
  }
};

int main() {
  while (true) {
    cout << "1. Add Student\n2. Update Student\n3. Delete Student\n4. Search "
            "Student\n5. Display All Students\n6. Exit\nEnter choice: ";
    int choice, id;
    Student s;
    cin >> choice;

    switch (choice) {
      case 1:
        s.addNewStudent();
        break;
      case 2:
        cout << "Enter ID to update: ";
        cin >> id;
        if (!s.updateStudent(id))
          cout << "Student not found.\n";
        break;
      case 3:
        cout << "Enter ID to delete: ";
        cin >> id;
        if (!s.deleteStudent(id))
          cout << "Student not found.\n";
        break;
      case 4:
        cout << "Enter ID to search: ";
        cin >> id;
        if (!s.searchStudent(id))
          cout << "Student not found.\n";
        break;
      case 5:
        s.displayAllStudents();
        break;
      case 6:
        return 0;
      default:
        cout << "Invalid choice!\n";
    }
  }
}
