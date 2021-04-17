//感觉涉及小数的时候可能有精度不够的问题
#include <iostream>
using namespace std;
int main() {
  double k;
  cin >> k;
  int count = 0;
  double Sn = 0.000;
  while (Sn <= k) {
    count++;
    Sn += 1.0 / count;
  }
  cout << count << endl;
  return 0;
}