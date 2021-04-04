/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */
//错误的在局部重声明了外围变量，导致未初始化的问题

#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> dp(n);
    dp[0] = 1;
    int index_2 = 0;
    int index_3 = 0;
    int index_5 = 0;
    for (int i = 1; i < n; i++) {
      int next = min({dp[index_2] * 2, dp[index_3] * 3, dp[index_5] * 5});
      while (next == dp[i - 1]) {
        if (next == dp[index_2] * 2) {
          index_2++;
        } else if (next == dp[index_3] * 3) {
          index_3++;
        } else if (next == dp[index_5] * 5) {
          index_5++;
        }
        next = min({dp[index_2] * 2, dp[index_3] * 3, dp[index_5] * 5});
      }

      dp[i] = next;
      if (next == dp[index_2] * 2) {
        index_2++;
      } else if (next == dp[index_3] * 3) {
        index_3++;
      } else if (next == dp[index_5] * 5) {
        index_5++;
      }
      dp[i] = next;
    }
    return dp[n - 1];
  }
};
// @lc code=end
