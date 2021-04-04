/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <string>
#include <unordered_map>
#include <limits>
using namespace std;
// @lc code=start
class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, int> window, need;
    for (char c : t) {
      need[c]++;
    }
    int length = numeric_limits<int>::max();
    int s_size = s.size();
    int t_size = t.size();
    int success = need.size();
    int left = 0;
    int right = 0;
    int min_left = 0;
    int min_right = 0;
    int valid = 0;
    while (right < s_size) {
      char c = s[right];
      right++;

      if (need.count(c)) {
        window[c]++;
        if (window[c] == need[c]) {
          valid++;
        }
      }

      while (valid == success) {
        if (right - left < length) {
          length = right - left;
          min_left = left;
          min_right = right;
        }
        char c = s[left];
        left++;

        if (need.count(c)) {
          window[c]--;
          if ((window[c] + 1) == need[c]) {
            valid--;
          }
        }
      }
    }
    return length == numeric_limits<int>::max()
               ? ""
               : s.substr(min_left, min_right - min_left);
  }
};
// @lc code=end
