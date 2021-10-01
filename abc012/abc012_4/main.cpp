#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const ll INF = 1e17;

void Main() {
  int N, M;
  cin >> N >> M;

  vector<vector<ll>> d(N, vector<ll>(N, INF));
  for (int i = 0; i < N; i++) d[i][i] = 0;
  for (int i = 0; i < M; i++) {
    int a, b, t;
    cin >> a >> b >> t;
    d[a - 1][b - 1] = t;
    d[b - 1][a - 1] = t;
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  ll ans = INF;
  for (int i = 0; i < N; i++) {
    ll tmp = 0;
    for (int j = 0; j < N; j++) {
      tmp = max(tmp, d[i][j]);
    }
    ans = min(ans, tmp);
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