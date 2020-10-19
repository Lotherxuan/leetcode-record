/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  //二维动态规划表 超时
  /*   bool checkSubarraySum(vector<int>& nums, int k) {
      if (nums.size() < 2) {
        return false;
      }
      if (!k) {
        for (int i = 1; i < nums.size(); i++) {
          if (nums[i] == 0 && nums[i - 1] == 0) return true;
        }
        return false;
      }
      int n = nums.size();
      bool res = false;
      vector<vector<int>> dp(n, vector<int>(n));
      for (int i = 0; i < n; i++) {
        dp[i][i] = nums[i] % k;
      }
      for (int i = 1; i < n; i++) {
        for (int j = 0; i + j < n; j++) {
          dp[j][i + j] = (dp[j][i + j - 1] + nums[i + j]) % k;
          if (dp[j][i + j] == 0) return true;
        }
      }

      return res;
    } */
    //没有完全靠自己写出来，建议再写一次
  bool checkSubarraySum(vector<int>& nums, int k) {
    if (nums.size() < 2) {
      return false;
    }
    if (!k) {
      for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == 0 && nums[i - 1] == 0) return true;
      }
      return false;
    }
    int n = nums.size();
    unordered_map<int, int> res;
    int i = 0;
    while (true) {
      if (i != 0 && nums[i] % k == 0)
        return true;
      else {
        if (res.find(nums[i] % k) == res.end()) {
          res[nums[i] % k] = i;
        } else {
          if (i - res[nums[i] % k] > 1) return true;
        }
      }
      i++;
      if (i == nums.size()) return false;
      nums[i] += nums[i - 1];
    }
  }
};
// @lc code=end
