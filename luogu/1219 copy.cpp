#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int result_count = 0;
bool check(vector<int>& track, int n);
void backtrack(vector<int>& track, int n) {
  if (track.size() == n) {
    if (result_count < 3) {
      for (auto num : track) {
        cout << num + 1 << " ";
      }
      cout << endl;
    }
    ++result_count;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (check(track, i)) {
      track.push_back(i);
      backtrack(track, n);
      track.pop_back();
    }
  }
}
bool check(vector<int>& track, int n) {
  int row_index = track.size();
  for (auto num : track) {
    if (num == n) {
      return false;
    }
  }
  for (int i = 0; i < track.size(); i++) {
    if ((n - row_index) == (track[i] - i)) {
      return false;
    }
    if ((n + row_index) == (track[i] + i)) {
      return false;
    }
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  //   vector<vector<int>> arr(n, vector<int>(n, 0));
  vector<vector<int>> res;
  vector<int> track;
  backtrack(track, n);

  cout << result_count << endl;
}