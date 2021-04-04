/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start

#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    auto cmp = [](pair<int, int> &p1, pair<int, int> &p2) {
      return p1.second > p2.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(
        cmp);

    for (auto num : nums) {
      m[num]++;
    }
    for (auto pair : m) {
      if (q.size() < k) {
        q.push(pair);
      } else if (q.top().second < pair.second) {
        q.pop();
        q.push(pair);
      }
    }
    vector<int> res;
    while (!q.empty()) {
      int key_value = q.top().first;
      res.push_back(key_value);
      q.pop();
    }
    return res;
  };
};
// @lc code=end
