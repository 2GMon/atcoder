#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  cin >> N;
  vector<int> A(2 * N);
  rep(i, 2 * N) cin >> A[i];

  vector<vector<ll>> dp(2 * N, vector<ll>(2 * N, 1e18));
  for (int i = 0; i < 2 * N - 1; i++) {
    dp[i][i + 1] = abs(A[i] - A[i + 1]);
  }
  for (int width = 3; width < 2 * N; width += 2) {
    for (int i = 0; i < 2 * N - 1; i++) {
      if (i + width >= 2 * N) continue;
      for (int j = i; j < i + width; j++) {
        dp[i][i + width] = min(dp[i][i + width], dp[i][j] + dp[j + 1][i + width]);
      }
      dp[i][i + width] = min(dp[i][i + width], dp[i + 1][i + width - 1] + abs(A[i] - A[i + width]));
    }
  }

  cout << dp[0][2 * N - 1] << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}