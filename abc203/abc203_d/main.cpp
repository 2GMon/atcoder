#include"bits/stdc++.h"
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int N, K;
vector<vector<int>> grid;

void Main() {
  cin >> N >> K;
  grid = vector<vector<int>>(N, vector<int>(N));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> grid[i][j];
    }
  }
  int L = K * K / 2 + 1;

  int wa = -1, ac = 1001001001;
  while (wa + 1 < ac) {
    int m = (wa + ac) / 2;
    bool ok = false;

    vector<vector<int>> cum = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
    rep(i, N) rep(j, N) cum[i + 1][j + 1] = grid[i][j] > m ? 1 : 0;
    rep(i, N + 1) rep(j, N) cum[i][j + 1] += cum[i][j];
    rep(i, N) rep(j, N + 1) cum[i + 1][j] += cum[i][j];
    rep(i, N - K + 1) rep(j, N - K + 1) {
      int now = cum[i + K][j + K] - cum[i][j + K] - cum[i + K][j] + cum[i][j];
      if (now < L) ok = true;
    }

    if (ok) ac = m;
    else wa = m;
  }

  cout << ac << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}