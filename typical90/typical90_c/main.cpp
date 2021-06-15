#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const int INF = 1000000000;
vector<vector<int>> edges;
vector<int> d;

void bfs(int n) {
  d[n] = 0;

  queue<int> q;
  q.push(n);

  while(!q.empty()) {
    int from = q.front(); q.pop();
    for (int to: edges[from]) {
      if (d[to] == INF) {
        d[to] = d[from] + 1;
        q.push(to);
      }
    }
  }
}

void Main() {
  int N;
  cin >> N;

  edges = vector<vector<int>>(N, vector<int>());
  rep(i, N - 1) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }

  d = vector<int>(N, INF);
  bfs(0);
  int longest = 0, longest_node = 0;
  rep(i, N) {
    if (d[i] > longest) {
      longest = d[i];
      longest_node = i;
    }
  }

  d = vector<int>(N, INF);
  bfs(longest_node);
  int ans = 0;
  rep(i, N) {
    ans = max(ans, d[i]);
  }

  cout << ans + 1 << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}