/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
// #include <string>
// using namespace std;
class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    string res;
    res.reserve(word1.length() + word2.length());
    auto word1_iter = word1.begin();
    auto word2_iter = word2.begin();
    auto res_iter = res.begin();
    while (word1_iter != word1.end() || word2_iter != word2.end()) {
      if (word1_iter != word1.end()) {
        res.push_back(*word1_iter);
        word1_iter++;
      }
      if (word2_iter != word2.end()) {
        res.push_back(*word2_iter);
        word2_iter++;
      }
    }
    return res;
  }
};
// @lc code=end
