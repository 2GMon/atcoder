#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, Q;
  cin >> N >> Q;

  vector<ll> x(N), y(N);
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }
  ll max_X = numeric_limits<ll>().min(), min_X = numeric_limits<ll>().max();
  ll max_Y = numeric_limits<ll>().min(), min_Y = numeric_limits<ll>().max();
  vector<ll> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    X[i] = x[i] - y[i];
    Y[i] = x[i] + y[i];
    max_X = max(max_X, X[i]); max_Y = max(max_Y, Y[i]);
    min_X = min(min_X, X[i]); min_Y = min(min_Y, Y[i]);
  }

  for (int i = 0; i < Q; i++) {
    ll ans = 0;
    int q;
    cin >> q;
    q--;
    ans = max(ans, abs(X[q] - max_X));
    ans = max(ans, abs(X[q] - min_X));
    ans = max(ans, abs(Y[q] - max_Y));
    ans = max(ans, abs(Y[q] - min_Y));
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