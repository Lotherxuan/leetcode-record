#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_set>
using namespace std;
int main() {
  int start, end;
  cin >> start;
  cin >> end;
  vector<int> month_days{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  unordered_set<int> s;
  for (int month = 1; month <= 12; month++) {
    for (int day = 1; day <= month_days[month - 1]; day++) {
      int total = 0;
      total += month * 100;
      total += day;
      int year = 0;
      year +=
          ((day % 10) * 10 + (day / 10)) * 100 + (month % 10) * 10 + month / 10;
      total += year * 10000;
      s.insert(total);
    }
  }
  int count = 0;
  for (auto i = s.begin(); i != s.end(); i++) {
    if (*i <= end && *i >= start) {
      count++;
    }
  }
  //   for (int i = start; i <= end; i++) {
  //     if (s.find(i) != s.end()) {
  //       count++;
  //     }
  //   }
  cout << count << endl;
}