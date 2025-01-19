// wap to create a class myString, overload + to concatenate two string and also
// overload == to check if two strings are same
#include <cstring>
#include <iostream>
using namespace std;

class myString {
 private:
  char* str;
  int size;

 public:
  myString() {
    size = 1;
    str = new char[size];
  }

  myString(const char* n1) {
    size = strlen(n1);
    str = new char[size + 1];
    strcpy(str, n1);
  }

  // overloaded + to concatenate two strings
  myString operator+(const myString& s) {
    myString s1;
    s1.size = size + s.size;
    s1.str = new char[s1.size + 1];

    strcpy(s1.str, str);
    strcat(s1.str, s.str);
    return s1;
  }

  // overloaded == to check if two strings are the same
  bool operator==(myString s) { return !strcmp(str, s.str); }

  // friend function for overloaded << operator
  friend ostream& operator<<(ostream& o, const myString& s);

  // Destructor for cleanup
  ~myString() { delete[] str; }
};

ostream& operator<<(ostream& o, const myString& s) {
  o << s.str;
  return o;
}

int main() {
  myString s1("ashutosh"), s2("ashutosh"), s3("raj"), s4("shourya");
  cout << "Concatened String : \n";
  cout << (s1 + s4) << endl;  // Concatenate s1 and s2

  (s1 == s2)
      ? cout << "\ns1 and s2 are equal"
      : cout << "\ns1 and s2 are not equal";  // Check if s1 and s2 are equal
  return 0;
}
