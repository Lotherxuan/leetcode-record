#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> dp(1001);
  dp[1] = 1;
  int count = 1;
  for (int i = 2; i < dp.size(); i++) {
    dp[i] = 1;
    for (int j = 1; j <= i / 2; j++) {
      dp[i] += dp[j];
    }
  }
  int n;
  cin >> n;
  cout << dp[n] << endl;
}