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