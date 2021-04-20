#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  string word;
  string text;
  string temp;
  getline(cin, word);
  transform(word.begin(), word.end(), word.begin(), ::tolower);
  int count = 0;
  int index = 0;
  int first_index = 0;
  bool search_word = false;
  string sentence;
  getline(cin, sentence);
  transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
  int cur_index = 0;
  while (cur_index < sentence.length()) {
    if (sentence[cur_index] < 'a' || sentence[cur_index] > 'z') {
      if (search_word) {
        search_word = false;
        if (temp == word) {
          if (count == 0) {
            first_index = index;
          }
          count++;
        }
        index += temp.length();
        temp.clear();
      }
      index++;
    } else {
      temp.push_back(sentence[cur_index]);
      search_word = true;
    }
    cur_index++;
  }
  //   stringstream str_stream(sentence);
  //   while (str_stream >> text) {
  //     if (word == text) {
  //       if (count == 0) {
  //         first_index = index;
  //       }
  //       count++;
  //     }
  //     index += (text.length() + 1);
  //   }
  if (!count) {
    cout << -1 << endl;
  } else {
    cout << count << " " << first_index << endl;
  }
}