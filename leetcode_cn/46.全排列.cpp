/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
// class Solution {
//  public:
//   vector<vector<int>> permute(vector<int>& nums) {
//     vector<vector<int>> res;
//     if (nums.size() == 1) {
//       res.push_back(vector<int>({nums[0]}));
//       return res;
//     }
//     for (int i = 0; i < nums.size(); i++) {
//       auto temp = nums;
//       temp.erase(temp.begin() + i);
//       vector<vector<int>> rec_res = permute(temp);
//       for (auto v : rec_res) {
//         v.push_back(nums[i]);
//         res.push_back(v);
//       }
//     }
//     return res;
//   }
// };

//深度优先回溯搜索
class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<int> track;
    vector<vector<int>> res;
    backtrace(nums, track, res);
    return res;
  }
  void backtrace(vector<int>& nums, vector<int>& track,
                 vector<vector<int>>& res) {
    if (track.size() == nums.size()) {
      res.push_back(track);
    } else {
      for (auto num : nums) {
        if (find(track.begin(), track.end(), num) == track.end()) {
          track.push_back(num);
          backtrace(nums, track, res);
          track.pop_back();
        }
      }
    }
  }
};
// @lc code=end
