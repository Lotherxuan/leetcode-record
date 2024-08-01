#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>
using namespace std;
int main() {
  int n, m;
  list<int> student_queue;
  unordered_map<int, list<int>::iterator> hash_table;
  typedef list<int>::iterator iter_type;
  cin >> n;
  student_queue.push_front(1);
  hash_table[1] = student_queue.begin();
  for (int i = 2; i <= n; i++) {
    int k, p;
    cin >> k >> p;
    auto pos = hash_table[k];
    if (p == 0) {
      iter_type insert_pos = student_queue.insert(pos, i);
      hash_table[i] = insert_pos;
    } else if (p == 1) {
      auto next_pos = std::next(pos);
      auto insert_pos = student_queue.insert(next_pos, i);
      hash_table[i] = insert_pos;
    }
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    if (hash_table.find(x) != hash_table.end()) {
      student_queue.erase(hash_table[x]);
      hash_table.erase(x);
    }
  }
  for (auto student : student_queue) {
    std::cout << student << " ";
  }
  std::cout << std::endl;
  return 0;
}

// 比较倾向于用链表先做插入，然后用哈希表记录位置，最后通过哈希表删除
// 第一次提交后有bug，经检查是写了auto next_pos = pos++
// 会导致next_pos等于pos自增前的