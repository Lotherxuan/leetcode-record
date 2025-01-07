/*
 * @lc app=leetcode.cn id=793 lang=cpp
 *
 * [793] 阶乘函数后 K 个零
 */

#include <limits>
using namespace std;
// @lc code=start
class Solution {
 public:
  int zeros(long m, int k) {
    long ans = 0, f = 5;
    while (m / f) {
      ans += (m / f);
      if (ans > k) return k + 1;
      f *= 5;
    }
    return ans;
  }
  int preimageSizeFZF(int k) {
    long l = 1, h = LONG_MAX;
    while (l <= h) {
      long m = l + (h - l) / 2;
      if (zeros(m, k) > k)
        h = m - 1;
      else if (zeros(m, k) < k)
        l = m + 1;
      else
        return 5;
    }
    return 0;
  }
  //   int preimageSizeFZF(int K) {
  //     return FindRightBoundary(K) - FindLeftBoundary(K) + 1;
  //   }
  //   long FindLeftBoundary(int k) {
  //     long right = 1e9 + 1;
  //     long left = 0;
  //     long mid;
  //     while (left < right) {
  //       mid = left + (right - left) / 2;
  //       if (trailingZeroes(mid) == k) {
  //         right = mid;
  //       } else if (trailingZeroes(mid) > k) {
  //         right = mid;
  //       } else if (trailingZeroes(mid) < k) {
  //         left = mid + 1;
  //       }
  //     }
  //     return left;
  //   }
  //   long FindRightBoundary(int k) {
  //     long right = 1e9 + 1;
  //     long left = 0;

  //     long mid;
  //     while (left < right) {
  //       mid = left + (right - left) / 2;
  //       if (trailingZeroes(mid) == k) {
  //         left = mid + 1;
  //       } else if (trailingZeroes(mid) > k) {
  //         right = mid;
  //       } else if (trailingZeroes(mid) < k) {
  //         left = mid + 1;
  //       }
  //     }
  //     return left - 1;
  //   }
  //   int trailingZeroes(long n) {
  //     int res = 0;
  //     long long divider = 5;
  //     while (divider <= n) {
  //       res += n / divider;
  //       divider *= 5;
  //     }
  //     return res;
  //   }
};
// @lc code=end
