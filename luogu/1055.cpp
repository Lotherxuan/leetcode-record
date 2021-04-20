#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  string s;
  cin >> s;
  int count = 1;
  int sum = 0;
  for (auto c : s) {
    if (c != '-') {
      if (count < 10) {
        sum += count * (c - '0');
        count++;
      } else {
        int remain = sum % 11;
        if (((remain < 10 && remain == (c - '0'))) ||
            (remain == 10 && c == 'X')) {
          cout << "Right" << endl;
        } else {
          s.pop_back();
          if (remain == 10) {
            s.push_back('X');
          } else {
            s.push_back(remain + '0');
          }
          cout << s << endl;
        }
      }
    }
  }
}