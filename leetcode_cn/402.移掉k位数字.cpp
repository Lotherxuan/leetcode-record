/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */
// 考虑空串和零的情形

#include <vector>
#include <deque>
#include <string>
using namespace std;
// @lc code=start
class Solution {
 public:
  string removeKdigits(string num, int k) {
    deque<char> min_stack;
    string res;
    int delete_count = 0;
    for (auto c : num) {
      if (delete_count == k) {
        if (min_stack.empty()) {
          res.push_back(c);
        } else {
          while (!min_stack.empty()) {
            if (!(res == "" && min_stack.front() == '0')) {
              res.push_back(min_stack.front());
            }
            min_stack.pop_front();
          }
          res.push_back(c);
        }
        continue;
      }
      while ((min_stack.empty() || c < min_stack.back()) && delete_count != k) {
        if (min_stack.empty()) {
          break;
        } else {
          min_stack.pop_back();
          delete_count++;
        }
      }
      min_stack.push_back(c);
    }
    while (delete_count < k) {
      min_stack.pop_back();
      delete_count++;
    }
    while (!min_stack.empty()) {
      if (!(res == "" && min_stack.front() == '0')) {
        res.push_back(min_stack.front());
      }
      min_stack.pop_front();
    }
    return res == "" ? "0" : res;
  }
};
// @lc code=end
