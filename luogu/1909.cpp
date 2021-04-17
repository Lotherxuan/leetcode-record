#include <iostream>
#include <limits>
using namespace std;
int main() {
  int target_count;
  cin >> target_count;
  int case_sum = 3;
  int case_count = 0;
  int money = 0;
  int min_money = numeric_limits<int>::max();
  while (case_count++ < case_sum) {
    int price;
    int count;
    cin >> count >> price;
    if (target_count % count == 0) {
      money = target_count / count * price;
    } else {
      money = (target_count / count + 1) * price;
    }
    if (money < min_money) {
      min_money = money;
    }
  }
  cout << min_money << endl;
}