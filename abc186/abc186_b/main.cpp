#include"bits/stdc++.h"
using namespace std;

int H, W;
int A[101][101];

void Main() {
  cin >> H >> W;

  int m = 1000;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
      m = min(m, A[i][j]);
    }
  }

  int ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      ans += A[i][j] - m;
    }
  }
  cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}