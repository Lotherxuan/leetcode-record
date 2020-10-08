/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

using namespace std;
#include <vector>
// @lc code=start
//当前算法时间复杂度为O(n^2),可以继续优化到O(n)
class Solution {
 public:
  int integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i < n + 1; i++) {
      int temp = 0;
      for (int j = 1; j < i; j++) {
        temp = max(max(temp, (i - j) * dp[j]), (i - j) * j);
      }
      dp[i] = temp;
    }
    return dp[n];
  }
};
// @lc code=end
