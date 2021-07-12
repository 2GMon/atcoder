#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const int INF = 1000000000;
int N, Q;
vector<vector<int>> G;

vector<int> dist;

void Main() {
  cin >> N >> Q;
  G.resize(N + 1);

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dist.resize(N + 1);
  for (int i = 1; i <= N; i++) {
    dist[i] = INF;
  }
  dist[1] = 0;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int pos = q.front(); q.pop();

    for (int nxt : G[pos]) {
      if (dist[nxt] == INF) {
        q.push(nxt);
        dist[nxt] = dist[pos] + 1;;
      }
    }
  }

  for (int i = 0; i < Q; i++) {
    int c, d;
    cin >> c >> d;
    if (dist[c] % 2 == dist[d] % 2) cout << "Town" << endl;
    else cout << "Road" << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}