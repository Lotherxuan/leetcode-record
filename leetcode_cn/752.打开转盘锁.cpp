/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// bfs注意一定一定一定要标记访问过的节点，并且尽量早的标记，可以看作是尽量早地剪枝，减少搜索范围
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    deque<string> q;
    int count = 0;
    q.push_back("0000");
    q.push_back("#");
    unordered_set<string> s(deadends.begin(), deadends.end());
    if (s.find("0000") != s.end()) {
      return -1;
    }
    unordered_set<string> visited;
    while (!q.empty()) {
      // queue<string> q_copy(q);
      // while(!q.copy.empty()){
      //   cout << q_copy.back() << " ";
      //   q_copy.pop();
      // }
      // for (auto q_s : q) {
      //   cout << q_s << " ";
      // }
      // cout << endl;
      // cout << visited.size() << endl;
      string back = q.front();
      q.pop_front();
      if (back == "#") {
        count++;
        if (!q.empty()) {
          q.push_back("#");
        }
      } else if (back == target) {
        q.push_back("#");
        break;
      } else {
        visited.insert(back);
        for (int i = 0; i < back.size(); i++) {
          string temp = back;
          temp[i] = (temp[i] - '0' + 11) % 10 + '0';
          if (s.find(temp) == s.end() && visited.find(temp) == visited.end()) {
            q.push_back(temp);
            visited.insert(temp);
          }
          temp = back;
          temp[i] = (temp[i] - '0' + 9) % 10 + '0';
          if (s.find(temp) == s.end() && visited.find(temp) == visited.end()) {
            q.push_back(temp);
            visited.insert(temp);
          }
        }
      }
      if (q.empty()) {
        return -1;
      }
    }
    return count;
  }
};
// @lc code=end
