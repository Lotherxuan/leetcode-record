//桶排序
//假定待排序的数的范围为0~599,共分为20个桶,范围依次为0~29,30~59,...

#include <algorithm>
#include <forward_list>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

const int MAX_NUMBER = 599;
const int BUCKET_NUMBER = 20;

void mergeLinklist(vector<forward_list<int>> &buckets, vector<int> &nums) {
  int index = 0;
  for (auto bucket = buckets.begin(); bucket != buckets.end(); bucket++) {
    for (auto iter = bucket->begin(); iter != bucket->end(); iter++) {
      nums[index++] = *iter;
    }
  }
}
void insertLinklist(forward_list<int> &bucket, int number) {
  auto pre = bucket.before_begin();
  auto cur = bucket.begin();
  while (cur != bucket.end()) {
    if (number <= *cur) {
      break;
    }
    cur++;
    pre++;
  }
  bucket.insert_after(pre, number);
}

void bucketsort(vector<int> &nums) {
  vector<forward_list<int>> buckets(BUCKET_NUMBER, forward_list<int>());
  for (int i = 0; i < nums.size(); i++) {
    insertLinklist(buckets[nums[i] / (MAX_NUMBER / BUCKET_NUMBER + 1)],
                   nums[i]);
  }
  mergeLinklist(buckets, nums);
}
int main() {
  int size = 10;
  random_device rd;
  vector<int> test(10);
  for (int i = 0; i < 10; i++) {
    test[i] = rd() % (MAX_NUMBER + 1);
  }
  cout << "before sort:" << endl;
  for_each(test.begin(), test.end(), [](int &n) { cout << n << " "; });
  cout << endl;
  bucketsort(test);
  cout << "after sort:" << endl;
  for_each(test.begin(), test.end(), [](int &n) { cout << n << " "; });
  return 0;
  return 0;
}
