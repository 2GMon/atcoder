#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  ll K;
  cin >> K;

  vector<ll> y;
  for (ll i = 1; i * i <= K; i++) {
    if (K % i != 0) continue;
    y.push_back(i);
    if (i * i != K) y.push_back(K / i);
  }
  sort(y.begin(), y.end());

  ll ans = 0;
  for (int i = 0; i < y.size(); i++) {
    for (int j = i; j < y.size(); j++) {
      ll a = y[i], b = y[j];
      if (K / a < b) continue;
      if (K % (a * b) != 0) continue;
      ll c = K / (a * b);
      if (c < b) continue;
      ans++;
    }
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