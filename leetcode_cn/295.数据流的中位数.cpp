/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

#include <queue>
#include <vector>
using namespace std;

// @lc code=start
class MedianFinder {
 public:
  priority_queue<int, vector<int>, greater<int>> big_q;
  priority_queue<int> small_q;
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    if (small_q.empty() || big_q.empty()) {
      if (small_q.empty() && big_q.empty()) {
        small_q.push(num);
      } else if (!small_q.empty() && big_q.empty()) {
        if (small_q.top() > num) {
          big_q.push(small_q.top());
          small_q.pop();
          small_q.push(num);
        } else {
          big_q.push(num);
        }
      }
    } else {
      if (small_q.size() == big_q.size()) {
        if (small_q.top() >= num) {
          small_q.push(num);
        } else {
          if (num > big_q.top()) {
            small_q.push(big_q.top());
            big_q.pop();
            big_q.push(num);
          } else {
            small_q.push(num);
          }
        }
      } else {
        if (small_q.top() >= num) {
          big_q.push(small_q.top());
          small_q.pop();
          small_q.push(num);
        } else {
          big_q.push(num);
        }
      }
    }
  }

  double findMedian() {
    if (big_q.size() == small_q.size()) {
      return (static_cast<double>(big_q.top()) +
              static_cast<double>(small_q.top())) /
             2;
    } else {
      return small_q.top();
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
