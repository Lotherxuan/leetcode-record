/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    int left = 0;
    int right = 0;
    vector<int> res;
    unordered_map<char, int> window;
    unordered_map<char, int> need;
    for (char& c : p) {
      need[c]++;
    }
    int valid_char_sum = need.size();
    int valid_char_count = 0;
    while (right < s.size()) {
      char c = s[right];
      right++;

      if (need.count(c)) {
        window[c]++;
        if (window[c] == need[c]) {
          valid_char_count++;
          if (valid_char_count == valid_char_sum) {
            res.push_back(left);
          }
        }
      }

      while (right - left + 1 > p.size()) {
        char c = s[left];
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
