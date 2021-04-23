/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
// 没有完全ac 还没着手测试是什么问题
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) { backtrace(board, 0, 0); }
  bool backtrace(vector<vector<char>>& board, int row, int column) {
    int row_size = board.size();
    int column_size = board[0].size();
    if ((row == (row_size - 1)) && (column == column_size - 1)) {
      if (board[row][column] != '.') {
        return true;
      } else {
        for (char c = '1'; c < '9'; c++) {
          if (check(board, row, column, c)) {
            board[row][column] = c;
            return true;
          }
        }
        return false;
      }
    } else {
      if (board[row][column] != '.') {
        return backtrace_next(board, row, column);
      } else {
        for (char c = '1'; c <= '9'; c++) {
          if (check(board, row, column, c)) {
            board[row][column] = c;
            if (backtrace_next(board, row, column)) {
              return true;
            }
          } else {
            continue;
          }
        }
        board[row][column] = '.';
        return false;
      }
    }
    return false;
  }
  bool backtrace_next(vector<vector<char>>& board, int row, int column) {
    int row_size = board.size();
    int column_size = board[0].size();
    if (column == column_size - 1) {
      return backtrace(board, row + 1, 0);
    } else {
      return backtrace(board, row, column + 1);
    }
    return true;
  }
  bool check(vector<vector<char>>& board, int row, int column, char c) {
    bool res = true;
    int row_size = board.size();
    int column_size = board[0].size();
    for (int i = 0; i < column_size; i++) {
      if (i != column) {
        if (c == board[row][i]) {
          return false;
        }
      }
    }
    for (int i = 0; i < row_size; i++) {
      if (i != row) {
        if (c == board[i][column]) {
          return false;
        }
      }
    }

    int block_row = row / 3;
    int block_column = column / 3;
    for (int i = block_row * 3; i < block_row * 3 + 3; i++) {
      for (int j = block_column * 3; j < block_column * 3 + 3; j++) {
        if (i != row && j != column) {
          if (c == board[i][j]) {
            return false;
          }
        }
      }
    }
    return res;
  }
};
// @lc code=end
