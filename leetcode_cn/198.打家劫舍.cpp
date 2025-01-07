/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

#include <vector>
using namespace std;

// @lc code=start
// easy难度 没啥好说的
class Solution {
 public:
  int rob(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) {
      return 0;
    } else if (size == 1) {
      return nums[0];
    }

    vector<int> dp(size);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < size; i++) {
      dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[size - 1];
  }
};
// @lc code=end
