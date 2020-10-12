//堆排序
//没有自己写，几乎纯抄维基百科的，写的还真蛮不错的
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void max_heapify(vector<int> &nums, int index, int end);

void heapSort(vector<int> &nums) {
  int size = nums.size();
  for (int i = size / 2 - 1; i >= 0; i--) {
    max_heapify(nums, i, size - 1);
  }
  for (int i = size - 1; i >= 0; i--) {
    swap(nums[0], nums[i]);
    max_heapify(nums, 0, i - 1);
  }
}

void max_heapify(vector<int> &nums, int index, int end) {
  int child = 2 * index + 1;
  while (child <= end) {
    if (child + 1 <= end && nums[child + 1] > nums[child]) {
      child++;
    }
    if (nums[child] < nums[index]) {
      return;
    } else {
      swap(nums[child], nums[index]);
      index = child;
      child = 2 * index + 1;
    }
  }
}

int main() {
  vector<int> a{12, 40, 39, 69, 58, 41, 22, 95};
  heapSort(a);
  for_each(a.begin(), a.end(), [](int &n) { cout << n << " "; });
  cout << endl;
}