#include <string>
#include <iostream>
using namespace std;
int main() {
  string whole_string;
  getline(cin, whole_string);
  int count = 0;
  for (char &c : whole_string) {
    if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A') ||
        (c <= '9' && c >= '0')) {
      count++;
    }
  }
  cout << count << endl;
}