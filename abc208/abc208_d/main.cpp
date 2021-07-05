#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

typedef struct {
  int to;
  int cost;
} edge;

const ll INF = 1e18;
ll d[401][401];

void Main() {
  int N, M;
  cin >> N >> M;


  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == j) d[i][j] = 0;
      else d[i][j] = INF;
    }
  }

  for (int i = 0; i < M; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    d[A][B] = C;
  }

  ll ans = 0;
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        if (d[i][j] != INF) ans += d[i][j];
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