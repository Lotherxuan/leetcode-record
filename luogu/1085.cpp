#include <iostream>
#include <limits>
using namespace std;
int main() {
  int day_count = 1;
  int max_day = 0;
  int max_time = numeric_limits<int>::min();
  bool happy = true;
  while (day_count++ < 8) {
    int i, j;
    cin >> i >> j;
    if (happy) {
      if (i + j > 8) {
        happy = false;
      }
    }

    if (i + j > max_time) {
      max_day = day_count - 1;
      max_time = i + j;
    }
  }
  if (happy) {
    cout << 0 << endl;
  } else {
    cout << max_day << endl;
  }
  return 0;
}