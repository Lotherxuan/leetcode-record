/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

#include <string>
#include <vector>
using namespace std;

//暴力搜索 递归 Time Limit Exceeded

// @lc code=start
/* class Solution {
 public:
  bool isMatch(string s, string p) {
    if (!p.size()) {
      if (!s.size() && !p.size()) {
        return true;
      } else {
        return false;
      }
    }
    if (!s.size()) {
      if (p.size() >= 2 && p[1] == '*') {
        return isMatch(s, p.substr(2, p.size()));
      } else {
        return false;
      }
    }
    bool first_match = (p[0] == s[0]) || (p[0] == '.');
    if (p.size() >= 2 && p[1] == '*') {
      return isMatch(s, p.substr(2, p.size())) ||
             (isMatch(s.substr(1, s.size()), p) && first_match);
    } else {
      return first_match &&
             (isMatch(s.substr(1, s.size()), p.substr(1, p.size())));
    }
    return false;
  }
}; */

//带dp_table的搜索 自顶向下搜索
//使用vector的时候一定一定要注意下标访问和边界条件的冲突
/* Your runtime beats 30.91 % of cpp submissions
Your memory usage beats 16.52 % of cpp submissions (12.1 MB) */

class Solution {
 public:
  bool isMatchWithTable(string s, string p, vector<vector<int>> &dp_table) {
    if (!p.size()) {
      if (!s.size() && !p.size()) {
        return true;
      } else {
        return false;
      }
    }
    if (!s.size()) {
      if (p.size() >= 2 && p[1] == '*') {
        return isMatchWithTable(s, p.substr(2, p.size()), dp_table);
      } else {
        return false;
      }
    }
    int row = dp_table.size();
    int column = dp_table[0].size();
    int s_length = s.size();
    int p_length = p.size();

    bool first_match = (p[0] == s[0]) || (p[0] == '.');
    if (p.size() >= 2 && p[1] == '*') {
      bool match_pattern1;
      bool match_pattern2;
      bool res;
      if (p.size() == 2) {
        match_pattern1 = isMatchWithTable(s, p.substr(2, p.size()), dp_table);
        //不查询dp_table
      } else if (dp_table[row - s_length][column - p_length + 2] == -1) {
        match_pattern1 = isMatchWithTable(s, p.substr(2, p.size()), dp_table);
        dp_table[row - s_length][column - p_length + 2] = (int)match_pattern1;
        //查询dp_table,表中无记录
      } else {
        match_pattern1 = (bool)dp_table[row - s_length][column - p_length + 2];
        //表中有记录，直接使用表中的记录
      }

      if (s.size() == 1) {
        match_pattern2 = isMatchWithTable(s.substr(1, s.size()), p, dp_table);
      } else if (dp_table[row - s_length + 1][column - p_length] == -1) {
        match_pattern2 = isMatchWithTable(s.substr(1, s.size()), p, dp_table);
        dp_table[row - s_length + 1][column - p_length] = (int)match_pattern2;
      } else {
        match_pattern2 = (bool)dp_table[row - s_length + 1][column - p_length];
      }
      res = match_pattern1 || (match_pattern2 && first_match);
      dp_table[row - s_length][column - p_length] = (int)res;
      return res;
    } else {
      bool match_pattern;
      bool res;
      if (s.size() == 1 || p.size() == 1) {
        match_pattern = isMatchWithTable(s.substr(1, s.size()),
                                         p.substr(1, p.size()), dp_table);
      } else if (dp_table[row - s_length + 1][column - p_length + 1] == -1) {
        match_pattern = isMatchWithTable(s.substr(1, s.size()),
                                         p.substr(1, p.size()), dp_table);
        dp_table[row - s_length + 1][column - p_length + 1] =
            (int)match_pattern;
      } else {
        match_pattern =
            (bool)dp_table[row - s_length + 1][column - p_length + 1];
      }

      res = first_match && match_pattern;
      dp_table[row - s_length][column - p_length] = (int)res;
      return res;
    }
    return false;
  }
  bool isMatch(string s, string p) {
    vector<vector<int>> dp_table(s.size(), vector<int>(p.size(), -1));
    return isMatchWithTable(s, p, dp_table);
  }
};
// @lc code=end
