#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

template <typename T>
class RangeMaximumQuery {
  const T MINF = numeric_limits<T>::min();
  int n; // 葉の数
  vector<T> seg;

public:
  void init(int sz) {
    int x = 1;
    while (x < sz) {
      x *= 2;
    }
    n = x;
    seg = vector<T>(n * 2, MINF);
  }

  void update(int i, T x) {
    i = n - 1 + i;
    seg[i] = x;

    while (i > 0) {
      i = (i - 1) / 2;
      seg[i] = max(seg[i * 2 + 1], seg[i * 2 + 2]);
    }
  }

  // [a, b)の最小値
  // k = 現在見ているノード, l = 見ているノードがカバーする葉の一番左, r = 見ているノードがカバーする葉の一番右 + 1
  T query(int a, int b, int k = -1, int l = -1, int r = -1) {
    if (k == -1) k = 0;
    if (l == -1) l = 0;
    if (r == -1) r = n;
    if (r <= a || b <= l) { // [l, r)が[a, b)の外にある
      return MINF;
    } else if (a <= l && r <= b) { // [l, r)が[a, b)に完全に含まれる
      return seg[k];
    } else { // [l, r)が[a, b)に一部含まれる
      T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

      return max(vl, vr);
    }
  }
};

void Main() {
  int W, N;
  cin >> W >> N;

  vector<int> L(N + 1), R(N + 1);
  vector<ll> V(N + 1);
  for (int i = 1; i <= N; i++) cin >> L[i] >> R[i] >> V[i];

  vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, numeric_limits<ll>::min())); // dp[i][j] : i番目までの料理を選んで、香辛料をj消費したときの最大価値
  dp[0][0] = 0;

  RangeMaximumQuery<ll> seg;
  seg.init(W + 1);
  seg.update(0, 0);

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= W; j++) dp[i][j] = dp[i - 1][j];

    for (int j = 0; j <= W; j++) {
      int l = max(j - R[i], 0), r = max(j - L[i] + 1, 0);
      if (l == r) continue;
      ll tmp = seg.query(l, r);
      if (tmp != numeric_limits<ll>::min()) dp[i][j] = max(dp[i][j], tmp + V[i]);
    }
    for (int j = 0; j <= W; j++) seg.update(j, dp[i][j]);
  }

  ll ans = dp[N][W];
  if (ans == numeric_limits<ll>::min()) cout << -1 << endl;
  else cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}