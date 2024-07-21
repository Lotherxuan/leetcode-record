#include <iostream>
#include <vector>
int main() {
  int M, S, T;
  std::cin >> M >> S >> T;
  int s1 = 0, s2 = 0;
  int s = 0;
  int t = 0;
  bool can = false;
  int new_M;
  while (t < T) {
    t++;
    s1 = s1 + 17;
    if (M >= 10) {
      M = M - 10;
      s2 = s2 + 60;
    } else {
      M = M + 4;
    }
    if (s2 > s1) {
      s1 = s2;
    }
    s = s1;
    if (s > S) {
      can = true;
      std::cout << "Yes" << std::endl;
      std::cout << t << std::endl;
      break;
    }
  }
  if (!can) {
    std::cout << "No" << std::endl;
    std::cout << s << std::endl;
  }
}