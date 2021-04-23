#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
void backtrace(vector<int>& nums, vector<int>& track,
               vector<vector<int>>& res) {
  if (track.size() == nums.size()) {
    res.push_back(track);
  } else {
    for (auto num : nums) {
      if (find(track.begin(), track.end(), num) == track.end()) {
        track.push_back(num);
        backtrace(nums, track, res);
        track.pop_back();
      }
    }
  }
}
vector<vector<int>> permute(vector<int>& nums) {
  vector<int> track;
  vector<vector<int>> res;
  backtrace(nums, track, res);
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < nums.size(); i++) {
    nums[i] = i + 1;
  }
  vector<vector<int>> res = permute(nums);
  for (auto arr : res) {
    for (auto num : arr) {
      printf("%5d", num);
    }
    printf("\n");
  }
}