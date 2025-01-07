/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */
#include <limits>
// @lc code=start
class Solution {
 public:
  bool isPowerOfTwo(int n) {
    bool res;
    if (!n) {
      return false;
    }
    if (n == std::numeric_limits<int>::min()) {
      return false;
    }

    if (!(n & (n - 1))) {
      res = true;
    } else {
      res = false;
    }
    return res;
  }
};
// @lc code=end
