#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  std::priority_queue<int, std::vector<int>, std::greater<int>>
      min_priority_queue;
  int n, op;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> op;
    if (op == 1) {
      int x;
      std::cin >> x;
      min_priority_queue.push(x);
    } else if (op == 2) {
      std::cout << min_priority_queue.top() << std::endl;
    } else if (op == 3) {
      min_priority_queue.pop();
    }
  }
  return 0;
}