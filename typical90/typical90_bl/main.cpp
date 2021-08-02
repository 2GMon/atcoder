#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, Q;
  cin >> N >> Q;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<ll> E(N);
  ll ans = 0;
  for (int i = 1; i < N; i++) {
    E[i] = A[i] - A[i - 1];
    ans += abs(E[i]);
  }

  for (int i = 0; i < Q; i++) {
    int L, R, V;
    cin >> L >> R >> V;
    L--; R--;
    if (L > 0) {
      ans -= abs(E[L]);
      E[L] += V;
      ans += abs(E[L]);
    }
    if (R < N - 1) {
      ans -= abs(E[R + 1]);
      E[R + 1] -= V;
      ans += abs(E[R + 1]);
    }
    cout << ans << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}