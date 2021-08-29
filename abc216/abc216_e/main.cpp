#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, K;
  cin >> N >> K;

  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A.rbegin(), A.rend());

  ll ans = 0;
  for (int i = 0; i < N && K > 0; i++) {
    ll a = A[i], b = A[i + 1];
    while (a > b && K > 0) {
      if ((i + 1) <= K) {
        ans += a * (i + 1);
        K -= (i + 1);
      } else {
        ans += a * K;
        K -= K;
      }
      a--;
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