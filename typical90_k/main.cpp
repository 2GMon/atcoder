#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

typedef pair<int, pair<int, int>> task;

void Main() {
  int N;
  cin >> N;

  int maxD = 0;
  vector<task> t(N);
  rep(i, N) {
    int D, C, S;
    cin >> D >> C >> S;
    maxD = max(maxD, D);
    task tmp = task(D, pair<int, int>(C, S));
    t[i] = tmp;
  }

  sort(t.begin(), t.end());

  vector<vector<ll>> dp(N + 1, vector<ll>(maxD + 1, 0));

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= maxD; j++) {
      if (j < t[i - 1].second.first || j > t[i - 1].first) {
        dp[i][j] = dp[i - 1][j];
      }
      if (t[i - 1].second.first <= j && j <= t[i - 1].first) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i - 1].second.first] + t[i - 1].second.second);
      }
    }
  }

  ll ans = 0;
  for (auto d: dp[N]) {
    ans = max(ans, d);
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