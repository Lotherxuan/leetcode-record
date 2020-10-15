//最坏情况为线性时间的选择算法

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

void insertsort(vector<int> &nums, int start, int end) {
  for (int i = start + 1; i < end + 1; i++) {
    int key = nums[i];
    int j = i - 1;
    while ((j >= start) && (nums[j] > key)) {
      nums[j + 1] = nums[j];
      j--;
    }
    nums[j + 1] = key;
  }
}

// pivot作为此次划分的基准 该函数为修改版，传入了pivot
int partition_alg(vector<int> &nums, int start, int end, int pivot) {
  for (int i = start; i <= end; i++) {
    if (nums[i] == pivot) {
      swap(nums[i], nums[end]);
      break;
    }
  }

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

//确保返回的是第k小的元素，与下标无关
int select_alg(vector<int> &nums, int start, int end, int k) {
  if (start == end) {
    return nums[0];
  }
  int nums_size = end - start + 1;
  int mediums_size = nums_size / 5 + static_cast<bool>(nums_size % 5);
  vector<int> mediums(mediums_size);
  for (int i = 0; i < mediums_size - 1; i++) {
    insertsort(nums, start + i * 5, start + i * 5 + 4);
    mediums[i] = nums[start + i * 5 + 2];
  }
  insertsort(nums, start + (mediums_size - 1) * 5, end);
  mediums[mediums_size - 1] =
      (nums[(end + start + (mediums_size - 1) * 5) / 2]);
  int pivot = select_alg(mediums, 0, mediums_size - 1, (mediums_size + 1) / 2);
  int divide_index = partition_alg(nums, start, end, pivot);
  int cur_k = divide_index - start + 1;
  if (cur_k == k) {
    return nums[divide_index];
  } else if (cur_k > k) {
    return select_alg(nums, start, divide_index - 1, k);
  } else {
    return select_alg(nums, divide_index + 1, end, k - cur_k);
  }
  return numeric_limits<int>::max();
}

int random_partition_alg(vector<int> &nums, int start, int end) {
  random_device rd;
  int flag = rd() % (end - start) + start;
  swap(nums[end], nums[flag]);
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

void random_quicksort(vector<int> &nums, int start, int end) {
  if (start >= end) {
    return;
  }
  int pivot_index = random_partition_alg(nums, start, end);
  random_quicksort(nums, start, pivot_index - 1);
  random_quicksort(nums, pivot_index + 1, end);
}

int main() {
  vector<int> test{12, 40, 39, 69, 58, 41, 22, 95, 44};
  for_each(test.begin(), test.end(), [](int &n) { cout << n << " "; });
  cout << endl;
  cout << select_alg(test, 0, test.size() - 1, 7) << endl;
  random_quicksort(test, 0, test.size() - 1);
  for_each(test.begin(), test.end(), [](int &n) { cout << n << " "; });
}