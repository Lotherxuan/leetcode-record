/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include <vector>
#include <stack>
#include <limits>
using namespace std;
// @lc code=start
class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    heights.insert(heights.begin(), numeric_limits<int>::min());
    heights.push_back(numeric_limits<int>::min());
    s.push(0);
    int cur_index = 1;
    int max_area = numeric_limits<int>::min();
    while (cur_index < heights.size()) {
      while (heights[cur_index] < heights[s.top()]) {
        int height = heights[s.top()];
        s.pop();
        int left_index = s.top();
        int width = cur_index - left_index - 1;
        int area = height * width;
        if (area > max_area) {
          max_area = area;
        }
      }
      s.push(cur_index);
      cur_index++;
    }
    return max_area;
  }
};
// @lc code=end
