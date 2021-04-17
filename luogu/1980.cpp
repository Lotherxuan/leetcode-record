#include <iostream>
#include <string>
using namespace std;
int count_times(int number, int x) {
  int res = 0;
  while (number != 0) {
    if (number % 10 == x) {
      res++;
    }
    number = number / 10;
  }
  return res;
}
int main() {
  int max_number;
  int target_number;
  cin >> max_number >> target_number;
  int count = 0;
  for (int i = 0; i <= max_number; i++) {
    count += count_times(i, target_number);
  }
  cout << count << endl;
  return 0;
}