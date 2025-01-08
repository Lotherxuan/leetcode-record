/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
// #include <algorithm>
// #include <vector>

// using namespace std;
// time cost: 5min
class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    auto max_value = max_element(candies.begin(), candies.end());
    auto check_value = *max_value - extraCandies;
    vector<bool> res(candies.size());
    for (int i = 0; i < candies.size(); i++) {
      res[i] = candies[i] >= check_value;
    }
    return res;
  }
};
// @lc code=end
