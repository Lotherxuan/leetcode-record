#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
  string heights;
  getline(cin, heights);
  int hand_length;
  cin >> hand_length;
  stringstream heights_stream(heights);
  int height;
  int count = 0;
  while (heights_stream >> height) {
    if (hand_length + 30 >= height) {
      count++;
    }
  }
  cout << count << endl;
}