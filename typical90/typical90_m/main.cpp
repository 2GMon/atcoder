#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int N, M;
ll dist[100009];
vector<pair<int, ll>> edges[100009];

void dijkstra(int from)
{
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
  for (int i = 1; i <= N; i++) dist[i] = (1ll << 60);
  dist[from] = 0;
  Q.push(make_pair(0, from));

  while (!Q.empty()) {
    int pos = Q.top().second;
    Q.pop();
    for (int i = 0; i < edges[pos].size(); i++) {
      int to = edges[pos][i].first;
      long long cost = edges[pos][i].second;
      if (dist[to] > dist[pos] + cost) {
        dist[to] = dist[pos] + cost;
        Q.push(make_pair(dist[to], to));
      }
    }
  }
}

void Main() {
  cin >> N >> M;
  rep(i, M) {
    int A, B, C;
    cin >> A >> B >> C;

    edges[A].push_back(pair<int, ll>(B, C));
    edges[B].push_back(pair<int, ll>(A, C));
  }

  ll dist_from1[100009];
  ll dist_fromN[100009];

  dijkstra(1);
  for (int i = 1; i <= N; i++) dist_from1[i] = dist[i];

  dijkstra(N);
  for (int i = 1; i <= N; i++) dist_fromN[i] = dist[i];

  for (int i = 1; i <= N; i++) {
    cout << dist_from1[i] + dist_fromN[i] << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}