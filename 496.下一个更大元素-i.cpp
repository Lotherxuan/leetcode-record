/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    vector<int> res;
    unordered_map<int, int> hash;
    for (int i = 0; i < nums2.size(); i++) {
      if (s.empty()) {
        s.push(nums2[i]);
      } else {
        while (!s.empty() && nums2[i] > s.top()) {
          hash[s.top()] = nums2[i];
          s.pop();
        }
        s.push(nums2[i]);
      }
    }
    while (!s.empty()) {
      hash[s.top()] = -1;
      s.pop();
    }
    for (auto i : nums1) {
      res.push_back(hash[i]);
    }
    return res;
  }
};
// @lc code=end
