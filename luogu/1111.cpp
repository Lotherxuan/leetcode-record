#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
  node(int _x, int _y, int _t) : x(_x), y(_y), t(_t){};
  int x;
  int y;
  int t;
};
// 在并查集中查找x
int find(vector<int> &union_set, int x) {
  if (union_set[x] == x) {
    return x;
  } else {
    union_set[x] = find(union_set, union_set[x]);
    return union_set[x];
  }
}
// 按秩合并x和y所在的并查集 传入的length用于记录并查集的秩
// 返回值表示x和y在合并前是否在同一并查集
bool union_set(vector<int> &union_set, vector<int> &length, int x, int y) {
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
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> union_find(N);
  vector<int> union_length(N, 1);
  vector<node> operations(M);
  for (int i = 0; i < union_find.size(); i++) {
    union_find[i] = i;
  }
  int count = 0;
  while (count++ < M) {
    int x, y, t;
    cin >> x >> y >> t;
    operations.emplace_back(x - 1, y - 1, t);
  }
  sort(operations.begin(), operations.end(),
       [](node const &n1, node const &n2) { return n1.t < n2.t; });
  int remain_count = N;
  for (auto &operation : operations) {
    if (union_set(union_find, union_length, operation.x, operation.y)) {
      // 这里并查集表示的是已经联通的节点 如果不在这个并查集中就说明还没联通
      remain_count--;
      if (remain_count == 1) {
        // 如果最后剩余节点等于1，说明所有节点都联通了
        cout << operation.t << endl;
        break;
      }
    } else {
      ;
    }
  }
  if (remain_count > 1) {
    cout << -1 << endl;
  }
}