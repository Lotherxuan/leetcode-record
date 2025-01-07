/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
 public:
  // int lengthOfLIS(vector<int>& nums) {
  //   int size = nums.size();
  //   vector<int> dp(size);
  //   dp[0] = 1;
  //   for (int i = 1; i < size; i++) {
  //     int max = 1;
  //     for (int j = 0; j < i; j++) {
  //       if (nums[i] > nums[j]) {
  //         if (dp[j] + 1 > max) {
  //           max = dp[j] + 1;
  //         }
  //       }
  //     }
  //     dp[i] = max;
  //   }
  //   int res = *max_element(dp.begin(), dp.end());
  //   return res;
  // };

  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp;
    dp.push_back(nums.front());
    for (auto i = nums.begin() + 1; i < nums.end(); i++) {
      if (*i > dp.back()) {
        dp.push_back(*i);
      } else {
        auto temp = lower_bound(dp.begin(), dp.end(), *i);
        *temp = *i;
      }
    }
    return dp.size();
  };
};

// @lc code=end
