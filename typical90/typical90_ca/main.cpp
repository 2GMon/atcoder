#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int H, W;
  cin >> H >> W;

  vector<vector<int>> A(H, vector<int>(W)), B(H, vector<int>(W));
  for (int h = 0; h < H; h++) {
    for (int w = 0; w < W; w++) {
      cin >> A[h][w];
    }
  }
  for (int h = 0; h < H; h++) {
    for (int w = 0; w < W; w++) {
      cin >> B[h][w];
    }
  }

  ll ans = 0;
  for (int h = 0; h < H - 1; h++) {
    for (int w = 0; w < W - 1; w++) {
      int diff = B[h][w] - A[h][w];
      if (diff != 0) {
        A[h][w] += diff;
        A[h][w + 1] += diff;
        A[h + 1][w] += diff;
        A[h + 1][w + 1] += diff;
        ans += abs(diff);
      }
    }
  }

  bool yes = true;
  for (int h = 0; h < H; h++) {
    for (int w = 0; w < W; w++) {
      if (A[h][w] != B[h][w]) yes = false;
    }
  }
  if (yes) {
    cout << "Yes" << endl;
    cout << ans << endl;
  } else {
    cout << "No" << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}