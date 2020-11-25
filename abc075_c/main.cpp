#include"bits/stdc++.h"
using namespace std;

int N, M;
vector<bool> visited;
int edge[50][50];
vector<pair<int, int>> edges;

void dfs(int n) {
  visited[n] = true;

  for (int to = 0; to < N; to++) {
    if (edge[n][to] > 0 && visited[to] == false)
      dfs(to);
  }
}

void Main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      edge[i][j] = 0;
    }
  }

  edges.resize(M);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    edge[a][b] += 1;
    edge[b][a] += 1;
    edges[i] = pair<int, int>(a, b);
  }

  int ans = 0;
  for (int i = 0; i < M; i++) {
    auto e = edges[i];
    edge[e.first][e.second]--;
    edge[e.second][e.first]--;

    visited = vector<bool>(N);
    for (int i = 0; i < N; i++) {
      visited[i] = false;
    }

    dfs(0);

    bool renketsu = true;
    for (auto v: visited) {
      if (!v) renketsu = false;
    }
    if (!renketsu) ans++;

    edge[e.first][e.second]++;
    edge[e.second][e.first]++;
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