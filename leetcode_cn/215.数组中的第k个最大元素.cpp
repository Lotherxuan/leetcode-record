/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<>> q;
    for (auto i : nums) {
      if (q.size() < k) {
        q.push(i);
      } else {
        if (i > q.top()) {
          q.pop();
          q.push(i);
        }
      }
    }
    return q.top();
  }
};
// @lc code=end
