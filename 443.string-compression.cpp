/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
#include <stack>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  int compress(vector<char> &chars) {
    if (chars.size() <= 1) {
      return 1;
    }
    int res = 0;
    char same_char = '\0';
    int same_char_count = 0;
    int cur_index = 0;
    int writing_index = 0;
    while (cur_index <= chars.size()) {
      if (cur_index == chars.size() || chars[cur_index] != same_char) {
        if (same_char_count > 0) {
          chars[writing_index++] = same_char;
          res += 1;
          if (same_char_count > 1) {
            stack<int> char_count_stack;
            while (same_char_count != 0) {
              char_count_stack.push(same_char_count % 10);
              same_char_count /= 10;
            }
            while (!char_count_stack.empty()) {
              chars[writing_index++] = char_count_stack.top() + '0';
              char_count_stack.pop();
              res += 1;
            }
          }
        }
        if (cur_index < chars.size()) {
          same_char_count = 1;
          same_char = chars[cur_index];
        }

      } else {
        same_char_count++;
      }
      cur_index++;
    }
    return res;
  }
};
// @lc code=end
