/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() == 1) {
      res.push_back(vector<int>({nums[0]}));
      return res;
    }
    for (int i = 0; i < nums.size(); i++) {
      auto temp = nums;
      temp.erase(temp.begin() + i);
      vector<vector<int>> rec_res = permute(temp);
      for (auto v : rec_res) {
        v.push_back(nums[i]);
        res.push_back(v);
      }
    }
    return res;
  }
};
// @lc code=end
