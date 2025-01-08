/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
// #include <algorithm>
// #include <cctype>
// #include <ctype.h>
// #include <string>

// using namespace std;
// don't do well on this problem
class Solution {

public:
  string reverseWords(string s) {
    auto word_begin = s.begin();
    decltype(word_begin) word_end = word_begin;
    while (*word_end == ' ') {
      word_end++;
    }
    if (distance(word_begin, word_end)) {
      s.erase(word_begin, word_end);
    }

    auto word_rbegin = s.rbegin();
    word_end = s.end();
    decltype(word_rbegin) word_rend = word_rbegin;
    while (*word_rend == ' ') {
      word_rend++;
    }
    if (distance(word_rend.base(), word_end)) {
      s.erase(word_rend.base(), word_end);
    }

    string res;
    auto cur_iter = s.begin();
    word_begin = cur_iter;
    bool word_start = true;
    while (cur_iter != s.end()) {
      if (isspace(*cur_iter)) {
        if (word_start) {
          res.insert(res.begin(), word_begin, cur_iter);
          if (*cur_iter == ' ') {
            res.insert(res.begin(), ' ');
          }
          word_start = false;
        }
      } else {
        if (!word_start) {
          word_start = true;
          word_begin = cur_iter;
        }
      }
      cur_iter++;
    }
    res.insert(res.begin(), word_begin, cur_iter);
    return res;
  }
};
// @lc code=end
