// Dijkstra算法，使用邻接矩阵，时间复杂度O(V^2+E)
#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;
vector<int> Dijkstra(vector<vector<int>> const& path_matrix, int start_point) {
  int point_number = path_matrix.size();
  unordered_set<int> visited;
  vector<pair<int, int>> points;
  vector<int> distance(point_number, numeric_limits<int>::max());

  points.push_back(make_pair(start_point, 0));
  auto cmp = [](pair<int, int> const& p1, pair<int, int> const& p2) {
    return p1.second > p2.second;
  };
  while (!points.empty()) {
    int min_point = points.front().first;
    visited.insert(min_point);
    distance[min_point] = points.front().second;
    points.clear();
    for (int i = 0; i < point_number; i++) {
      if (visited.find(i) == visited.end()) {
        if (distance[min_point] < distance[i] - path_matrix[min_point][i]) {
          distance[i] = distance[min_point] + path_matrix[min_point][i];
        }
        points.push_back(make_pair(i, distance[i]));
      }
    }
    make_heap(points.begin(), points.end(), cmp);
  }
  return distance;
}
int main() {
  int n, m, s;
  // n:点的个数 m:有向边的个数 s:出发点的编号
  cin >> n >> m >> s;
  vector<vector<int>> path_matrix(n,
                                  vector<int>(n, numeric_limits<int>::max()));
  for (int i = 0; i < n; i++) {
    path_matrix[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    path_matrix[u - 1][v - 1] = w;
  }
  vector<int> res = Dijkstra(path_matrix, s - 1);
  for (auto const& i : res) {
    cout << i << " ";
  }
  cout << endl;
}