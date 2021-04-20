#include <iostream>
using namespace std;
int main() {
  long long a1, a2, n;

  cin >> a1 >> a2 >> n;
  long long last = a1 + (a2 - a1) * (n - 1);
  cout << (a1 + last) * n / 2 << endl;
}
