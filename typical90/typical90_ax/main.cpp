#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const ll MOD = 1e9 + 7;

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

void Main() {
  ll N, L;
  cin >> N >> L;

  int num = N / L;

  ll ans = 1;
  for (int i = 1; i <= num; i++) {
    ll tmp = 1;
    for (int j = 0; j < i; j++) {
      tmp *= (N - (L * i) + i - j);
      tmp %= MOD;
      tmp *= modinv(1 + j, MOD);
      tmp %= MOD;
    }
    ans += tmp;
    ans %= MOD;
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