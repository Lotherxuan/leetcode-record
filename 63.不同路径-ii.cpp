/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int row = obstacleGrid.size();
    int column = obstacleGrid[0].size();
    vector<int> cur(column);
    cur[0] = (obstacleGrid[0][0] == 0);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < column; j++) {
        if (obstacleGrid[i][j]) {
          cur[j] = 0;
          continue;
        } else if ((j - 1) >= 0 && obstacleGrid[i][j - 1] == 0) {
          cur[j] += cur[j - 1];
        }
      }
    }
    return cur.back();
  }
};
// @lc code=end
