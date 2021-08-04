#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int dh[] = {-1, 0, 1, 0};
int dw[] = {0, -1, 0, 1};

ll dfs(int h, int w, int H, int W, int num, vector<vector<char>>& c, vector<vector<bool>>& visited) {
  if (h == H && w == W && num != 1) {
    if (num - 1 < 3) return 0;
    return num - 1;
  } else {
    visited[h][w] = true;
    ll res = 0;
    for (int i = 0; i < 4; i++) {
      int nh = h + dh[i], nw = w + dw[i];
      if (0 <= nh && nh < c.size() && 0 <= nw && nw < c[0].size() && c[nh][nw] == '.' && (visited[nh][nw] == false || (nh == H && nw == W))) {
        res = max(res, dfs(nh, nw, H, W, num + 1, c, visited));
      }
    }
    visited[h][w] = false;
    if (res < 3) res = 0;
    return res;
  }
}

void Main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> c(H, vector<char>(W));
  vector<vector<bool>> visited(H, vector<bool>(W, false));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> c[i][j];
    }
  }

  ll ans = 0;
  bool finish = false;
  for (int i = 0; i < H && !finish; i++) {
    for (int j = 0; j < W && !finish; j++) {
      if (c[i][j] == '.') {
        ans = max(ans, dfs(i, j, i, j, 1, c, visited));
      }
    }
  }
  if (ans == 0) cout << -1 << endl;
  else cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}