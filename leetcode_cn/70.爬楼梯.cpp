/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include <vector>
using namespace std;

//保存所有动态规划情况
/* class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1 || n == 2) {
      return n;
    }
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < n + 1; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
}; */

//只保存动态规划的最后结果
class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1 || n == 2) {
      return n;
    }
    int m = 1;
    int p = 2;
    for (int i = 3; i < n + 1; i++) {
      int temp = m + p;
      m = p;
      p = temp;
    }
    return p;
  }
};
// @lc code=end
