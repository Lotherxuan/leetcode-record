#include <string>
#include <stack>
#include <iostream>
using namespace std;
int main() {
  string s_in;
  cin >> s_in;
  stack<char> s_char;
  bool neg = false;
  for (char &c : s_in) {
    if (c == '-') {
      neg = true;
    } else {
      s_char.push(c);
    }
  }
  if (neg) {
    cout << "-";
  }
  while (!s_char.empty() && s_char.top() == '0') {
    s_char.pop();
  }
  while (!s_char.empty()) {
    cout << s_char.top();
    s_char.pop();
  }
  cout << endl;
  return 0;
}
