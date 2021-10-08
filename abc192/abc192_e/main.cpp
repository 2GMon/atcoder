#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

typedef struct {
  int to;
  int T;
  int K;
} edge;

void Main() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;

  int A, B, T, K;
  vector<vector<edge>> edges(N + 1);
  for (int i = 0; i < M; i++) {
    cin >> A >> B >> T >> K;
    edges[A].push_back({ B, T, K });
    edges[B].push_back({ A, T, K });
  }

  vector<ll> dist(N + 1, 1ll << 60);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
  dist[X] = 0;
  Q.push(make_pair(0, X));
  while (!Q.empty()) {
    auto q = Q.top(); Q.pop();
    int pos = q.second;
    ll now = q.first;

    if (pos == Y) break;
    
    for (edge e: edges[pos]) {
      int to = e.to;
      int T = e.T;
      int K = e.K;
      ll nxtTime = (now + K - 1) / K * K + T;
      if (dist[to] > nxtTime) {
        dist[to] = nxtTime;
        Q.push(make_pair(dist[to], to));
      }
    }
  }

  if (dist[Y] == 1ll << 60) cout << -1 << endl;
  else cout << dist[Y] << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}