/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for (int i = 0; i < size - 2; i++) {
      int target = -nums[i];
      int front = i + 1;
      int back = size - 1;
      while (front < back) {
        if (nums[front] + nums[back] == target) {
          int front_value = nums[front];
          int back_value = nums[back];
          res.push_back(vector<int>{-target, nums[front], nums[back]});
          while (nums[front] == front_value) {
            front++;
          }
          while (nums[back] == back_value) {
            back--;
          }

        } else if (nums[front] + nums[back] < target) {
          front++;
        } else {
          back--;
        }
      }
      while (i + 1 < size && nums[i] == nums[i + 1]) {
        i++;
      }
    }
    return res;
  }
};
// @lc code=end
