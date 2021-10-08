#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

const int INF = 1e9;

void Main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

  vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(310, vector<int>(310, INF)));

  dp[0][0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int x = 0; x <= X; x++) {
      for (int y = 0; y <= Y; y++) {
        if (dp[i][x][y] == INF) continue;

        dp[i + 1][x][y] = min(dp[i + 1][x][y], dp[i][x][y]);
        dp[i + 1][min(x + A[i], X)][min(y + B[i], Y)] = min(dp[i + 1][min(x + A[i], X)][min(y + B[i], Y)], dp[i][x][y] + 1);
      }
    }
  }

  int ans = dp[N][X][Y];
  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}