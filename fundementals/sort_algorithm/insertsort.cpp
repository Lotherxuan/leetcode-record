#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//排序nums[start]到nums[end]的部分
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

void printarray(vector<int> &nums) {
  for_each(nums.begin(), nums.end(), [](int &n) { cout << n << " "; });
  cout << endl;
}
int main() {
  /*   vector<int> test{27, 40, 39, 69, 58, 41, 22, 95, 44};
    printarray(test);
    insertsort(test, 0, test.size() - 1);
    printarray(test); */
  cout << 6 / 5 + static_cast<bool>(5 % 5) << endl;
}