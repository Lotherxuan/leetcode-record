//快速排序
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int partition_alg(vector<int> &nums, int start, int end) {
  int pivot = nums[end];  // pivot作为此次划分的基准
  int divide_index =
      start - 1;  // divide_index作为大于pivot部分和小于pivot部分的分界
  // nums[divide_index]及左边的数都是小于pivot的，nums[divide_index+1]及右边的数都是大于pivot的
  for (int i = start; i < end; i++) {
    if (nums[i] < pivot) {
      divide_index++;
      swap(nums[divide_index], nums[i]);
    }
  }
  swap(nums[divide_index + 1], nums[end]);
  return divide_index + 1;
}

void quicksort(vector<int> &nums, int start, int end) {
  if (start >= end) {
    return;
  }
  int pivot_index = partition_alg(nums, start, end);
  quicksort(nums, start, pivot_index - 1);
  quicksort(nums, pivot_index + 1, end);
}

int main() {
  vector<int> test{12, 40, 39, 69, 58, 41, 22, 95, 44};
  quicksort(test, 0, test.size() - 1);
  for_each(test.begin(), test.end(), [](int &n) { cout << n << " "; });
  return 0;
}