/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include <vector>
#include <stack>
using namespace std;
// 访问容器元素时一定要检查容器是否为空，比如说s.top()这样的操作
// 还忘记了s.pop()
// 只有两个bug 好耶！有进步！
// @lc code=start
class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> s;
    vector<int> res(nums.size());

    if (nums.empty()) {
      return res;
    }
    if (nums.size() == 1) {
      res[0] = -1;
      return res;
    }
    int cur_index = 1;
    s.push(0);
    while (!s.empty() && cur_index < nums.size()) {
      while (!s.empty() && nums[cur_index] > nums[s.top()]) {
        res[s.top()] = nums[cur_index];
        s.pop();
      }
      s.push(cur_index);
      cur_index++;
    }
    cur_index = 0;
    while (!s.empty() && cur_index < s.top()) {
      while (!s.empty() && nums[cur_index] > nums[s.top()]) {
        res[s.top()] = nums[cur_index];
        s.pop();
      }
      cur_index++;
    }
    while (!s.empty()) {
      res[s.top()] = -1;
      s.pop();
    }
    return res;
  }
};
// @lc code=end
