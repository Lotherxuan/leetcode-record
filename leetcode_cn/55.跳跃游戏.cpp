/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    if (nums.empty()) {
      return false;
    }
    int end_index = nums.size() - 1;
    vector<bool> dp(end_index + 1, false);
    dp[end_index] = true;
    for (int cur_i = end_index - 1; cur_i >= 0; cur_i--) {
      for (int n = nums[cur_i]; n > 0; n--) {
        if (dp[cur_i + n]) {
          dp[cur_i] = true;
        }
      }
    }
    return dp[0];
  }
};
// @lc code=end
