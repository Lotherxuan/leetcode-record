/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */
#include <algorithm>
#include <vector>
using namespace std;

//时间复杂度O(n^2) 动态规划 自底向上构造dp_table
// @lc code=start
class Solution {
 public:
  void lengthOfLISWithTable(vector<int>& nums, vector<int>& dp_table) {
    for (size_t i = 0; i < nums.size(); i++) {
      for (size_t j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          dp_table[i] = max(dp_table[i], dp_table[j] + 1);
        }
      }
    }
  }
  int lengthOfLIS(vector<int>& nums) {
    if (!nums.size()) return 0;
    vector<int> dp_table(nums.size(), 1);
    lengthOfLISWithTable(nums, dp_table);
    return *max_element(dp_table.begin(), dp_table.end());
  }
};
// @lc code=end
