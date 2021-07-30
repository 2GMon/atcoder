#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, M;
  cin >> N >> M;
  vector<double> d(N + 1 + M, -1);
  d[1] = 0;

  vector<vector<int>> G(N + 1 + M);
  for (int i = 0; i < M; i++) {
    int K;
    cin >> K;
    for (int j = 0; j < K; j++) {
      int R;
      cin >> R;
      G[N + 1 + i].push_back(R);
      G[R].push_back(N + 1 + i);
    }
  }

  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int pos = q.front(); q.pop();
    for (int nxt : G[pos]) {
      if(d[nxt] == -1) {
        d[nxt] = d[pos] + 0.5;
        q.push(nxt);
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    cout << int(d[i]) << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}