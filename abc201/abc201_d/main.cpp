#include"bits/stdc++.h"
using namespace std;

void Main() {
  int H, W;
  cin >> H >> W;

  vector<vector<int>> M(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char c;
      cin >> c;
      if (c == '+') M[i][j] = 1;
      else M[i][j] = -1;
    }
  }

  vector<vector<int>> dp(H, vector<int>(W, 0));
  for (int h = H - 1; h >= 0; h--) {
    for (int w = W - 1; w >= 0; w--) {
      if (h == H - 1 & w == W - 1) {
        dp[h][w] = 0;
      } else if (h == H - 1) {
        dp[h][w] = -dp[h][w + 1] + M[h][w + 1];
      } else if (w == W - 1) {
        dp[h][w] = -dp[h + 1][w] + M[h + 1][w];
      } else {
        dp[h][w] = max(-dp[h + 1][w] + M[h + 1][w], -dp[h][w + 1] + M[h][w + 1]);
      }
    }
  }

  if (dp[0][0] > 0) cout << "Takahashi" << endl;
  else if (dp[0][0] == 0) cout << "Draw" << endl;
  else cout << "Aoki" << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}

/*
*/