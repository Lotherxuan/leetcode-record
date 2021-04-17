#include <iostream>
using namespace std;
int main() {
  int N;
  cin >> N;
  int i = 1;
  while (i * (i + 1) / 2 < N) {
    i++;
  }
  int count = N - (i * (i - 1) / 2);
  if (i % 2 == 0) {
    cout << count << "/" << (i + 1 - count) << endl;
  } else {
    cout << (i + 1 - count) << "/" << count << endl;
  }

  return 0;
}