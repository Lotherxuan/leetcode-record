// KMP算法模板
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
void border(string const& pattern, vector<int>& borders) {
  // borders[j]表示pattern[1...j]最大相同的真前缀和真后缀
  int length = borders.size();
  int j = 0;
  if (length) {
    borders[0] = 0;
    borders[1] = 0;
    // 只统计真后缀和真前缀
    if (length >= 1) {
      for (int i = 2; i < length; i++) {
        // 求borders[i]的值
        while (j > 0 && pattern[j + 1] != pattern[i]) {
          j = borders[j];
          //重设j的值，到往前最大相同真前缀的位置
        }
        //此时j=0或者pattern[j+1] == pattern[i]
        if (pattern[j + 1] == pattern[i]) {
          j++;
        }
        borders[i] = j;
      }
    }
  }
}
int main() {
  string pattern, search;
  cin >> search;
  cin >> pattern;
  pattern.insert(pattern.begin(), ' ');
  search.insert(search.begin(), ' ');
  int pattern_length = pattern.length();
  int search_length = search.length();
  vector<int> borders(pattern_length);
  border(pattern, borders);
  // for_each(borders.begin(), borders.end(),
  //          [](int const& i) { cout << i << endl; });
  int i = 1, j = 0;
  // search[i...i+j-1]和pattern[1...j]匹配
  for (int i = 1; i < search_length; i++) {
    while (j > 0 && (search[i] != pattern[j + 1])) {
      j = borders[j];
    }
    if (search[i] == pattern[j + 1]) {
      j++;
    }
    if (j == pattern_length - 1) {
      cout << i - j + 1 << endl;
      //输出匹配串匹配位置的开头
      j = borders[j];
    }
  }
  for_each(borders.begin() + 1, borders.end(),
           [](int const& i) { cout << i << " "; });
  cout << endl;
}