#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
int find_max_nolower(vector<int> const &nums) {
  vector<int> dp;
  for (auto num : nums) {
    if (dp.empty() || num <= dp.back()) {
      dp.push_back(num);
    } else {
      //   int start = 0;
      //   int end = dp.size() - 1;
      //   int mid = start + (end - start) / 2;
      //   while (true) {
      //     if (dp[mid] >= num && dp[mid + 1] < num) {
      //       break;
      //     } else {
      //       if (dp[mid] >= num) {
      //         start = mid;
      //         mid = start + (end - start) / 2;
      //       } else {
      //         end = mid;
      //         mid = start + (end - start) / 2;
      //       }
      //     }
      //   }
      //   dp[mid + 1] = num;
      auto iter = upper_bound(dp.begin(), dp.end(), num, greater<int>());
      *iter = num;
    }
  }
  return dp.size();
}
int find_max_upper(vector<int> const &nums) {
  vector<int> dp;
  for (auto num : nums) {
    if (dp.empty() || num > dp.back()) {
      dp.push_back(num);
    } else {
      //   int start = 0;
      //   int end = dp.size() - 1;
      //   int mid = start + (end - start) / 2;
      //   while (true) {
      //     if (dp[mid] >= num && dp[mid + 1] < num) {
      //       break;
      //     } else {
      //       if (dp[mid] >= num) {
      //         start = mid;
      //         mid = start + (end - start) / 2;
      //       } else {
      //         end = mid;
      //         mid = start + (end - start) / 2;
      //       }
      //     }
      //   }
      //   dp[mid + 1] = num;
      auto iter = upper_bound(dp.begin(), dp.end(), num, less_equal<int>());
      *iter = num;
    }
  }
  return dp.size();
}
int main() {
  string whole_string;
  getline(cin, whole_string);
  stringstream ss(whole_string);
  vector<int> nums;
  int num;
  while (ss >> num) {
    nums.push_back(num);
  }
  cout << find_max_nolower(nums) << endl;
  cout << find_max_upper(nums) << endl;
}