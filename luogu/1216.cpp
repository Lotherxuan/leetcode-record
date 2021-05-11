#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
  int lines;
  cin >> lines;
  vector<vector<int>> dp(lines, vector<int>(lines, 0));
  for (int i = 0; i < lines; i++) {
    vector<int> read_nums(i + 1);
    for (int j = 0; j < i + 1; j++) {
      cin >> read_nums[j];
    }
    if (i == 0) {
      dp[i][0] = read_nums[i];
    } else {
      for (int j = 0; j < i + 1; j++) {
        if (j == 0) {
          dp[i][0] = dp[i - 1][0] + read_nums[0];
        } else if (j == i) {
          dp[i][i] = dp[i - 1][i - 1] + read_nums[i];
        } else {
          dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + read_nums[j];
        }
      }
    }
  }
  cout << *max_element(dp[lines - 1].begin(), dp[lines - 1].end()) << endl;
}