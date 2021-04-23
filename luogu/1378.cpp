#include <iostream>
#define PI 3.1415926
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
double max_x, min_x, max_y, min_y;
struct node {
  node(double _x = 0, double _y = 0, double _r = 0) : x(_x), y(_y), r(_r) {}
  double x;
  double y;
  double r;
};

double length(double x1, double y1, double x2, double y2) {
  double res = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
  return res;
}

double caculate_area(vector<node> &nodes, vector<bool> &if_placed) {
  double area_sum = 0;
  for (int i = 0; i < if_placed.size(); i++) {
    if (if_placed[i]) {
      area_sum += nodes[i].r * nodes[i].r * PI;
    }
  }
  return area_sum;
}

void dfs(vector<node> &nodes, vector<bool> &if_placed, double &max_area) {
  double cur_area = caculate_area(nodes, if_placed);
  if (cur_area > max_area) {
    max_area = cur_area;
  }
  for (int i = 0; i < if_placed.size(); i++) {
    if (if_placed[i]) {
      continue;
    } else {
      if_placed[i] = true;
      node &n_r = nodes[i];
      n_r.r = min({n_r.x - min_x, max_x - n_r.x, n_r.y - min_y, max_y - n_r.y});

      for (int j = 0; j < if_placed.size(); j++) {
        if (if_placed[j] && j != i) {
          double l = length(nodes[j].x, nodes[j].y, n_r.x, n_r.y);
          if (l < nodes[j].r) {
            n_r.r = 0;
            break;
          } else {
            n_r.r = min(l - nodes[j].r, n_r.r);
          }
        }
      }

      dfs(nodes, if_placed, max_area);
      nodes[i].r = 0;
      if_placed[i] = false;
    }
  }
}

int main() {
  int N;
  cin >> N;
  double x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x1 += 1000;
  y1 += 1000;
  x2 += 1000;
  y2 += 1000;

  max_x = max(x1, x2);
  min_x = min(x1, x2);
  max_y = max(y1, y2);
  min_y = min(y1, y2);

  vector<node> nodes(N);
  for (int i = 0; i < N; i++) {
    node &n = nodes[i];
    cin >> n.x >> n.y;
    n.x += 1000;
    n.y += 1000;
  }
  double max_area = 0;
  vector<bool> if_placed(N, false);
  dfs(nodes, if_placed, max_area);
  double res = (max_x - min_x) * (max_y - min_y) - max_area;
  cout << static_cast<int>(round(res)) << endl;
}