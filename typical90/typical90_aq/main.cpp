#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

struct pos {
  int h, w, dir;
};

int H, W;
int rs, rt, cs, ct;
char m[1002][1002];
int d[1002][1002][4];
int dh[4] = {-1, 1, 0, 0};
int dw[4] = {0, 0, -1, 1};
const int INF = 1e9;

void Main() {
  cin >> H >> W;
  cin >> rs >> cs;
  cin >> rt >> ct;

  for (int i = 0; i <= H + 1; i++) {
    m[i][0] = '#';
    m[i][0] = '#';
    m[i][W + 1] = '#';
    m[i][W + 1] = '#';
  }
  for (int i = 0; i <= W + 1; i++) {
    m[0][i] = '#';
    m[0][i] = '#';
    m[H + 1][i] = '#';
    m[H + 1][i] = '#';
  }

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> m[i][j];
    }
  }

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      d[i][j][0] = d[i][j][1] = d[i][j][2] = d[i][j][3] = INF;
    }
  }

  queue<pos> q;
  for (int i = 0; i < 4; i++) {
    q.push({rs, cs, i});
    d[rs][cs][i] = 0;
  }

  while (!q.empty()) {
    pos now = q.front(); q.pop();
    int h = now.h, w = now.w, dir = now.dir;
    for (int i = 0; i < 4; i++) {
      int nh = h + dh[i], nw = w + dw[i];
      int num = d[h][w][dir] + (dir != i ? 1: 0);
      if (1 <= nh && nh <= H && 1 <= nw && nw <= W && m[nh][nw] == '.' && d[nh][nw][i] > num) {
        d[nh][nw][i] = num;
        q.push({nh, nw, i});
      }
    }
  }
  
  cout << min({d[rt][ct][0], d[rt][ct][1], d[rt][ct][2], d[rt][ct][3]}) << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}