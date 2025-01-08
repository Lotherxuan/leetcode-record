/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
// #include <exception>
// #include <string>
// using namespace std;
class Solution {
public:
  // check if str1 is divided by str2
  bool checkDevided(string const &str1, string const &str2) {
    if (str1.length() == 0 || str2.length() == 0) {
      return false;
    } else {
      auto str1_length = str1.length();
      auto str2_length = str2.length();
      if (str1_length % str2_length != 0) {
        return false;
      }
      auto str1_iter = str1.begin();
      auto str2_iter = str2.begin();
      while (str1_iter != str1.end()) {
        str2_iter = str2.begin();
        while (str2_iter != str2.end() && str1_iter != str1.end()) {
          if (*str1_iter++ != *str2_iter++) {
            return false;
          }
        }
      }
      if (str2_iter != str2.end() || str1_iter != str1.end()) {
        return false;
      } else {
        return true;
      }
    }
  }
  string gcdOfStrings(string str1, string str2) {
    if (str1.length() < str2.length()) {
      swap(str1, str2);
    }
    string res(str2);
    while (res.length() != 0) {
      //   if (checkDevided(str2, res)) {
      //     if (checkDevided(str1, res)) {
      //       break;
      //     }
      //   } else {
      //     res.pop_back();
      //   }
      if (checkDevided(str2, res) && checkDevided(str1, res)) {
        break;
      } else {
        res.pop_back();
      }
    }
    return res;
  }
};
// @lc code=end
