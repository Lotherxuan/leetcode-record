// ac大概一半，算法没问题，要用前缀和进行剪纸，暂时还不会前缀和
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;
void backtrace(vector<long long> &nums, vector<long long> &track,
               long long &sum, long long &max, long long C) {
  if (sum < C) {
    if (sum > max) {
      max = sum;
    }
    // for (auto num : nums) {
    //   if (track.empty() ||
    //       (find(track.begin(), track.end(), num) == track.end() &&
    //        num > track.back())) {
    //     track.push_back(num);
    //     sum += num;
    //     backtrace(nums, track, sum, max, C);
    //     track.pop_back();
    //     sum -= num;
    //   }
    // }
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (track.empty() ||
          (find(track.begin(), track.end(), nums[i]) == track.end() &&
           nums[i] > track.back())) {
        track.push_back(nums[i]);
        sum += nums[i];
        backtrace(nums, track, sum, max, C);
        track.pop_back();
        sum -= nums[i];
      }
    }
  }

  else {
    return;
  }
}
int main() {
  long long N, C;
  cin >> N >> C;
  long long max = numeric_limits<long long>::min();
  long long sum = 0;
  vector<long long> nums(N);
  vector<long long> track;
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }
  backtrace(nums, track, sum, max, C);
  cout << max << endl;
}