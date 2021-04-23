#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check(vector<int>& track, int n);
void backtrack(vector<vector<int>>& res, vector<int>& track, int n) {
  if (track.size() == n) {
    res.push_back(track);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (check(track, i)) {
      track.push_back(i);
      backtrack(res, track, n);
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
  backtrack(res, track, n);
  for (int i = 0; i < 3; i++) {
    for (auto num : res[i]) {
      cout << num + 1 << " ";
    }
    cout << endl;
  }
  cout << res.size() << endl;
}