#include <vector>
#include <algorithm>
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> heights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> heights[i];
  }
  std::vector<int> n0(n);
  std::vector<int> n1(n);
  std::vector<int> d0;
  std::vector<int> d1;
  for (int i = 0; i < n; i++) {
    if (d0.empty()) {
      d0.push_back(heights[i]);
      n0[i] = 1;
    } else {
      if (heights[i] > d0.back()) {
        d0.push_back(heights[i]);
        n0[i] = n0[i - 1] + 1;
      } else {
        auto iter = std::lower_bound(d0.begin(), d0.end(), heights[i]);
        *iter = heights[i];
        n0[i] = n0[i - 1];
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (d1.empty()) {
      d1.push_back(heights[i]);
      n1[i] = 1;
    } else {
      if (heights[i] > d1.back()) {
        d1.push_back(heights[i]);
        n1[i] = n1[i + 1] + 1;
      } else {
        auto iter = std::lower_bound(d1.begin(), d1.end(), heights[i]);
        *iter = heights[i];
        n1[i] = n1[i + 1];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = std::max(ans, n0[i] + n1[i] - 1);
  }
  std::cout << n - ans << std::endl;
}