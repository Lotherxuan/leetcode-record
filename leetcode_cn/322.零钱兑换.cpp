/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
//递归，暴力法
#include <algorithm>
#include <vector>
#define INF 9999999
using namespace std;
//递归 暴力搜索 Time Limit Exceeded
/* class Solution {
 public:
  int coinChange(vector<int> &coins, int amount) {
    if (amount < 0) {
      return -1;
    } else if (amount == 0) {
      return 0;
    } else {
      int res = INF;
      for (auto &coin : coins) {
        int sub_problem = coinChange(coins, amount - coin);
        if (sub_problem == -1) {
          continue;
        } else {
          res = min(res, sub_problem + 1);
        }
      }
      if (res == INF) {
        return -1;
      } else {
        return res;
      }
    }
  }
}; */

//递归 带备忘录的递归 自顶向下
/* Your runtime beats 39.86 % of cpp submissions
Your memory usage beats 11.09 % of cpp submissions (14.6 MB) */
/* class Solution {
 public:
  int coinChangeWithArray(vector<int> &coins, int amount,
                          vector<int> &history) {
    int sub_problem;
    if (amount < 0) {
      return -1;
    } else if (amount == 0) {
      return 0;
    } else {
      int res = INF;
      for (auto &coin : coins) {
        if (amount - coin < 0) {
          sub_problem = -1;
        } else if (history[amount - coin] == -2) {
          sub_problem = coinChangeWithArray(coins, amount - coin, history);
          history[amount - coin] = sub_problem;
        } else {
          sub_problem = history[amount - coin];
        }
        if (sub_problem == -1) {
          continue;
        } else {
          res = min(res, sub_problem + 1);
        }
      }
      if (res == INF) {
        return -1;
      } else {
        return res;
      }
    }
  }
  int coinChange(vector<int> &coins, int amount) {
    vector<int> history(amount + 1, -2);
    history[0] = 0;
    return coinChangeWithArray(coins, amount, history);
  }
}; */

//循环 自底向上
/* Your runtime beats 24.97 % of cpp submissions
Your memory usage beats 45.8 % of cpp submissions (13.7 MB) */
class Solution {
 public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> search_history(amount + 1, -2);
    search_history[0] = 0;
    for (int i = 1; i <= amount; i++) {
      int res = INF;
      for (auto &coin : coins) {
        int sub_problem;
        if (i - coin < 0) {
          sub_problem = -1;
        } else {
          sub_problem = search_history[i - coin];
        }
        if (sub_problem == -1) {
          continue;
        } else {
          res = min(res, sub_problem + 1);
        }
      }
      if (res == INF) {
        search_history[i] = -1;
      } else {
        search_history[i] = res;
      }
    }
    return search_history[amount];
  }
};
// @lc code=end
