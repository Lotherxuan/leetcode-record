/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int trap(vector<int>& height) {
    int end_index = height.size();
    stack<int> s;

    int index = 0;
    while (index < end_index && !height[index]) {
      index++;
    }

    s.push(height[index]);
    index++;

    while (index < end_index) {
      int top = s.top();
      if (height[index] <) }
  }
};
// @lc code=end
