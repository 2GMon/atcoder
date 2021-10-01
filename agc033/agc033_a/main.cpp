#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const int dh[] = {-1, 0, 1, 0};
const int dw[] = {0, -1, 0, 1};

void Main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  queue<pair<int, int>> black;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
      if (A[i][j] == '#') black.push(pair<int, int>(i, j));
    }
  }

  int ans = 0;
  while (!black.empty()) {
    queue<pair<int, int>> next_black;
    while(!black.empty()) {
      pair<int, int> b = black.front(); black.pop();
      for (int i = 0; i < 4; i++) {
        int nh = b.first + dh[i];
        int nw = b.second + dw[i];
        if (0 <= nh && nh < H && 0 <= nw && nw < W && A[nh][nw] == '.') {
          A[nh][nw] = '#';
          next_black.push(pair<int, int>(nh, nw));
        }
      }
    }
    black = next_black;
    ans++;
  }
  cout << ans - 1 << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}