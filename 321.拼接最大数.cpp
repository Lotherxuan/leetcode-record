/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    vector<vector<int>> dp(size1, vector<int>(size2));
  }
};
// @lc code=end
