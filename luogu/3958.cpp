#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>

using lli = long long int;

struct node {
  node(lli _x, lli _y, lli _z) : x(_x), y(_y), z(_z){};
  node() : x(0), y(0), z(0){};
  lli x;
  lli y;
  lli z;
};
// 在并查集中查找x
lli find(std::vector<lli> &union_set, lli x) {
  if (union_set[x] == x) {
    return x;
  } else {
    union_set[x] = find(union_set, union_set[x]);
    return union_set[x];
  }
}
// 按秩合并x和y所在的并查集 传入的length用于记录并查集的秩
// 返回值表示x和y在合并前是否在同一并查集
bool union_set(std::vector<lli> &union_set, std::vector<lli> &length, lli x,
               lli y) {
  lli xx = find(union_set, x);
  lli yy = find(union_set, y);
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

bool sphere_lliersect(node &n1, node &n2, lli r) {
  lli x_length = std::abs(n1.x - n2.x);
  lli y_length = std::abs(n1.y - n2.y);
  lli z_length = std::abs(n1.z - n2.z);
  return 4 * r * r >=
         x_length * x_length + y_length * y_length + z_length * z_length;
}

bool can_bottom_to_floor(lli n, lli h, lli r,
                         std::vector<node> &sphere_centers) {
  if (n != sphere_centers.size()) {
    return false;
  }
  if (n == 1) {
    node &only_node = sphere_centers.front();
    return (only_node.z - r <= 0) && (only_node.z + r >= h);
  } else {
    std::sort(sphere_centers.begin(), sphere_centers.end(),
              [](node const &n1, node const &n2) { return n1.z < n2.z; });
    // node &start_node = sphere_centers.front();
    // node &end_node = sphere_centers.back();
    // std::vector<node> sphere_centers_with_sides(0);
    // sphere_centers_with_sides.emplace_back(start_node.x, start_node.y, 0);
    // for (auto node : sphere_centers) {
    //   sphere_centers_with_sides.emplace_back(node.x, node.y, node.z);
    // }
    // sphere_centers_with_sides.emplace_back(end_node.x, end_node.y, h);
    // lli node_count = sphere_centers_with_sides.size();
    lli node_count = sphere_centers.size();
    std::vector<lli> union_find(node_count);
    for (lli i = 0; i < node_count; i++) {
      union_find[i] = i;
    }
    std::vector<lli> union_length(node_count, 1);
    for (lli i = 0; i < node_count; i++) {
      for (lli j = 0; j < i; j++) {
        if (sphere_lliersect(sphere_centers[i], sphere_centers[j], r)) {
          union_set(union_find, union_length, i, j);
        }
      }
    }

    // 检查下平面
    std::unordered_map<lli, bool> lower_floor;
    for (int i = 0; i < node_count; i++) {
      if (sphere_centers[i].z - r <= 0) {
        lli union_set_index = union_find[i];
        if (lower_floor.find(union_set_index) == lower_floor.end()) {
          lower_floor[union_set_index] = true;
        }
      }
    }
    // 检查上平面
    std::unordered_map<lli, bool> upper_floor;
    for (int i = 0; i < node_count; i++) {
      if (sphere_centers[i].z + r >= h) {
        lli union_set_index = union_find[i];
        if (upper_floor.find(union_set_index) == upper_floor.end()) {
          upper_floor[union_set_index] = true;
        }
      }
    }
    bool res = false;
    for (int i = 0; i < node_count; i++) {
      lli union_set_index = union_find[i];
      if ((lower_floor.find(union_set_index) != lower_floor.end()) &&
          (upper_floor.find(union_set_index) != upper_floor.end())) {
        res = true;
        break;
      }
    }
    // return find(union_find, 0) == find(union_find, node_count - 1);
    return res;
  }
}
int main() {
  //   node n1(7272, 9750, 209);
  //   node n2(1523, -614, 425);
  //   std::cout << sphere_lliersect(n1, n2, 3189);
  lli t;
  std::cin >> t;
  for (lli i = 0; i < t; i++) {
    lli n, h, r;
    std::vector<node> sphere_centers(0);
    std::cin >> n >> h >> r;
    for (lli j = 0; j < n; j++) {
      lli x, y, z;
      std::cin >> x >> y >> z;
      sphere_centers.emplace_back(x, y, z);
    }
    if (can_bottom_to_floor(n, h, r, sphere_centers)) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }
  return 0;
}

// 第一次提交有问题 是只有一个点的时候处理有问题
// 第二次提交有问题
// 逻辑问题，处理上下面的时候不能简化成上下面各选取一个点作为起始点和终止点