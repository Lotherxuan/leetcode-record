/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0) {
        }
      }
    }
  }
};
// @lc code=end
