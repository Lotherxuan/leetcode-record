//计数排序
//该排序要求n个输入元素中的每一个都是在0到k区间(包括k)内的一个整数，其中k为某个正整数。
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

const int MAX = 100;

vector<int> countsort(vector<int> &nums) {
  vector<int> count(MAX + 1, 0);
  vector<int> res(nums.size());
  for (int i = 0; i < nums.size(); i++) {
    count[nums[i]]++;
  }
  for (int i = 1; i < count.size(); i++) {
    count[i] += count[i - 1];
  }
  for (int i = nums.size() - 1; i >= 0; i--) {
    res[count[nums[i]] - 1] = nums[i];
    count[nums[i]]--;
  }
  return res;
}
int main() {
  int size = 10;
  random_device rd;
  vector<int> test(10);
  for (int i = 0; i < 10; i++) {
    test[i] = rd() % (MAX + 1);
  }
  cout << "before sort:" << endl;
  for_each(test.begin(), test.end(), [](int &n) { cout << n << " "; });
  cout << endl;
  vector<int> res = countsort(test);
  cout << "after sort:" << endl;
  for_each(res.begin(), res.end(), [](int &n) { cout << n << " "; });
  return 0;
}
