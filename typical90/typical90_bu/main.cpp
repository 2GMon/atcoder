#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const ll MOD = 1e9 + 7;

void dfs(int pos, int pre, vector<char>& c, vector<vector<int>>& G, vector<vector<ll>>& dp) {
  ll v1 = 1, v2 = 1;
  for (int next : G[pos]) {
    if (next == pre) continue;
    dfs(next, pos, c, G, dp);
    if (c[pos] == 'a') {
      v1 *= (dp[next][0] + dp[next][2]);
      v2 *= (dp[next][0] + dp[next][1] + 2 * dp[next][2]);
    }
    if (c[pos]== 'b') {
      v1 *= (dp[next][1] + dp[next][2]);
      v2 *= (dp[next][0] + dp[next][1] + 2 * dp[next][2]);
    }
    v1 %= MOD;
    v2 %= MOD;
  }

  if (c[pos] == 'a') {
    dp[pos][0] = v1;
    dp[pos][2] = (v2 - v1 + MOD) % MOD;
  }
  if (c[pos] == 'b') {
    dp[pos][1] = v1;
    dp[pos][2] = (v2 - v1 + MOD) % MOD;
  }
}

void Main() {
  int N;
  cin >> N;

  vector<char> c(N);
  for (int i = 0; i < N; i++) cin >> c[i];

  vector<vector<int>> G(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<vector<ll>> dp(N, vector<ll>(3));
  dfs(0, -1, c, G, dp);
  cout << dp[0][2] << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}