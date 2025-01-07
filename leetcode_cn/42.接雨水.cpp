/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int trap(vector<int>& height) {
    int size = height.size();
    vector<int> left_max(size, 0);
    vector<int> right_max(size, 0);
    int sum = 0;
    for (int i = 1; i < size - 1; i++) {
      left_max[i] = max(left_max[i - 1], height[i - 1]);
    }
    for (int i = size - 2; i >= 0; i--) {
      right_max[i] = max(right_max[i + 1], height[i + 1]);
    }
    for (int i = 0; i < size - 1; i++) {
      int min_height = min(left_max[i], right_max[i]);
      if (height[i] < min_height) {
        sum += min_height - height[i];
      }
    }
    return sum;
  }
};
// @lc code=end
