#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
  int n;
  cin >> n;
  vector<string> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  auto cmp = [](string a, string b) { return a + b > b + a; };
  sort(nums.begin(), nums.end(), cmp);
  for (auto i = nums.begin(); i < nums.end(); i++) {
    cout << *i;
  }
  cout << endl;
}