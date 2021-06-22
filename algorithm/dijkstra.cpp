#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

int N;
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