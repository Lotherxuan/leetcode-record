#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  long long int n;
  std::cin >> n;
  std::vector<long long int> heights(n);

  for (long long int i = 0; i < n; i++) {
    std::cin >> heights[i];
  }
  std::sort(heights.begin(), heights.end());
  long long int cur_height = 0;
  long long int begin_index = 0;
  long long int end_index = n - 1;
  long long int height_sum = 0;
  bool next_is_higher_height = true;
  bool loop_end = false;
  while (!loop_end) {
    if (begin_index == end_index) {
      loop_end = true;
    }
    if (next_is_higher_height) {
      height_sum +=
          (heights[end_index] - cur_height) * (heights[end_index] - cur_height);
      cur_height = heights[end_index];
      end_index--;
    } else {
      height_sum += (cur_height - heights[begin_index]) *
                    (cur_height - heights[begin_index]);
      cur_height = heights[begin_index];
      begin_index++;
    }
    next_is_higher_height = !next_is_higher_height;
  }
  std::cout << height_sum << std::endl;
}