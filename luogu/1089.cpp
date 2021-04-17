// 写的算法有问题，读题不仔细，漏掉了一些逻辑信息
#include <iostream>
using namespace std;
int main() {
  int month_sum = 12;
  int month_count = 0;
  int save = 0;
  int cur_money = 0;
  while (month_count++ < month_sum) {
    int budget;
    cin >> budget;
    if (cur_money + 300 < budget) {
      cout << "-" << month_count << endl;
      break;
    } else {
      int over_money = cur_money + 300 - budget;
      save += (over_money / 100) * 100;
      cur_money = over_money % 100;
    }
    if (month_count == 12) {
      cout << (save * 1.2) + cur_money << endl;
    }
  }
  return 0;
}