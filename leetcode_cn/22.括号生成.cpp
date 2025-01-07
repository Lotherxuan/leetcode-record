/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string s;
    int left = 0;
    int right = 0;
    backtrace(res, s, left, right, n);
    return res;
  }

  void backtrace(vector<string> &res, string &s, int &left, int &right, int n) {
    if (left == n && right == n) {
      res.push_back(s);
    } else if (left == right) {
      s.push_back('(');
      left++;
      backtrace(res, s, left, right, n);
      s.pop_back();
      left--;
    } else if (left > right) {
      if (left < n) {
        s.push_back('(');
        left++;
        backtrace(res, s, left, right, n);
        s.pop_back();
        left--;

        s.push_back(')');
        right++;
        backtrace(res, s, left, right, n);
        s.pop_back();
        right--;
      } else {
        s.push_back(')');
        right++;
        backtrace(res, s, left, right, n);
        s.pop_back();
        right--;
      }
    }
  }
};
// @lc code=end
