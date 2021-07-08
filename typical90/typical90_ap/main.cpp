#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const ll MOD = 1e9 + 7;

void Main() {
  int K;
  cin >> K;
  if (K % 9 != 0) {
    cout << 0 << endl;
    return;
  }

  vector<ll> dp(K + 1);
  dp[0] = 1;
  for (int i = 1; i <= K; i++) {
    for (int j = 1; j <= min(i, 9); j++) {
      dp[i] += dp[i - j];
      dp[i] %= MOD;
    }
  }
  cout << dp[K] << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}