#include <iostream>
#include <stack>
using namespace std;
int main() {
  int temp;
  cin >> temp;
  stack<int> s;
  while (temp != 0) {
    s.push(temp);
    cin >> temp;
  }
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
  return 0;
}