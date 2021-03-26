/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if (!matrix.size()) {
      return res;

    } else if (!matrix[0].size()) {
      return res;
    }
    int row_bottom = matrix.size() - 1;
    int row_up = 0;
    int column_right = matrix[0].size() - 1;
    int column_left = 0;
    res.resize((row_bottom + 1) * (column_right + 1));
    int index = 0;
    while (true) {
      for (int column = column_left; column <= column_right; column++) {
        res[index++] = matrix[row_up][column];
      }
      if (++row_up > row_bottom) {
        break;
      }
      for (int row = row_up; row <= row_bottom; row++) {
        res[index++] = matrix[row][column_right];
      }
      if (--column_right < column_left) {
        break;
      }
      for (int column = column_right; column >= column_left; column--) {
        res[index++] = matrix[row_bottom][column];
      }
      if (--row_bottom < row_up) {
        break;
      }

      for (int row = row_bottom; row >= row_up; row--) {
        res[index++] = matrix[row][column_left];
      }
      if (++column_left > column_right) {
        break;
      }
    }
    return res;
  }
};
// @lc code=end
