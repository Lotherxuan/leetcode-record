#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;
int partion(vector<int> &nums, int start, int end) {
  int random_index = rand() % (end - start) + start;
  swap(nums[random_index], nums[end]);

  int pivot = nums[end];
  int right_less_index = start - 1;
  for (int i = start; i < end; i++) {
    if (nums[i] <= nums[end]) {
      right_less_index++;
      swap(nums[i], nums[right_less_index]);
    }
  }
  swap(nums[end], nums[right_less_index + 1]);
  return right_less_index + 1;
}

void quick_sort(vector<int> &nums, int start, int end) {
  if (start >= end) {
    return;
  }
  int index = partion(nums, start, end);
  quick_sort(nums, start, index - 1);
  quick_sort(nums, index + 1, end);
}
int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  //   quick_sort(nums, 0, nums.size() - 1);
  sort(nums.begin(), nums.end());
  for (auto num : nums) {
    cout << num << " ";
  }
  cout << endl;
}