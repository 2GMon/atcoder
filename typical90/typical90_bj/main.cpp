#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

struct edge {
  int to;
  int item;
};

void Main() {
  int N;
  cin >> N;
  vector<int> A(N + 1), B(N + 1);
  vector<vector<int>> G(N + 1);
  vector<bool> done(N + 1);
  queue<int> q;
  for (int i = 1; i <= N; i++) {
    cin >> A[i] >> B[i];
    G[A[i]].push_back(i);
    G[B[i]].push_back(i);
    if (A[i] == i || B[i] == i) {
      done[i] = true;
      q.push(i);
    }
  }

  vector<int> ans;
  while (!q.empty()) {
    int op = q.front(); q.pop();
    ans.push_back(op);

    for (auto next : G[op]) {
      if (done[next]) continue;
      done[next] = true;
      q.push(next);
    }
  }

  if (ans.size() != N) cout << -1 << endl;
  else {
    reverse(ans.begin(), ans.end());
    for (auto o : ans) {
      cout << o << endl;
    }
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}