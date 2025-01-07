/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start

//自底向上构造dp_table 遍历的方式可以改进 不能减少时间复杂度，但是能减少运行时间
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string longestPalindrome(string s) {
    int len = s.length();
    if (!len) {
      return s;
    } else {
      vector<vector<bool>> dp(len, vector<bool>(len));
      int length = 0;
      string res;
      for (int i = 0; i < len; i++) {
        dp[i][i] = true;
      }
      for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
          dp[i][i + 1] = true;
        }
      }
      for (int j = 2; j < len; j++) {
        for (int i = 0; j + i < len; i++) {
          dp[i][j + i] = dp[i + 1][j + i - 1] && (s[i] == s[j + i]);
        }
      }
      for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
          if (dp[i][j]) {
            if ((j - i + 1) > length) {
              length = j - i + 1;
              res = s.substr(i, j - i + 1);
            }
          }
        }
      }
      return res;
    }
    return "exception";
  }
};
// @lc code=end
