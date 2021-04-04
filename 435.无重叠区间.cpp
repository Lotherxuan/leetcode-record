/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
      return 0;
    }
    int res = 0;
    sort(intervals.begin(), intervals.end(),
         [](auto& v1, auto& v2) { return v1[1] <= v2[1]; });
    int cur_end = intervals[0][1];
    for (auto i = intervals.begin() + 1; i < intervals.end(); i++) {
      if ((*i)[0] < cur_end) {
        res++;
      } else {
        cur_end = (*i)[1];
      }
    }
    return res;
  }
};
// @lc code=end
