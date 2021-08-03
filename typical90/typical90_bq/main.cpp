#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const ll MOD = 1e9 + 7;

ll modpow(ll a, ll b, ll m) {
    ll ans = 1;
    while (b != 0) {
        if (b % 2 == 1)
        {
            ans = ans*a % m;
        }
        a = a*a % m;
        b /= 2;
    }
    return ans;
}

void Main() {
  ll N;
  int K;
  cin >> N >> K;

  if (K == 1) {
    if (N == 1) cout << 1 << endl;
    else cout << 0 << endl;
  } else if (N == 1) {
    cout << K % MOD << endl;
  } else if (N == 2) {
    cout << K * (K - 1) % MOD << endl;
  } else {
    cout << (ll) K * (K - 1) % MOD * modpow(K - 2, N - 2, MOD) % MOD << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}