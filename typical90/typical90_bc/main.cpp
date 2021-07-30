#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)


void Main() {
  int N, P, Q;
  cin >> N >> P >> Q;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  ll ans = 0;
  for (int a = 0; a < N; a++) {
    for (int b = a + 1; b < N; b++) {
      for (int c = b + 1; c < N; c++) {
        for (int d = c + 1; d < N; d++) {
          for (int e = d + 1; e < N; e++) {
            ll seki = A[a];
            seki *= A[b];
            seki %= P;
            seki *= A[c];
            seki %= P;
            seki *= A[d];
            seki %= P;
            seki *= A[e];
            if (seki % P == Q) ans++;
          }
        }
      }
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