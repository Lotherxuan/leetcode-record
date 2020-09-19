/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

#include <vector>
using namespace std;

// @lc code=start

//自底向上构造dp表 保存所有信息，内存使用较多，存在优化空间
/* class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n));
    if (m < n) {
      return uniquePaths(n, m);
    }
    dp[0][0] = 1;
    for (int i = 1; i < m; i++) {
      for (int j = 0; (j < n) && (i - j) >= 0; j++) {
        if (!j || !(i - j)) {
          dp[i - j][j] = 1;
        } else {
          dp[i - j][j] = dp[i - j - 1][j] + dp[i - j][j - 1];
        }
      }
    }
    for (int sum = m; sum <= m + n - 2; sum++) {
      for (int j = sum - m + 1; j < n; j++) {
        dp[sum - j][j] = dp[sum - j - 1][j] + dp[sum - j][j - 1];
      }
    }

    return dp[m - 1][n - 1];
  }
}; */

//只保存当前行和上一行的信息，空间复杂度从O(m*n)减少到O(n)
/* class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<int> pre(n, 1), cur(n, 1);
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        cur[j] = cur[j - 1] + pre[j];
      }
      swap(pre, cur);
    }
    return pre[n - 1];
    //此时cur被pre交换过一次 故return到pre[n-1]
  }
}; */

//只保存当前行的信息 进一步减少空间复杂度
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<int> row(n, 1);
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        row[j] += row[j - 1];
      }
    }
    return row[n - 1];
  }
};
// @lc code=end
