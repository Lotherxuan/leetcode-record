#include <iostream>
#include <vector>

using namespace std;
void build(long long l, long long r, long long p, vector<long long>& numbers,
           vector<long long>& segment) {
  if (l == r) {
    segment[p] = numbers[l];
    return;
  }
  long long m = l + ((r - l) >> 1);
  build(l, m, 2 * p, numbers, segment);
  build(m + 1, r, p * 2 + 1, numbers, segment);
  segment[p] = segment[2 * p] + segment[2 * p + 1];
}

void update(long long l, long long r, long long c, long long s, long long t,
            long long p, vector<long long>& numbers, vector<long long>& segment,
            vector<long long>& tag) {
  if (l <= s && t <= r) {
    segment[p] += (t - s + 1) * c;
    tag[p] += c;
    return;
  }

  long long m = s + ((t - s) >> 1);
  if (tag[p]) {
    segment[p * 2] += tag[p] * (m - s + 1);
    tag[p * 2] += tag[p];
    segment[p * 2 + 1] += tag[p] * (t - m);
    tag[p * 2 + 1] += tag[p];
  }

  tag[p] = 0;

  if (l <= m) {
    update(l, r, c, s, m, p * 2, numbers, segment, tag);
  }
  if (r > m) {
    update(l, r, c, m + 1, t, p * 2 + 1, numbers, segment, tag);
  }
  segment[p] = segment[p * 2] + segment[p * 2 + 1];
}
long long getsum(long long l, long long r, long long s, long long t,
                 long long p, vector<long long>& segment,
                 vector<long long>& tag) {
  if (l <= s && r >= t) {
    return segment[p];
  }
  long long m = s + ((t - s) >> 1);
  if (tag[p]) {
    segment[p * 2] += tag[p] * (m - s + 1);
    tag[p * 2] += tag[p];
    segment[p * 2 + 1] += tag[p] * (t - m);
    tag[p * 2 + 1] += tag[p];
  }

  tag[p] = 0;

  long long sum = 0;
  if (l <= m) {
    sum += getsum(l, r, s, m, p * 2, segment, tag);
  }
  if (r > m) {
    sum += getsum(l, r, m + 1, t, p * 2 + 1, segment, tag);
  }
  return sum;
}
int main() {
  long long n, m;
  cin >> n >> m;
  vector<long long> numbers(n + 1);
  vector<long long> segment(4 * n);
  vector<long long> tag(4 * n);
  for (long long i = 0; i < n; i++) {
    cin >> numbers[i + 1];
  }
  build(1, n, 1, numbers, segment);
  for (long long i = 0; i < m; i++) {
    long long op;
    long long x, y, k;
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> k;
      update(x, y, k, 1, n, 1, numbers, segment, tag);
      //       cout << endl;
      //       cout << "after update" << endl;
      //       for (long long i = 1; i < 16; i++) {
      //         cout << segment[i] << " ";
      //       }
      //       cout << endl;

      //       for (long long i = 1; i < 16; i++) {
      //         cout << tag[i] << " ";
      //       }
      //       cout << endl;
    } else if (op == 2) {
      cin >> x >> y;
      cout << getsum(x, y, 1, n, 1, segment, tag) << endl;
    }
  }
}