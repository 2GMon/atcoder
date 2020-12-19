#include"bits/stdc++.h"
using namespace std;

vector<int> visited;
vector<vector<int>> edge;

bool dfs(int n, int before) {
  if (visited[n] == 1) return false;

  visited[n] = 1;
  for (auto to: edge[n]) {
    if (to == before) continue;
    if (visited[to] == 1) return false;
    if (!dfs(to, n)) return false;
  }
  return true;
}

void Main() {
  int N, M;
  cin >> N >> M;

  visited.resize(N);
  for (int i = 0; i < N; i++) {
    visited[i] = 0;
  }
  edge.resize(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (visited[i] == 1) continue;
    if (dfs(i, -1)) {
      ans++;
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