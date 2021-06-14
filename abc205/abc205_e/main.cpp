#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

ll MOD = 1e9 + 7;
const int MAX = 3000000;
ll fac[MAX], finv[MAX], inv[MAX];

void modcombinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i ) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

ll modcomb(ll n, ll k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void Main() {
  ll N, M, K;
  cin >> N >> M >> K;

  if (N > M + K) {
    cout << 0 << endl;
    return;
  }

  modcombinit();
  ll ans = modcomb(N + M, M);
  ans -= modcomb(M + N, N - K - 1);
  if (ans < 0) ans = MOD + ans;
  cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}