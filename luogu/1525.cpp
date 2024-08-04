#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct Node {
  Node(int _x, int _y, int _z) : x(_x), y(_y), z(_z){};
  Node() : x(0), y(0), z(0){};
  int x;
  int y;
  int z;
};
// 在并查集中查找x
int find(std::vector<int> &union_set, int x) {
  if (union_set[x] == x) {
    return x;
  } else {
    union_set[x] = find(union_set, union_set[x]);
    return union_set[x];
  }
}
// 按秩合并x和y所在的并查集 传入的length用于记录并查集的秩
// 返回值表示x和y在合并前是否在同一并查集
bool union_set(std::vector<int> &union_set, std::vector<int> &length, int x,
               int y) {
  int xx = find(union_set, x);
  int yy = find(union_set, y);
  if (xx == yy) {
    return false;
  } else {
    if (length[xx] <= length[yy]) {
      union_set[xx] = yy;
      length[yy] += length[xx];
    } else {
      union_set[yy] = xx;
      length[xx] += length[yy];
    }
    return true;
  }
}

int get_min_hostility(int criminal_count, std::vector<Node> &hostilities) {
  std::vector<int> union_find(criminal_count);
  for (int i = 0; i < criminal_count; i++) {
    union_find[i] = i;
  }
  std::vector<int> union_length(criminal_count, 1);
  std::unordered_map<int, int> enemy_table;
  std::sort(hostilities.begin(), hostilities.end(),
            [](Node const &n1, Node const &n2) { return n1.z > n2.z; });
  for (auto &node : hostilities) {
    if (find(union_find, node.x) == find(union_find, node.y)) {
      return node.z;
    } else {
      if (enemy_table.find(node.x) == enemy_table.end()) {
        enemy_table[node.x] = node.y;
      } else {
        int x_enemy = enemy_table[node.x];
        union_set(union_find, union_length, x_enemy, node.y);
      }
      if (enemy_table.find(node.y) == enemy_table.end()) {
        enemy_table[node.y] = node.x;
      } else {
        int y_enemy = enemy_table[node.y];
        union_set(union_find, union_length, y_enemy, node.x);
      }
    }
    // } else if (enemy_table.find(node.x) == enemy_table.end() ||
    //            enemy_table.find(node.y) == enemy_table.end()) {
    //   enemy_table[node.x] = node.y;
    //   enemy_table[node.y] = node.x;
    // } else {
    //   int x_enemy = enemy_table[node.x];
    //   int y_enemy = enemy_table[node.y];
    //   union_set(union_find, union_length, x_enemy, node.y);
    //   union_set(union_find, union_length, y_enemy, node.x);
    // }
  }
  return 0;
}

int main() {
  int criminal_count, hostility_count;
  std::cin >> criminal_count >> hostility_count;
  std::vector<Node> hostilities(hostility_count);
  for (int i = 0; i < hostility_count; i++) {
    int x, y, z;
    std::cin >> x >> y >> z;
    hostilities[i] = Node(x - 1, y - 1, z);
  }
  std::cout << get_min_hostility(criminal_count, hostilities);
  return 0;
}

// 第一次ac没过，有点瑕疵的是处理node.x
// 和node.y已有enemy时两个可能不是同时都有enemy 需要分开处理