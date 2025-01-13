/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
  int maxOperations(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int op_count = 0;
    int start_index = 0;
    int end_index = nums.size() - 1;
    while (start_index < end_index) {
      if (nums[start_index] + nums[end_index] > k) {
        end_index--;

      } else if (nums[start_index] + nums[end_index] < k) {
        start_index++;
      } else {
        op_count++;
        start_index++;
        end_index--;
      }
    }
    return op_count;
  }
};
// @lc code=end
