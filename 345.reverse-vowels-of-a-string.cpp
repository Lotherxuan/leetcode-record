/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
// #include <iterator>
// #include <string>
// using namespace std;
// time cost : 9min
class Solution {
public:
  bool check_vowels(char const c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
        c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      return true;
    }
    return false;
  }
  string reverseVowels(string s) {
    string vowels_seq;
    for (auto &c : s) {
      //   if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
      //       c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      //     vowels_seq.push_back(c);
      //   }
      if (check_vowels(c)) {
        vowels_seq.push_back(c);
      }
    }
    auto vowels_seq_riter = vowels_seq.rbegin();
    for (int i = 0; i < s.length(); i++) {
      if (check_vowels(s[i])) {
        s[i] = *vowels_seq_riter++;
      }
    }
    return s;
  }
};
// @lc code=end
