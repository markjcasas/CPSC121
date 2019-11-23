#include <iostream>

int sum_numbers(int numbers[], int size) {
  if (size == 1) {
    return numbers[0];
  } else {
    return numbers[size - 1] + sum_numbers(numbers, size -1);
  }
}

int main() {
  int my_numbers[] = {5, 8, 12 ,4, 1};
  int sum = 0;
  sum = sum_numbers(my_numbers, 5);
  std::cout << "Sum is: " << sum << '\n';
  return 0;
}
