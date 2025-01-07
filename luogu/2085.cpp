#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

using LLI = long long int;
using SmallQueue =
    std::priority_queue<LLI, std::vector<LLI>, std::greater<LLI>>;
using BigQueue = std::priority_queue<LLI, std::vector<LLI>, std::less<LLI>>;
LLI get_min_x(LLI a, LLI b) {
  double res = -(static_cast<double>(b) / (static_cast<double>(a) * 2));
  if (res <= 0) {
    return 1;
  } else {
    return static_cast<LLI>(std::ceil(res));
  }
}
void check_function_value(BigQueue &big_queue, LLI a, LLI b, LLI c, int m) {
  LLI min_x = get_min_x(a, b);
  for (LLI i = min_x; i <= min_x + m; i++) {
    LLI function_value = a * i * i + b * i + c;
    if (big_queue.size() < m) {
      big_queue.push(function_value);
    } else if (big_queue.top() > function_value) {
      big_queue.pop();
      big_queue.push(function_value);
    }
  }
}
void print_top_m_value(BigQueue &big_queue, int m) {
  std::vector<LLI> output_vector(m);
  for (int i = 0; i < m; i++) {
    output_vector[m - 1 - i] = big_queue.top();
    big_queue.pop();
  }
  for (auto value : output_vector) {
    std::cout << value << " ";
  }
  std::cout << std::endl;
}
int main() {
  int n, m;
  std::cin >> n >> m;
  BigQueue big_queue;
  for (int i = 0; i < n; i++) {
    LLI a, b, c;
    std::cin >> a >> b >> c;
    check_function_value(big_queue, a, b, c, m);
  }
  print_top_m_value(big_queue, m);
  return 0;
}

// 第一种思路：对于每个函数列出前m小的数，合并到一个序列然后求前m个顺序统计量，复杂度为m*nm,求第n顺序统计量为线性时间复杂度
// 第二种思路：对于一个序列求前k小的数，具体操作需要一个大根堆一个小根堆，小根堆存放第1小到第m小的数，大根堆存访第m+1小到更大的数。(有误
// 其实不需要小根堆，只有m存在动态变化的时候才需要小根堆) 时间复杂度mnlog(mn)
// 这两种哪种更优化不好说