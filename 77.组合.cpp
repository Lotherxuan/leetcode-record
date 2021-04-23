/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<int> track;
    vector<vector<int>> res;
    backtrace(res, track, n, k);
    return res;
  }
  void backtrace(vector<vector<int>>& res, vector<int>& track, int n, int k) {
    if (track.size() == k) {
      res.push_back(track);
      return;
    }
    for (int i = 1; i <= n; i++) {
      if (track.empty() ||
          (find(track.begin(), track.end(), i) == track.end() &&
           i > track.back())) {
        track.push_back(i);
        backtrace(res, track, n, k);
        track.pop_back();
      }
    }
  }
};
// @lc code=end
