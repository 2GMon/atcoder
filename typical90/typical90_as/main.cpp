#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, K;
  cin >> N >> K;
  vector<ll> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }

  ll d[1 << N];
  d[0] = 0;
  for (int i = 1; i < (1 << N); i++) {
    ll maxd = 0;
    for (int a = 0; (1 << a) < (1 << N); a++) {
      if ((i & (1 << a)) == 0) continue;
      for (int b = 1; (1 << (a + b)) < (1 << N); b++) {
        if ((i & (1 << (a + b))) == 0) continue;
        maxd = max(maxd, (X[a] - X[a + b]) * (X[a] - X[a + b]) + (Y[a] - Y[a + b]) * (Y[a] - Y[a + b]));
      }
    }
    d[i] = maxd;
  }

  ll dp[K + 1][1 << N];
  for (int i = 0; i <= K; i++) {
    for (int j = 0; j < (1 << N); j++) {
      dp[i][j] = numeric_limits<ll>::max();
    }
  }
  dp[0][0] = 0;
  for (int k = 1; k <= K; k++) {
    for (int i = 1; i < (1 << N); i++) {
      for (int j = i; j != 0; j = (j - 1) & i) {
        dp[k][i] = min(dp[k][i], max(dp[k - 1][i - j], d[j]));
      }
    }
  }
  cout << dp[K][(1 << N) - 1] << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}