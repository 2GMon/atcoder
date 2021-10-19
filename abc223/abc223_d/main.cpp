#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

void Main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) cin >> A[i] >> B[i];

  vector<vector<int>> G(N + 1);
  vector<int> input(N + 1, 0);
  for (int i = 0; i < M; i++) {
    G[A[i]].push_back(B[i]);
    input[B[i]]++;
  }

  priority_queue<int, vector<int>, greater<int>> q;
  for (int i = 1; i <= N; i++) {
    if (input[i] == 0) q.push(i);
  }

  vector<int> ans;
  while (!q.empty()) {
    int i = q.top(); q.pop();
    ans.push_back(i);
    for (int j: G[i]) {
      input[j]--;
      if (input[j] == 0) {
        q.push(j);
      }
    }
  }

  if (ans.size() != N) cout << -1 << endl;
  else {
    for (int i = 0; i < N; i++) cout << ans[i] << (i + 1 == N ? '\n' : ' ');
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}