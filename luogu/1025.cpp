#include <iostream>
#include <vector>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<vector<int>> dp(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (i == j) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = 0;
      }
    }
  }
  for (int i = 1; i < N; i++) {
    int row = i;
    int column = 0;
    dp[row][column] = 1;
    row++;
    column++;
    while (row < N && column < N) {
      dp[row][column] = dp[row - column - 1][column] + dp[row - 1][column - 1];
      row++;
      column++;
    }
  }
  //   for (auto out : dp) {
  //     for (auto v : out) {
  //       cout << v << " ";
  //     }
  //     cout << endl;
  //   }
  cout << dp[N - 1][K - 1] << endl;
}