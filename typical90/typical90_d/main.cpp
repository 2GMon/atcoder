#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int H, W;
  cin >> H >> W;

  vector<vector<int>> A = vector<vector<int>>(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
    }
  }

  vector<int> sum_row = vector<int>(H, 0), sum_col = vector<int>(W, 0);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      sum_row[i] += A[i][j];
      sum_col[j] += A[i][j];
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << sum_row[i] + sum_col[j] - A[i][j];
      if (j != W - 1) cout << " ";
    }
    cout << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}