/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
    //动态规划，可以使用滚动数组减少空间复杂度
public:
    int maxSubArray(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> dp(size, 0);
        int cur = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < size; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            cur = max(cur, dp[i]);
        }
        return cur;
    }
};
// @lc code=end
