/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
#include <algorithm>
#include <limits.h>
#include <vector>

using namespace std;
class Solution {
public:
  bool increasingTriplet(vector<int> &nums) {
    if (nums.size() < 3) {
      return false;
    }
    // min_num: the samllest, mid_num: the second smallest;
    int min_num = INT_MAX;
    int mid_num = INT_MAX;
    for (int i : nums) {
      if (i > mid_num) {
        return true;
      } else if (i < min_num) {
        min_num = i;
      } else if (i > min_num && i < mid_num) {
        mid_num = i;
      }
    }
    return false;
  }
};
// @lc code=end
