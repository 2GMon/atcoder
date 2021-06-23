#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

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