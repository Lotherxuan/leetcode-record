/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// @lc code=start

//暴力搜索 Time Limit Exceeded
/* class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    if (!text1.size() || !text2.size()) {
      return 0;
    } else {
      if (text1[text1.size() - 1] == text2[text2.size() - 1]) {
        return longestCommonSubsequence(text1.substr(0, text1.size() - 1),
                                        text2.substr(0, text2.size() - 1)) +
               1;
      } else {
        return max(longestCommonSubsequence(text1.substr(0, text1.size() - 1),
                                            text2.substr(0, text2.size())),
                   longestCommonSubsequence(text1.substr(0, text1.size()),
                                            text2.substr(0, text2.size() - 1)));
      }
    }
    return 0;
  }
}; */

//自底向上遍历
/* Your runtime beats 40.73 % of cpp submissions
Your memory usage beats 44.78 % of cpp submissions (12.6 MB) */
class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    if (text1.size() < text2.size()) {
      return longestCommonSubsequence(text2, text1);
    } else {
      vector<vector<int>> dp_table(text1.size() + 1,
                                   vector<int>(text2.size() + 1));
      for (size_t i = 0; i < dp_table.size(); i++) {
        for (size_t j = 0; j < dp_table[0].size(); j++) {
          if (!i || !j) {
            dp_table[i][j] = 0;
          }
        }
      }
      int row = dp_table.size();
      int column = dp_table[0].size();
      for (int i = 1; i < row; i++) {
        for (int j = 1; j < column; j++) {
          if (text1[i - 1] == text2[j - 1]) {
            dp_table[i][j] = dp_table[i - 1][j - 1] + 1;
          } else {
            dp_table[i][j] = max(dp_table[i - 1][j], dp_table[i][j - 1]);
          }
        }
      }
      return dp_table[text1.size()][text2.size()];
    }
    return 0;
  }
};
// @lc code=end
