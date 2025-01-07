/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
    }
    if (sum % k != 0) return false;
    sum = sum / k;
    if (nums[nums.size() - 1] > sum) {
      return false;
    }
    int sumNeeded[7];
    for (int j = 0; j < 4; j++) {
      sumNeeded[j] = sum;
    }
    for (int j = 0; j < 4; j++) {
      cout << sumNeeded[j] << " ";
    }
    bool result = help(nums, nums.size() - 1, sumNeeded, k);
    return result;
  }

  bool help(vector<int>& nums, int pointer, int sumNeeded[], int k) {
    if (pointer < 0) {
      return true;
    }
    for (int i = 0; i < k; i++) {
      if (sumNeeded[i] == nums[pointer] ||
          (sumNeeded[i] - nums[pointer] >= nums[0])) {
        sumNeeded[i] -= nums[pointer];

        if (help(nums, pointer - 1, sumNeeded, k)) {
          return true;
        }
        sumNeeded[i] += nums[pointer];
      }
    }
    return false;
  }
};
// @lc code=end
