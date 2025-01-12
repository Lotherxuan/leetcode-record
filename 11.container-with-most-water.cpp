/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
  int maxArea(vector<int> &height) {
    if (height.size() < 2) {
      return 0;
    }
    int start_index = 0;
    int end_index = height.size() - 1;
    int max_area =
        min(height[start_index], height[end_index]) * (end_index - start_index);
    while ((end_index - start_index) > 1) {
      if (height[start_index] < height[end_index]) {
        start_index++;
      } else {
        end_index--;
      }
      max_area = max(max_area, min(height[start_index], height[end_index]) *
                                   (end_index - start_index));
    }
    return max_area;
  }
};
// @lc code=end
