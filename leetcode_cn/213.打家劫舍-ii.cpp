/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

using namespace std;
#include <vector>

// @lc code=start
class Solution {
 public:
  int rob(vector<int>& nums) {
    int res = 0;
    int size = nums.size();
    int res_with_first;
    int res_without_first;

    if (!size) {
      return 0;
    } else if (size == 1) {
      return nums[0];
    } else if (size == 2) {
      return max(nums[0], nums[1]);
    }

    vector<int> dp(size, 0);
    dp[1] = nums[1];
    dp[2] = max(dp[1], nums[2]);
    for (int i = 3; i < size; i++) {
      dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    res_without_first = dp[size - 1];

    dp[0] = dp[1] = nums[0];
    for (int i = 2; i < size - 1; i++) {
      dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    res_with_first = dp[size - 2];
    res = max(res_with_first, res_without_first);
    return res;
  }
};
// @lc code=end
