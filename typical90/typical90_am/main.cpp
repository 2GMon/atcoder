#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int N;
vector<vector<int>> G(100001);
vector<ll> dp(100001);
ll ans = 0;

void dfs(int pos, int before) {
  dp[pos] = 1;
  for (int i : G[pos]) {
    if (i != before) {
      dfs(i, pos);
      dp[pos] += dp[i];
    }
  }
  ans += (N - dp[pos]) * dp[pos];
}

void Main() {
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(1, -1);

  cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}