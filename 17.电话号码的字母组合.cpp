/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> res;
    multimap<char, char> char_map;
    char_map.insert(make_pair('2', 'a'));
    char_map.insert(make_pair('2', 'b'));
    char_map.insert(make_pair('2', 'c'));
    char_map.insert(make_pair('3', 'd'));
    char_map.insert(make_pair('3', 'e'));
    char_map.insert(make_pair('3', 'f'));
    char_map.insert(make_pair('4', 'g'));
    char_map.insert(make_pair('4', 'h'));
    char_map.insert(make_pair('4', 'i'));
    char_map.insert(make_pair('5', 'j'));
    char_map.insert(make_pair('5', 'k'));
    char_map.insert(make_pair('5', 'l'));
    char_map.insert(make_pair('6', 'm'));
    char_map.insert(make_pair('6', 'n'));
    char_map.insert(make_pair('6', 'o'));
    char_map.insert(make_pair('7', 'p'));
    char_map.insert(make_pair('7', 'q'));
    char_map.insert(make_pair('7', 'r'));
    char_map.insert(make_pair('7', 's'));
    char_map.insert(make_pair('8', 't'));
    char_map.insert(make_pair('8', 'u'));
    char_map.insert(make_pair('8', 'v'));
    char_map.insert(make_pair('9', 'w'));
    char_map.insert(make_pair('9', 'x'));
    char_map.insert(make_pair('9', 'y'));
    char_map.insert(make_pair('9', 'z'));
    string current;
    if (digits.size() == 0) {
      ;
    } else {
      backtrace(res, char_map, digits, 0, current);
    }
    return res;
  }
  void backtrace(vector<string>& res, multimap<char, char>& char_map,
                 string& digits, int index, string& current) {
    if (index == digits.size()) {
      res.push_back(current);
      return;
    } else {
      auto range = char_map.equal_range(digits[index]);
      for (auto i = range.first; i != range.second; i++) {
        current.push_back(i->second);
        backtrace(res, char_map, digits, index + 1, current);
        current.pop_back();
      }
    }
  }
};
// @lc code=end
