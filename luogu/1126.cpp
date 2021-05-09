// 还没写完，有待补全
#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;
char directions[4] = {'E', 'S', 'W', 'N'};
int start_x;
int start_y;
int end_x;
int end_y;
int start_direct;
struct node {
  int x;
  int y;
  node(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

struct state {
  int x;
  int y;
  int direct_index;

  //   state(int _x = 0, int _y = 0, int _direct_index = 0)
  //       : x(_x), y(_y), direct_index(_direct_index) {}
  bool operator==(state const& s) {
    return (x == s.x) && (y == s.y) && (direct_index == s.direct_index);
  }
};

int bfs(vector<vector<bool>>& board, state& start_state) {
  unordered_set<state> state_set;
  state_set.insert(start_state);
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> board(N, vector<bool>(M, false));
  cin >> start_x >> start_y >> end_x >> end_y;
  char temp;
  cin >> temp;
  if (temp == 'E') {
    start_direct = 0;
  } else if (temp == 'S') {
    start_direct = 1;

  } else if (temp == 'W') {
    start_direct = 2;
  } else if (temp == 'N') {
    start_direct = 3;
  }
}
