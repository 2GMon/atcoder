#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, Q;
  cin >> N >> Q;

  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  vector<ll> K(Q);
  rep(i, Q) cin >> K[i];

  sort(A.begin(), A.end());
  vector<ll> num(N);
  num[0] = max(A[0] - 1, (ll)0);
  for (int i = 1; i < N; i++) {
    num[i] = max(num[i - 1] + (A[i] - A[i - 1] - 1), (ll)0);
  }

  for (auto k: K) {
    int lb = -1, ub = N;
    while (ub - lb > 1) {
      int c = (ub + lb) / 2;
      if (num[c] >= k) ub = c;
      else lb = c;
    }
    cout << A[lb] + (k - num[lb]) << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}