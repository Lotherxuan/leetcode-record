/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <vector>
#include <queue>
#include <deque>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
 public:
  // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  //   vector<int> res;
  //   int left = 0;
  //   int right = left + k;
  //   deque<int> dq;
  //   for (int i = left; i < right; i++) {
  //     if (dq.empty()) {
  //       dq.push_back(nums[i]);

  //     } else {
  //       while (!dq.empty() && nums[i] > dq.back()) {
  //         dq.pop_back();
  //       }
  //       dq.push_back(nums[i]);
  //     }
  //   }
  //   res.push_back(dq.front());
  //   left++;
  //   right++;
  //   while (right <= res.size()) {
  //     if (dq.front() == nums[left - 1]) {
  //       dq.pop_front();
  //     }
  //     while (!dq.empty() && nums[right - 1] > dq.back()) {
  //       dq.pop_back();
  //     }
  //     dq.push_back(nums[right - 1]);
  //     res.push_back(dq.front());
  //     left++;
  //     right++;
  //   }
  //   return res;
  // }
  // 优先队列很麻烦，要存二元组，干脆不写了。
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<int> pri_q;
    int left = 0;
    int right = left + 1;
    for (int i = left; i < right; i++) {
    }
  }
};
// @lc code=end
