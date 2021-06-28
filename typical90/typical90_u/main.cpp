#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int N, M;
vector<int> A, B;
vector<vector<int>> edges, r_edges;
vector<bool> used;
vector<int> nodes;
ll cnt = 0;

void dfs(int i) {
  used[i] = true;
  for (int to: edges[i]) {
    if (!used[to]) dfs(to);
  }
  nodes.push_back(i);
}

void dfs_(int i) {
  used[i] = true;
  cnt++;
  for (int to: r_edges[i]) {
    if (!used[to]) dfs_(to);
  }
}

void Main() {
  cin >> N >> M;

  A = vector<int>(M);
  B = vector<int>(M);
  edges = vector<vector<int>>(N + 1);
  r_edges = vector<vector<int>>(N + 1);
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i];
    edges[A[i]].push_back(B[i]);
    r_edges[B[i]].push_back(A[i]);
  }

  used = vector<bool>(N + 1, false);
  for (int i = 1; i <= N; i++) {
    if (!used[i]) dfs(i);
  }

  ll ans = 0;
  reverse(nodes.begin(), nodes.end());
  for (int i = 1; i <= N; i++) used[i] = false;
  for (int i : nodes) {
    if (used[i]) continue;
    cnt = 0;
    dfs_(i);
    ans += cnt * (cnt - 1) / 2;
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