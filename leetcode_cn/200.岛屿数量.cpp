/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int row_max = grid.size() - 1;
    int column_max = grid[0].size() - 1;
    int res = 0;
    for (int r = 0; r <= row_max; r++) {
      for (int c = 0; c <= column_max; c++) {
        if (grid[r][c] == '1') {
          res++;
          earseIslands(grid, r, c);
        }
      }
    }
    return res;
  }

  void earseIslands(vector<vector<char>>& grid, int row, int column) {
    int row_max = grid.size() - 1;
    int column_max = grid[0].size() - 1;
    queue<pair<int, int>> q;
    grid[row][column] = '0';
    q.push(make_pair(row, column));
    while (!q.empty()) {
      auto cor = q.front();
      int cor_row = cor.first;
      int cor_column = cor.second;
      if (cor_row + 1 <= row_max) {
        if (grid[cor_row + 1][cor_column] == '1') {
          grid[cor_row + 1][cor_column] = '0';
          q.push(make_pair(cor_row + 1, cor_column));
        }
      }
      if (cor_row - 1 >= 0) {
        if (grid[cor_row - 1][cor_column] == '1') {
          grid[cor_row - 1][cor_column] = '0';
          q.push(make_pair(cor_row - 1, cor_column));
        }
      }
      if (cor_column + 1 <= column_max) {
        if (grid[cor_row][cor_column + 1] == '1') {
          grid[cor_row][cor_column + 1] = '0';
          q.push(make_pair(cor_row, cor_column + 1));
        }
      }
      if (cor_column - 1 >= 0) {
        if (grid[cor_row][cor_column - 1] == '1') {
          grid[cor_row][cor_column - 1] = '0';
          q.push(make_pair(cor_row, cor_column - 1));
        }
      }
      q.pop();
    }
  }
};
// @lc code=end
