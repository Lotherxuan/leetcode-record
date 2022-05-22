/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
 public:
  int maxArea(vector<int>& height) {
    auto left = height.begin();
    auto right = height.end() - 1;
    int max = -1;
    int current;
    while (left < right) {
      current = distance(left, right) * min(*left, *right);
      if (current > max) {
        max = current;
      }
      if (*left >= *right) {
        right--;
      } else {
        left++;
      }
    }
    return max;
  }
};
// @lc code=end
