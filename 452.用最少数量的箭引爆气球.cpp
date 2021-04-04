/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
// @lc code=start
class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) {
      return 0;
    }
    sort(points.begin(), points.end(),
         [](auto& v0, auto& v1) { return v0[1] < v1[1]; });
    int res = 1;
    int cur = points[0][1];
    if (points.size() == 1) {
      return res;
    }
    for (auto i = points.begin() + 1; i < points.end(); i++) {
      if ((*i)[0] <= cur) {
        continue;
      } else {
        res++;
        cur = (*i)[1];
      }
    }
    return res;
  }
};
// @lc code=end
