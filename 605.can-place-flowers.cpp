/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
// #include <vector>
// using namespace std;
// time cost: 5min
class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int plant_count = 0;
    for (int i = 0; i < flowerbed.size(); i++) {
      if (flowerbed[i] == 0 && (i - 1 < 0 || flowerbed[i - 1] == 0) &&
          (i + 1 >= flowerbed.size() || flowerbed[i + 1] == 0)) {
        plant_count++;
        flowerbed[i] = 1;
      }
      if (plant_count >= n) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
