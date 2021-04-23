#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int direction[2][8] = {{2, 2, 1, -1, -2, -2, -1, 1},
                             {1, -1, -2, -2, -1, 1, 2, 2}};
struct node {
  int x;
  int y;
  node(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};
void bfs(vector<vector<int>> &board, int start_x, int start_y) {
  queue<node> q;
  node start_node(start_x, start_y);
  int max_row = board.size() - 1;
  int max_column = board[0].size() - 1;
  board[start_x][start_y] = 0;
  q.push(start_node);

  while (!q.empty()) {
    node head = q.front();
    q.pop();
    for (int i = 0; i < 8; i++) {
      int search_x = head.x + direction[0][i];
      int search_y = head.y + direction[1][i];
      if (search_x >= 0 && search_x <= max_row && search_y >= 0 &&
          search_y <= max_column && board[search_x][search_y] == -1) {
        board[search_x][search_y] = board[head.x][head.y] + 1;
        node next_node(search_x, search_y);
        q.push(next_node);
      }
    }
  }
}
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> board(N, vector<int>(M, -1));
  int start_x, start_y;
  cin >> start_x >> start_y;
  bfs(board, start_x - 1, start_y - 1);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      //   cout << board[i][j] << "     ";
      printf("%-5d", board[i][j]);
    }
    cout << endl;
  }
}