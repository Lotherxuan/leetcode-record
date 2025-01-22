#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

int main() {
  int milk_sum, farmer_count;
  std::cin >> milk_sum >> farmer_count;
  std::vector<std::pair<int, int>> farmers(farmer_count);
  for (int i = 0; i < farmer_count; i++) {
    int milk_price, milk_quantity;
    std::cin >> milk_price >> milk_quantity;
    farmers[i] = std::make_pair(milk_price, milk_quantity);
  }
  std::sort(farmers.begin(), farmers.end(),
            [](auto const &p1, auto const &p2) { return p1.first < p2.first; });
  int milk_cur = 0;
  int price_count = 0;
  int farmer_index = 0;
  while (milk_sum - milk_cur > 0) {
    int milk_buy = std::min(milk_sum - milk_cur, farmers[farmer_index].second);
    price_count += farmers[farmer_index].first * milk_buy;
    milk_cur += milk_buy;
    farmer_index++;
  }
  std::cout << price_count;
}