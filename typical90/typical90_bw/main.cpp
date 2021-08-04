#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  ll N;
  cin >> N;

  map<int, int> p;
  int i = 2;
  for (ll i = 2; i * i <= N; i++) {
    if (N % i != 0) continue;
    ll tmp = 0;
    while (N %i == 0) {
      tmp++;
      N /= i;
    }
    p[i] = tmp;
  }
  if (N != 1) p[N]++;

  ll count = 0;
  for (auto tmp : p) {
    count += tmp.second;
  }

  ll ans = 0;
  while (count > 1) {
    ans++;
    if (count % 2 == 1) count = count / 2 + 1;
    else count = count / 2;
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