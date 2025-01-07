#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using NutsQueue = std::priority_queue<int, std::vector<int>, std::greater<int>>;

// int get_min_nuts_sum(NutsQueue &nuts_heap, int nut_sum) {
//   if (nuts_heap.size() <= 1) {
//     return nut_sum;
//   } else {
//     int nut_0 = nuts_heap.top();
//     nuts_heap.pop();
//     int nut_1 = nuts_heap.top();
//     nuts_heap.pop();
//     int two_nut_sum = nut_0 + nut_1;
//     nut_sum += two_nut_sum;
//     nuts_heap.push(two_nut_sum);
//     get_min_nuts_sum(nuts_heap, nut_sum);
//   }
// }

int main() {
  int n, nut;
  int num_sum = 0;
  std::cin >> n;
  std::priority_queue<int, std::vector<int>, std::greater<int>> nuts_heap;
  for (int i = 0; i < n; i++) {
    std::cin >> nut;
    nuts_heap.push(nut);
  }
  for (int i = 0; i < n - 1; i++) {
    int nut_0 = nuts_heap.top();
    nuts_heap.pop();
    int nut_1 = nuts_heap.top();
    nuts_heap.pop();
    int two_nut_sum = nut_0 + nut_1;
    num_sum += two_nut_sum;
    nuts_heap.push(two_nut_sum);
  }
  std::cout << num_sum;
  return 0;
}

// 整体思路就是在一个vector中每次都找出最小的两个数进行合并 直至只剩一个数
// 很奇怪的是提交到洛谷之后有内存访问错误
// 把递归改成循环之后就没问题了，可能是因为地址访问减少了？