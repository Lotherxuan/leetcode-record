/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size();
    if (n == 0 || n == 1 || n == 2) {
      return 0;
    } else if (n == 3) {
      if (A[2] - A[1] != A[1] - A[0]) {
        return 0;
      } else {
        return 1;
      }

    } else {
      vector<int> dp(n, 0);
      int sum = 0;
      for (int i = 2; i < n; i++) {
        if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
          dp[i] = dp[i - 1] + 1;
          sum += dp[i];
        }
      }
      return sum;
    }
    return -1;
  }
};
// @lc code=end
