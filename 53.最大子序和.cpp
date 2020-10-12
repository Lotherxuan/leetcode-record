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

public:
    //动态规划，可以使用滚动数组减少空间复杂度
    /*     int maxSubArray(vector<int> &nums)
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
    } */

    //分治算法，时间复杂度和动态规划相同
    struct state
    {
        int left;
        int right;
        int sum;
    };

    //寻找以nums[mid]和nums[mid+1]为分界，nums[start]和nums[end]为界的最大子数组
    state findCrossMax(vector<int> &nums, int start, int mid, int end)
    {
        state res;
        int left_sum = numeric_limits<int>::min();
        int sum = 0;
        int left_index = mid;
        for (int i = mid; i >= start; i--)
        {
            sum += nums[i];
            if (sum > left_sum)
            {
                left_sum = sum;
                left_index = i;
            }
        }

        int right_sum = numeric_limits<int>::min();
        sum = 0;
        int right_index = mid + 1;
        for (int i = mid + 1; i <= end; i++)
        {
            sum += nums[i];
            if (sum > right_sum)
            {
                right_sum = sum;
                right_index = i;
            }
        }

        res.left = left_index;
        res.right = right_index;
        res.sum = left_sum + right_sum;

        return res;
    }

    state maxSubArrayFunc(vector<int> &nums, int start, int end)
    {
        state res;
        if (start == end)
        {
            res.left = start;
            res.right = end;
            res.sum = nums[start];
            return res;
        }
        int mid = (start + end) / 2;
        state right_state = maxSubArrayFunc(nums, start, mid);
        state left_state = maxSubArrayFunc(nums, mid + 1, end);
        state cross_state = findCrossMax(nums, start, mid, end);
        int max_sum = max(max(right_state.sum, left_state.sum), cross_state.sum);
        if (max_sum == right_state.sum)
        {
            res = right_state;
        }
        else if (max_sum == left_state.sum)
        {
            res = left_state;
        }
        else
        {
            res = cross_state;
        }

        return res;
    }

    int maxSubArray(vector<int> &nums)
    {
        return maxSubArrayFunc(nums, 0, nums.size() - 1).sum;
    }
};
// @lc code=end
