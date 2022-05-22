#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main() {
  vector<int> a{1, 2, 3, 4};
  for_each(a.begin(), a.end(), [](int &n) { cout << n; });
  cout << endl;

  random_device rd;
  vector<int> test;
  for (int i = 0; i < 10; i++) {
    test.push_back(rd() % 100);
  }
  for_each(test.begin(), test.end(), [](int &n) { cout << n << " "; });
  return 0;
}