/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */
// 算法逻辑有问题，要注意if要不要加else，注意分支的情况
#include <vector>
#include <limits>
using namespace std;

// @lc code=start
class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> dp(n);
    vector<int> indexes(primes.size(), 0);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
      int next;
      int min_value = numeric_limits<int>::max();
      int min_index = 0;
      for (int j = 0; j < indexes.size(); j++) {
        if (dp[indexes[j]] * primes[j] == dp[i - 1]) {
          indexes[j]++;
        }
        if (dp[indexes[j]] * primes[j] < min_value) {
          min_value = dp[indexes[j]] * primes[j];
          min_index = j;
        }
      }
      indexes[min_index]++;
      dp[i] = min_value;
    }
    return dp[n - 1];
  }
};
// @lc code=end
