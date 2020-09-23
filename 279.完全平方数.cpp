/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int numSquares(int n) {
    if (n == 0 || n == 1) {
      return n;
    }
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++) {
      int res = i;
      for (int j = 1; j * j <= i; j++) {
        res = min(res, dp[i - j * j] + 1);
      }
      dp[i] = res;
    }
    return dp[n];
  }
};
// @lc code=end
