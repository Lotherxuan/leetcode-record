#include <iostream>
#include <vector>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> dp(N + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  for (int j = 2; j <= N; j++) {
    for (int i = 1; i <= K; i++) {
      if ((j - i) >= 0) {
        dp[j] = (dp[j] + dp[j - i]) % 100003;
      }
    }
  }
  cout << dp[N] << endl;
}