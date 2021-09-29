#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const long long MOD = 998244353;

void Main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  vector<vector<long long>> dp(N + 1, vector<long long>(10, 0));

  dp[0][A[0]] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= 9; j++) {
      if (dp[i - 1][j] == 0) continue;
      dp[i][(j + A[i]) % 10] += dp[i - 1][j];
      dp[i][(j + A[i]) % 10] %= MOD;
      dp[i][(j * A[i]) % 10] += dp[i - 1][j];
      dp[i][(j * A[i]) % 10] %= MOD;
    }
  }

  for (int i = 0; i < 10; i++) {
    cout << dp[N - 1][i] << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}