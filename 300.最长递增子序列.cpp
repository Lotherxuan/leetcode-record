/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    vector<int> dp(size);
    dp[0] = 1;
    for (int i = 1; i < size; i++) {
      int max = 1;
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          if (dp[j] + 1 > max) {
            max = dp[j] + 1;
          }
        }
      }
      dp[i] = max;
    }
    int res = *max_element(dp.begin(), dp.end());
    return res;
  };
};

// @lc code=end
