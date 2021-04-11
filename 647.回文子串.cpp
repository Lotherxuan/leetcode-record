/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int countSubstrings(string s) {
    if (s.empty()) {
      return 0;
    }
    if (s.size() == 1) {
      return 1;
    }
    int size = s.size();
    vector<vector<bool>> dp(size, vector<bool>(size, false));
    int count = 0;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size - i; j++) {
        int row = j;
        int column = i + j;
        if (row == column) {
          dp[row][column] = true;
          count++;
        } else if ((column - row) == 1 && s[column] == s[row]) {
          dp[row][column] = true;
          count++;
        } else if (i >= 2 && dp[row + 1][column - 1] && s[column] == s[row]) {
          dp[row][column] = true;
          count++;
        }
      }
    }
    return count;
  }
};
// @lc code=end
