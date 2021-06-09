#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  cin >> N;

  map<int, int> cnt;
  for (int i = 2; i <= N; i++) {
    int tmp = i;
    for (int j = 2; j * j <= i; j++) {
      while (tmp % j == 0) {
        cnt[j]++;
        tmp /= j;
      }
    }
    if (tmp != 1) cnt[tmp]++;
  }

  ll ans = 1;
  ll mod = 1e9 + 7;
  for (auto c: cnt) {
    ans *= (c.second + 1);
    ans %= mod;
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