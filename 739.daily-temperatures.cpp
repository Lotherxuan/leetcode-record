/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    vector<int> res(temperatures.size());
    stack<pair<int, int>> s;
    for (int i = 0; i < temperatures.size(); i++) {
      while (!s.empty() && temperatures[i] > s.top().first) {
        int temperature_index = s.top().second;
        res[temperature_index] = i - temperature_index;
        s.pop();
      }
      s.push(make_pair(temperatures[i], i));
    }
    res[temperatures.size() - 1] = 0;
    return res;
  }
};
// @lc code=end
