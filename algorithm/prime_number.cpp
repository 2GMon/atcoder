#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

void Sieve(ll x) {
  vector<bool> flags(x, true);
  flags[0] = false;
  flags[1] = false;

  for (ll p = 2; p <= x; p++) {
    if (!flags[p]) continue;
    for (ll mult = p * p; mult < x; mult += p) flags[mult] = false;
  }
}

void prime_factorization(ll N) {
  map<int, int> p;
  for (ll i = 2; i * i <= N; i++) {
    if (N % i != 0)
      continue;
    ll tmp = 0;
    while (N % i == 0) {
      tmp++;
      N /= i;
    }
    p[i] = tmp;
  }
  if (N != 1) p[N]++;
}