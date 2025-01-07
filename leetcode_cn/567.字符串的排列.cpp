/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    bool res = false;
    int left = 0;
    int right = 0;
    int min_left = left;
    int min_right = right;
    int valid_char_count = 0;
    unordered_map<char, int> window, need;
    for (char& c : s1) {
      need[c]++;
    }
    int valid_char_sum = need.size();
    while (right < s2.size()) {
      char c = s2[right];
      right++;
      if (need.count(c)) {
        window[c]++;
        if (window[c] == need[c]) {
          valid_char_count++;
          if (valid_char_count == valid_char_sum) {
            return true;
          }
        }
      }

      while (right - left + 1 > s1.size()) {
        char c = s2[left];
        left++;
        if (need.count(c)) {
          window[c]--;
          if ((window[c] + 1) == need[c]) {
            valid_char_count--;
          }
        }
      }
    }
    return res;
  }
};
// @lc code=end
