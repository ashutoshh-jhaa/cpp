// overload not operator to toggle case of a given string
#include <cstring>
#include <iostream>
using namespace std;

class myString {
 private:
  char* name;
  size_t size;
  char* reversedCase;

 public:
  myString(const char* n) {
    size = strlen(n) + 1;
    name = new char[size];
    strcpy(name, n);
    reversedCase = nullptr;
  }

  // Overload the '!' operator to toggle case
  myString& operator!() {
    if (reversedCase) {
      delete[] reversedCase;
    }
    reversedCase = new char[size];
    strcpy(reversedCase, name);

    for (size_t i = 0; i < size - 1; i++) {
      if (reversedCase[i] >= 'A' && reversedCase[i] <= 'Z') {
        reversedCase[i] += 32;
      } else if (reversedCase[i] >= 'a' && reversedCase[i] <= 'z') {
        reversedCase[i] -= 32;
      }
    }
    return *this;
  }

  friend ostream& operator<<(ostream& o, myString& s);

  ~myString() {
    delete[] name;
    delete[] reversedCase;
  }
};

ostream& operator<<(ostream& o, myString& s) {
  if (s.reversedCase) {
    o << "Reversed Case: " << s.reversedCase;
  } else {
    o << "No case toggle performed yet.";
  }
  return o;
}

int main() {
  myString s1("AshuTOSH");
  cout << !s1 << endl;

  myString s2("johnDOE");
  cout << !s2 << endl;

  myString s3 = !s1;
  cout << s3 << endl;

  return 0;
}
