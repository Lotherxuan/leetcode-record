/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

/* 使用哈希表+链表的实现 */
#include <list>
#include <unordered_map>
using namespace std;
// @lc code=start
class LRUCache {
 public:
  LRUCache(int capacity) { size = capacity; }

  int get(int key) {
    auto iter = m.find(key);
    if (iter == m.end()) {
      return -1;
    } else {
      l.splice(l.begin(), l, iter->second);
      return iter->second->second;
    }
  }

  void put(int key, int value) {
    auto iter = m.find(key);
    if (l.size() < size) {
      if (iter == m.end()) {
        l.push_front({key, value});
        m[key] = l.begin();
      } else {
        iter->second->second = value;
        l.splice(l.begin(), l, iter->second);
        m[key] = l.begin();
      }
    } else {
      if (iter == m.end()) {
        auto k = l.back().first;
        m.erase(k);
        l.pop_back();
        l.push_front({key, value});
        m[key] = l.begin();
      } else {
        iter->second->second = value;
        l.splice(l.begin(), l, iter->second);
        m[key] = l.begin();
      }
    }
  }

 private:
  int size;
  unordered_map<int, list<pair<int, int>>::iterator> m;
  list<pair<int, int>> l;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
