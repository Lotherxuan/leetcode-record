/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int jump(vector<int>& nums) {
    int jump_count = 0;
    int cur_index = 0;
    int end_index = nums.size() - 1;
    while (cur_index < end_index) {
      int max_length = 0;
      int max_chose_index = 0;
      for (int n = 0; n <= nums[cur_index] && (cur_index + n) <= end_index;
           n++) {
        if (n == 0) {
          continue;
        }
        if (cur_index + n == end_index) {
          jump_count++;
          return jump_count;
        }
        int length = cur_index + n + nums[cur_index + n];
        if (length >= max_length) {
          max_length = length;
          max_chose_index = n;
        }
      }
      cur_index += max_chose_index;
      jump_count++;
      if (cur_index >= end_index) {
        break;
      }
    }
    return jump_count;
  }
};
// @lc code=end
