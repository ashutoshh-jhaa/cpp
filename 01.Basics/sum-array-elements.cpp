#include <iostream>
int main() {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 7, 8, 8}, sum = 0;

  for (int i = 0; i < 10; i++) {
    sum += arr[i];
  }

  std::cout << "sum : " << sum;
}