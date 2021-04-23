/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> track;
    vector<vector<int>> res;
    backtrace(res, nums, track);
    return res;
  }

  void backtrace(vector<vector<int>>& res, vector<int>& nums,
                 vector<int> track) {
    res.push_back(track);
    for (auto num : nums) {
      if (track.empty() ||
          (find(track.begin(), track.end(), num) == track.end() &&
           num > track.back()))

      {
        track.push_back(num);
        backtrace(res, nums, track);
        track.pop_back();
      }
    }
  }
};
// @lc code=end
