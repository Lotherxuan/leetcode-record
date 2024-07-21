#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
int main() {
  int N, M;
  std::cin >> N >> M;
  std::vector<int> board(N + 1, 0);
  for (int i = 0; i < N; i++) {
    std::cin >> board[i + 1];
  }
  int cards[4] = {0, 0, 0, 0};
  int card;
  for (int i = 0; i < M; i++) {
    std::cin >> card;
    cards[card - 1]++;
  }
  std::array<std::vector<int>, 4> card_arr;
  for (int i = 0; i < 4; i++) {
    card_arr[i] = std::vector<int>(N + 1, cards[i]);
  }

  std::vector<int> dp(N + 1, 0);
  dp[1] = board[1];
  for (int i = 2; i < N + 1; i++) {
    int max_score = -1;
    int max_index = -1;
    for (int j = 1; j < 5; j++) {
      int index = i - j;
      if (index > 0 && card_arr[j - 1][index] > 0) {
        if (dp[index] > max_score) {
          max_score = dp[index];
          max_index = index;
        }
      }
    }
    if (max_score != -1) {
      dp[i] = dp[max_index] + board[i];
      for (int j = 0; j < 4; j++) {
        card_arr[j][i] = card_arr[j][max_index];
      }
      card_arr[i - max_index - 1][i] =
          card_arr[i - max_index - 1][max_index] - 1;
    }
  }
  auto ans = std::max_element(dp.begin() + 1, dp.end());
  std::cout << *ans << std::endl;
}