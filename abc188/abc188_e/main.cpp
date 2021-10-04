#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N + 1);
  for (int i = 1; i <= N; i++) cin >> A[i];

  vector<vector<int>> G(N + 1);
  for (int i = 0; i < M; i++) {
    int X, Y;
    cin >> X >> Y;
    G[X].push_back(Y);
  }

  vector<ll> dp(N + 1, 3e9 + 10);
  for (int i = 1; i < N; i++) {
    for (auto nxt: G[i]) {
      dp[nxt] = min({dp[i], dp[nxt], (ll)A[i]});
    }
  }

  ll ans = -3e9 - 5;
  for (int i = 2; i <= N; i++) {
    ans = max(ans, A[i] - dp[i]);
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