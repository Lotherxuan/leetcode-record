#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
  int x;
  int y;
  node(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

const int direction[2][4] = {{1, 0, -1, 0}, {0, -1, 0, 1}};

void bfs(vector<vector<int>> &arr) {
  queue<node> q;
  node n_start(0, 0);
  q.push(n_start);
  arr[0][0] = -1;
  int max_index = arr.size() - 1;
  while (!q.empty()) {
    node head = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int search_x = head.x + direction[0][i];
      int search_y = head.y + direction[1][i];
      if ((search_x >= 0 && search_x <= max_index) &&
          (search_y >= 0 && search_y <= max_index) &&
          (arr[search_x][search_y] == 0)) {
        arr[search_x][search_y] = -1;
        node next_node(search_x, search_y);
        q.push(next_node);
      }
    }
  }
}

int main() {
  int N;
  cin >> N;
  vector<vector<int>> arr(N + 2, vector<int>(N + 2, 0));
  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < N + 1; j++) {
      cin >> arr[i][j];
    }
  }
  bfs(arr);
  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < N + 1; j++) {
      if (arr[i][j] == -1) {
        cout << 0 << " ";
      } else if (arr[i][j] == 1) {
        cout << 1 << " ";
      } else if (arr[i][j] == 0) {
        cout << 2 << " ";
      }
    }
    cout << endl;
  }
}