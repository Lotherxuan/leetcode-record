/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

#include <vector>
#include <stack>
#include <limits>
using namespace std;

// 在maximalRectangl函数中调用第84题的函数的过程中写了bug，原因是没有注意到传的是值还是引用，事实上由于84题采取了两端哨兵值的做法，导致传入的数组实际上是被改变了的
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
  int maximalRectangle(vector<vector<char>>& matrix) {
    int max_area = 0;
    if (matrix.empty()) {
      return 0;
    }
    vector<int> cur_height(matrix[0].size(), 0);
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < cur_height.size(); j++) {
        if (matrix[i][j] == '0') {
          cur_height[j] = 0;
        } else {
          cur_height[j]++;
        }
      }
      vector<int> copy_height(cur_height);
      int cur_area = largestRectangleArea(copy_height);
      if (cur_area > max_area) {
        max_area = cur_area;
      }
    }
    return max_area;
  }
};
// @lc code=end
