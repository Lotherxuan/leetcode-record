#include <iostream>
#include <queue>
#include <unordered_set>

int main() {
  int m, n;
  std::cin >> m >> n;
  std::queue<int> word_in_memory;
  std::unordered_set<int> word_in_queue;
  int search_count = 0;
  int word;
  for (int i = 0; i < n; i++) {
    std::cin >> word;
    if (word_in_queue.find(word) == word_in_queue.end()) {
      if (word_in_queue.size() >= m) {
        int back_word = word_in_memory.front();
        word_in_memory.pop();
        word_in_queue.erase(back_word);
      }
      word_in_queue.insert(word);
      word_in_memory.push(word);
      search_count++;
    }
  }
  std::cout << search_count << std::endl;
  return 0;
}

// 没什么特别的 维护一个队列和一个unordered_set