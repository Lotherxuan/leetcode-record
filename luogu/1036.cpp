#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool isprime(int num) {
  bool res = true;
  int square = sqrt(num);
  for (int i = 2; i <= square; i++) {
    if (num % i == 0) {
      res = false;
      break;
    }
  }
  return res;
}
int rec_func(int to_choose, int sum, int start, int end, vector<int>& nums) {
  int count = 0;
  if (!to_choose) {
    if (isprime(sum)) {
      count += 1;
    }
  } else {
    for (int i = start; i <= end; i++) {
      count += rec_func(to_choose - 1, sum + nums[i], i + 1, end, nums);
    }
  }
  return count;
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  cout << rec_func(k, 0, 0, n - 1, nums);
}