/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      long long int product = 1;
      int zero_count = 0;
      for (auto i : nums) {
        if (i == 0) {
          zero_count++;
          if (zero_count >= 2) {
            product = 0;
            break;
          }
        } else {
          product *= i;
        }
      }
      vector<int> res(nums.size());
      for (int i = 0; i < nums.size(); i++) {
        if (zero_count == 1) {
          res[i] = (nums[i] != 0) ? 0 : product;
        } else {
          res[i] = (nums[i] != 0) ? product / nums[i] : 0;
        }
      }
      return res;
    }
};
// @lc code=end

