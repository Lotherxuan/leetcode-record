/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// 先想好算法再开始写程序！在算法阶段就考虑各种情况！
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
 public:
  string removeDuplicateLetters(string s) {
    string res;
    queue<char> max_stack;
    unordered_map<char, int> m;
    for (auto c : s) {
      m[c]++;
    }
    for (auto c : s) {
      if (max_stack.empty()) {
      }
    }
    //   while (!max_s.empty()) {
    //     auto c = max_s.top();
    //     if (m[c] == 1) {
    //       res.push_back(c);
    //     }
    //     max_s.pop();
    //     m[c]--;
    //   }
    return res;
  }
};
// @lc code=end
