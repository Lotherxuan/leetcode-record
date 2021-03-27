/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int size = nums.size();
    if (!size) {
      return -1;
    }
    if (size == 1) {
      return target == nums[0] ? 0 : -1;
    }
    int left = 0;
    int right = size - 1;
    int middle = 0;
    while (left <= right) {
      middle = (left + right) / 2;
      if (target == nums[middle]) {
        return middle;
      } else if (nums[0] <= nums[middle]) {
        if (target >= nums[0] && target <= nums[middle]) {
          right = middle - 1;
        } else {
          left = middle + 1;
        }
      } else {
        if (target >= nums[middle] && target <= nums[size - 1]) {
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      }
    }
    return -1;
  }
};
// @lc code=end
