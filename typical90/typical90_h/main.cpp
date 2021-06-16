#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const ll MOD = 1e9 + 7;

void Main() {
  int N;
  cin >> N;
  vector<char> S(N);
  rep(i, N) cin >> S[i];

  string a = "atcoder";
  vector<vector<ll>> dp(N + 1, vector<ll>(8, 0));
  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 8; j++) {
      if (S[i] == a[j]) {
        dp[i + 1][j + 1] += dp[i][j];
        dp[i + 1][j + 1] %= MOD;
      }
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= MOD;
    }
  }

  cout << dp[N][7] << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}