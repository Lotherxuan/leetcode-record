/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> arrays;
        sort(nums.begin(), nums.end());
        size_t n = nums.size();
        for (size_t i = 0; i < n; i++)
        {
            int j = i + 1, k = n;
            while ((nums[i] + nums[j] + nums[k]) != 0)
            {
            }
        }
    }
};
// @lc code=end
