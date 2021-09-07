/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

// dp[i][j]=max{dp[i][j-2]+2(s[j]=='(',
// s[j-1]==')'),dp[i][j-2]+2(s[j]==)}
class Solution {
 public:
  int longestValidParentheses(string s) {
    int length = s.size();
    vector<vector<int>> dp(length, vector<int>(length));
    int max_length = -1;
  }
};
// @lc code=end
