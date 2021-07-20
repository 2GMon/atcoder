#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const ll MOD = 1e9 + 7;

void Main() {
  int N;
  cin >> N;
  vector<vector<int>> A(N);
  for (int i = 0; i < N; i++) {
    int a;
    for (int j = 0; j < 6; j++) {
      cin >> a;
      A[i].push_back(a);
    }
  }

  ll ans = 1;
  for (int i = 0; i < N; i++) {
    ll tmp = 0;
    for (int d : A[i]) tmp += d;
    ans *= tmp;
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