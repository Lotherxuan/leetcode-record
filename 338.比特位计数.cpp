/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> dp(num + 1, 0);
    int high_bit = 0;
    for (int i = 1; i <= num; i++) {
      if ((i & (i - 1)) == 0) {
        high_bit = i;
      }
      dp[i] = dp[i - high_bit] + 1;
    }
    return dp;
  }
};
// @lc code=end
