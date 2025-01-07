#include <functional>
#include <iostream>
#include <queue>
using LLI = long long int;
using SmallQueue =
    std::priority_queue<LLI, std::vector<LLI>, std::greater<LLI>>;
using BigQueue = std::priority_queue<LLI, std::vector<LLI>, std::less<LLI>>;
int main() {
  SmallQueue small_queue; //储存较大的半数元素
  BigQueue big_queue;     //储存较小的半数元素
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    LLI num;
    std::cin >> num;
    if (small_queue.size() == big_queue.size()) {
      if (small_queue.size() == 0 || big_queue.size() == 0) {
        small_queue.push(num);
      } else {
        LLI small_half_part = big_queue.top();
        if (num < small_half_part) {
          small_queue.push(small_half_part);
          big_queue.pop();
          big_queue.push(num);
        } else if (num >= small_half_part) {
          small_queue.push(num);
        }
      }
    } else {
      if (small_queue.size() == 0 || big_queue.size() == 0) {
        LLI big_half_part = small_queue.top();
        if (num < big_half_part) {
          big_queue.push(num);
        } else if (num >= big_half_part) {
          big_queue.push(big_half_part);
          small_queue.pop();
          small_queue.push(num);
        }
      } else {
        LLI big_half_part = small_queue.top();
        LLI small_half_part = big_queue.top();
        if (num < big_half_part) {
          big_queue.push(num);
        } else if (num >= big_half_part) {
          big_queue.push(big_half_part);
          small_queue.pop();
          small_queue.push(num);
        }
      }
    }
    if (i % 2 == 0) {
      std::cout << small_queue.top() << std::endl;
    }
  }
  return 0;
}

// 第一种思路 两个堆 一个大根堆一个小根堆
// 然后维护两个堆的数量保证两个堆的数量差距不超过1 时间复杂度是nlogn
// 第二种思路比较朴素 就是直接求第n顺序量然后再做插入 前者复杂度logn
// 插入的时间复杂度也是n 扩容的总时间复杂度用摊还分析也是n 总体时间复杂度为nlogn