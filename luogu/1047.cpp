#include <iostream>
#include <vector>
using namespace std;
int main() {
  int l, m;
  cin >> l >> m;
  vector<bool> tags(l + 1, true);

  for (int i = 0; i < m; i++) {
    int start, end;
    cin >> start >> end;
    for (int i = start; i <= end; i++) {
      tags[i] = false;
    }
  }
  int count = 0;
  for (bool b : tags) {
    if (b) {
      count++;
    }
  }
  cout << count << endl;
}