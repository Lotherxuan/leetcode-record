#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  unordered_set<int> nums_set;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (nums[i] != nums[j]) {
        nums_set.insert(nums[i] + nums[j]);
      }
    }
  }
  int count = 0;
  for (int num : nums) {
    if (nums_set.count(num) == 1) {
      count++;
    }
  }
  cout << count << endl;
}