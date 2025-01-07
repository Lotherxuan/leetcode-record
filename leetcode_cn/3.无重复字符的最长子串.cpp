/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (!s.size())
        {
            return 0;
        }
        unordered_set<char> char_set;
        int max_length = 0;
        int left_pointer = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            while (char_set.find(s[i]) != char_set.end())
            {

                char_set.erase(s[left_pointer]);
                left_pointer++;
            }
            char_set.insert(s[i]);
            if (i - left_pointer + 1 > max_length)
            {
                max_length = i - left_pointer + 1;
            }
        }
        return max_length;
    }
};

// @lc code=end
