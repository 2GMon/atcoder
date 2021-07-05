#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, K;
  cin >> N >> K;

  vector<int> cnt(N + 1, 0);
  for (int i = 2; i <= N; i++) {
    if (cnt[i] >= 1) continue;
    for (int j = i; j <= N; j += i) cnt[j] += 1;
  }

  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    if (cnt[i] >= K) ans++;
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