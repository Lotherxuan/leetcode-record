/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// 先想好算法再开始写程序！在算法阶段就考虑各种情况！
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
 public:
  string removeDuplicateLetters(string s) {
    string res;
    deque<char> min_stack;
    unordered_map<char, int> m;
    unordered_map<char, bool> instack;
    for (auto c : s) {
      m[c]++;
      instack[c] = false;
    }
    for (auto c : s) {
      m[c]--;
      if (instack[c]) {
        continue;
      }
      if (min_stack.empty()) {
        min_stack.push_back(c);
        instack[c] = true;
      } else {
        while (!min_stack.empty() && c < min_stack.back()) {
          char c_back = min_stack.back();
          if (m[c_back] == 0) {
            break;
          } else {
            min_stack.pop_back();
            instack[c_back] = false;
          }
        }
        min_stack.push_back(c);
        instack[c] = true;
      }
    }
    while (!min_stack.empty()) {
      res.push_back(min_stack.front());
      min_stack.pop_front();
    }

    return res;
  }
};
// @lc code=end
