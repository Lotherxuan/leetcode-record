#include <vector>
#include <iostream>
#include <stack>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<int> numbers(n);
  vector<int> res(n);
  stack<int> s;
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() && numbers[i] >= numbers[s.top()]) {
      s.pop();
    }
    if (s.empty()) {
      res[i] = 0;
    } else {
      res[i] = s.top() + 1;
    }
    s.push(i);
  }
  for (auto n : res) {
    cout << n << " ";
  }
  cout << endl;
}