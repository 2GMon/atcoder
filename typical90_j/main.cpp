#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  cin >> N;

  vector<int> C(N + 1), P(N + 1);
  rep(i, N) cin >> C[i + 1] >> P[i + 1];

  vector<ll> sum1(N + 1, 0), sum2(N + 1, 0);
  rep(i, N) {
    if (C[i + 1] == 1) {
      sum1[i + 1] = sum1[i] + P[i + 1];
      sum2[i + 1] = sum2[i];
    } else {
      sum2[i + 1] = sum2[i] + P[i + 1];
      sum1[i + 1] = sum1[i];
    }
  }

  int Q;
  cin >> Q;
  rep(i, Q) {
    int L, R;
    cin >> L >> R;
    cout << sum1[R] - sum1[L - 1] << " " << sum2[R] - sum2[L - 1] << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}