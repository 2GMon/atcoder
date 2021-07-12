#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const ll MOD = 1e9 + 7;

void Main() {
  int N;
  cin >> N;
  vector<int> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }
  sort(C.begin(), C.end());

  ll ans = 1;
  for (int i = 0; i < N; i++) {
    ans *= (C[i] - i);
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