#include <iostream>
#include <list>
using namespace std;
int main() {
  int n, m;
  std::cin >> n >> m;
  std::list<int> circle;
  for (int i = 0; i < n; i++) {
    circle.push_back(i + 1);
  }
  auto iter = circle.end();
  decltype(iter) old_iter = iter;
  while (true) {
    iter++;
    if (iter == circle.end()) {
      iter++;
    }
    if (old_iter != circle.end()) {
      circle.erase(old_iter);
      if (circle.empty()) {
        std::cout << std::endl;
        break;
      }
    }
    for (int i = 1; i < m; i++) {
      iter++;
      if (iter == circle.end()) {
        iter++;
      }
    }
    std::cout << *iter << " ";
    // std::cout << *iter << std::endl;
    old_iter = iter;
    // for (auto i : circle) {
    //   std::cout << i << " ";
    // }
    // std::cout << std::endl;
  }
  std::cout << std::endl;
  return 0;
}