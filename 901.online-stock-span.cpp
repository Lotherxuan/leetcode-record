/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <utility>

using namespace std;
class StockSpanner {
public:
  stack<pair<int, int>> stock_stack;
  StockSpanner() {}

  int next(int price) {
    int span_count = 1;

    while (!stock_stack.empty() && price >= stock_stack.top().first) {
      span_count += stock_stack.top().second;
      stock_stack.pop();
    }
    stock_stack.push(make_pair(price, span_count));
    return span_count;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
